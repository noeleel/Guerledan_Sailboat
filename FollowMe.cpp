// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include "FollowMe.h"

THREAD_PROC_RETURN_VALUE FollowMeThread(void* pParam)
{
	UNREFERENCED_PARAMETER(pParam);

	FILE* logfollowmefile = NULL;
	char logfollowmefilename[MAX_BUF_LEN];

	int i = 0;
	double distance = 0, step = 0, norm_ba = 0;

	CHRONO chrono;

	EnterCriticalSection(&strtimeCS);
	sprintf(logfollowmefilename, LOG_FOLDER"logfollowme_%.64s.csv", strtimeex_fns());
	LeaveCriticalSection(&strtimeCS);
	logfollowmefile = fopen(logfollowmefilename, "w");
	if (logfollowmefile == NULL)
	{
		printf("Unable to create log file.\n");
		if (!bExit) bExit = TRUE; // Unexpected program exit...
		return 0;
	}

	fprintf(logfollowmefile,
		"%% Time (in s); xtarget; ytarget; ztarget; distance (in m); wx[last]; wy[last]; wz[last]; step (in m);\n"
		); 
	fflush(logfollowmefile);

	StartChrono(&chrono);

	for (;;)
	{
		mSleep(100);

		if (bExit) break;
		if (!bFollowMeTrackingControl) continue;

		EnterCriticalSection(&FollowMeCS);

		EnterCriticalSection(&StateVariablesCS);

		if (wx_vector.size() <= 0)
		{
			i = 0;
			wx_vector.push_back(Center(xhat)); wy_vector.push_back(Center(yhat)); wz_vector.push_back(Center(zhat));
			if ((xtarget_followme != 0)&&(ytarget_followme != 0))
			{ 			
				wx_vector.push_back(xtarget_followme); wy_vector.push_back(ytarget_followme); wz_vector.push_back(ztarget_followme);
			}
			else
			{ 			
				wx_vector.push_back(Center(xhat)); wy_vector.push_back(Center(yhat)); wz_vector.push_back(Center(zhat));
			}
			wxa = wx_vector[i]; wya = wy_vector[i]; wza = wz_vector[i]; wxb = wx_vector[i+1]; wyb = wy_vector[i+1]; wzb = wz_vector[i+1];
			if (bDepth_followme) norm_ba = sqrt(sqr(wxa-wxb)+sqr(wya-wyb)+sqr(wza-wzb)); else norm_ba = sqrt(sqr(wxa-wxb)+sqr(wya-wyb));
		}
		if (bDepth_followme)
		{
			distance = sqrt(sqr(xtarget_followme-Center(xhat))+sqr(ytarget_followme-Center(yhat))+sqr(ztarget_followme-Center(zhat)));
			step = sqrt(sqr(xtarget_followme-wx_vector[wx_vector.size()-1])+sqr(ytarget_followme-wy_vector[wy_vector.size()-1])+sqr(ztarget_followme-wz_vector[wz_vector.size()-1]));
		}
		else
		{
			distance = sqrt(sqr(xtarget_followme-Center(xhat))+sqr(ytarget_followme-Center(yhat)));
			step = sqrt(sqr(xtarget_followme-wx_vector[wx_vector.size()-1])+sqr(ytarget_followme-wy_vector[wy_vector.size()-1]));
		}
		// Create new waypoints regularly from the target trajectory. 
		if (step > spaceperiod_followme)
		{
			wx_vector.push_back(xtarget_followme); wy_vector.push_back(ytarget_followme); wz_vector.push_back(ztarget_followme); 
		}
		if (bDepth_followme)
		{
			if ((forbidradius_followme > 0)&&(sqrt(sqr(xtarget_followme-forbidx_followme)+sqr(ytarget_followme-forbidy_followme)+sqr(ztarget_followme-forbidz_followme)) < forbidradius_followme))
			{
				// Clear all the target trajectory, but in practice this does not really prevent the follower to go through the forbidden area...
				wxa = 0; wya = 0; wza = 0; wxb = 0; wyb = 0; wzb = 0;
				wx_vector.clear(); wy_vector.clear(); wz_vector.clear();
			}
		}
		else
		{
			if ((forbidradius_followme > 0)&&(sqrt(sqr(xtarget_followme-forbidx_followme)+sqr(ytarget_followme-forbidy_followme)) < forbidradius_followme))
			{
				// Clear all the target trajectory, but in practice this does not really prevent the follower to go through the forbidden area...
				wxa = 0; wya = 0; wza = 0; wxb = 0; wyb = 0; wzb = 0;
				wx_vector.clear(); wy_vector.clear(); wz_vector.clear();
			}
		}

		LeaveCriticalSection(&StateVariablesCS);

		if (wx_vector.size() > 0)
		{
			fprintf(logfollowmefile, "%f;%f;%f;%f;%f;%f;%f;%f;%f;\n", GetTimeElapsedChronoQuick(&chrono), xtarget_followme, ytarget_followme, ztarget_followme, distance, wx_vector[wx_vector.size()-1], wy_vector[wy_vector.size()-1], wz_vector[wz_vector.size()-1], step);
			fflush(logfollowmefile);
		}

		if (bFollowMeTrackingControl)
		{
			EnterCriticalSection(&StateVariablesCS);
			if (distance > dmax_followme)
			{
				u = umax_followme;
				bLineFollowingControl = TRUE;
				bWaypointControl = FALSE;
				bHeadingControl = TRUE;
				if (bDepth_followme)
				{
					bDepthControl = TRUE;
					bAltitudeAGLControl = FALSE;
					wz = (norm_ba != 0)? (1-distance/norm_ba)*(wzb-wza)+wza: wzb;
					wz = min(max(wz, wzb), wza);
				}
				// Check if the destination waypoint of the line was reached.
				if ((wxb-wxa)*(Center(xhat)-wxb)+(wyb-wya)*(Center(yhat)-wyb) >= 0)
				{
					if ((i >= 0)&&(i < (int)wx_vector.size()-2))
					{
						i++;
						wxa = wx_vector[i]; wya = wy_vector[i]; wza = wz_vector[i]; wxb = wx_vector[i+1]; wyb = wy_vector[i+1]; wzb = wz_vector[i+1];
						if (bDepth_followme) norm_ba = sqrt(sqr(wxa-wxb)+sqr(wya-wyb)+sqr(wza-wzb)); else norm_ba = sqrt(sqr(wxa-wxb)+sqr(wya-wyb));
					}
					else
					{
						//printf("Warning : No more waypoints to follow.\n");
						bLineFollowingControl = FALSE;
						bWaypointControl = FALSE;
						bHeadingControl = FALSE;
						u = uidle_followme;
						uw = 0;
						// Should never stop the depth control...?
					}
				}
			}
			else if (distance > dmin_followme)
			{
				u = umin_followme;
				bLineFollowingControl = TRUE;
				bWaypointControl = FALSE;
				bHeadingControl = TRUE;
				if (bDepth_followme)
				{
					bDepthControl = TRUE;
					bAltitudeAGLControl = FALSE;
					wz = (norm_ba != 0)? (1-distance/norm_ba)*(wzb-wza)+wza: wzb;
					wz = min(max(wz, wzb), wza);
				}
				// Check if the destination waypoint of the line was reached.
				if ((wxb-wxa)*(Center(xhat)-wxb)+(wyb-wya)*(Center(yhat)-wyb) >= 0)
				{
					if ((i >= 0)&&(i < (int)wx_vector.size()-2))
					{
						i++;
						wxa = wx_vector[i]; wya = wy_vector[i]; wza = wz_vector[i]; wxb = wx_vector[i+1]; wyb = wy_vector[i+1]; wzb = wz_vector[i+1];
						if (bDepth_followme) norm_ba = sqrt(sqr(wxa-wxb)+sqr(wya-wyb)+sqr(wza-wzb)); else norm_ba = sqrt(sqr(wxa-wxb)+sqr(wya-wyb));
					}
					else
					{
						//printf("Warning : No more waypoints to follow.\n");
						bLineFollowingControl = FALSE;
						bWaypointControl = FALSE;
						bHeadingControl = FALSE;
						u = uidle_followme;
						uw = 0;
						// Should never stop the depth control...?
					}
				}
			}
			else
			{
				bLineFollowingControl = FALSE;
				bWaypointControl = FALSE;
				bHeadingControl = FALSE;
				u = uidle_followme;
				uw = 0;
				// Should never stop the depth control...?
			}
			LeaveCriticalSection(&StateVariablesCS);
		}

		LeaveCriticalSection(&FollowMeCS);

		if (bExit) break;
	}

	StopChronoQuick(&chrono);

	fclose(logfollowmefile);

	if (!bExit) bExit = TRUE; // Unexpected program exit...

	return 0;
}
