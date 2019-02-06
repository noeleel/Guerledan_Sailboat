// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include "Ball.h"

// Need to be undefined at the end of the file...
// min and max might cause incompatibilities with GCC...
#ifndef _MSC_VER
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif // !max
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif // !min
#endif // !_MSC_VER

THREAD_PROC_RETURN_VALUE BallThread(void* pParam)
{
	UNREFERENCED_PARAMETER(pParam);

	// Missing error checking...

	int flag_cam = 0;
	int nbTotalPixels = videoimgwidth*videoimgheight;
	// Used to detect the bounds of the detected object.
	int* nbSelectedPixelsj = (int*)calloc(videoimgwidth, sizeof(int)); // Number of selected pixels for the column j.
	int* nbSelectedPixelsi = (int*)calloc(videoimgheight, sizeof(int)); // Number of selected pixels for the line i.
	// Number of selected pixels in the picture.
	int nbSelectedPixels = 0;
	// Number of selected pixels in the picture for the light.
	int nbSelectedPixelsLight_ball = 0;
	// Image indicating selected pixels.
	IplImage* SelectedPixelsImage = cvCreateImage(cvSize(videoimgwidth, videoimgheight), IPL_DEPTH_8U, 3);
	// Estimation of the center of the object in the picture.
	double obji = 0, objj = 0;
	// Estimation of the radius of the object (in pixels).
	int objRadius = 0;
	// Estimation of the bounding rectangle of the object (in pixels).
	double objBoundWidth = 0, objBoundHeight = 0;
	// Estimation of the orientation of the object (in rad).
	double objAngle = 0;
	BOOL bobjAngleValid = FALSE;
	// Estimated d to the object (in m).
	double objDistance = 0;
	// Estimated bearing to the object (in rad).
	double objBearing = 0;
	// Estimated elevation to the object (in rad).
	double objElevation = 0;
	// Real radius of the object (in m).
	//double objRealRadius = 0.15;
	// Parameters of the camera.
	double pixelAngleSize = M_PI*HorizontalBeam/(180.0*videoimgwidth); // Angular size of a pixel (in rad).
	// We only consider objects that covers that ratio of the picture (refers to the min size of the object on the picture).
	//double objPixRatio = 1.0/256.0;
	// We only consider objects that have an estimated radius (in pixels) greater than this one.
	int objMinRadius = 0;
	// We consider that we are on the detected object when the number of selected pixels for the 
	// line i or column j (in pixels) is greater than this one.
	int objMinnbSelectedPixelsij = 0;


	// Accuracy of the orientation of the object (in rad).
	double thetastep = M_PI/32.0;
	// Accuracy of the covering of the object for the computation of its orientation (w.r.t. object radius).
	double dstepobjRadiusratio = 1.0/10.0;
	// When this ratio of objRadius is outside the picture, the estimated orientation will not be considered as valid.
	double objRadiusouterrratio = 0.25;
	// When abs(1-objBounds/objRadius) < boundsradiuserrratio, the detected object has probably a square or circle 
	// shape and the estimated orientation will not be considered as valid.
	double boundsradiuserrratio = 0.25;	

	CHRONO chrono_mindetectionduration;

	char strtime_pic[MAX_BUF_LEN];
	char snapfilename[MAX_BUF_LEN];
	char picsnapfilename[MAX_BUF_LEN];
	char dtcfilename[MAX_BUF_LEN];
	char kmlfilename[MAX_BUF_LEN];
	FILE* kmlsnapfile = NULL;
	int pic_counter = 0;
	CHRONO chrono;

	// Missing error checking...
	IplImage* image = cvCreateImage(cvSize(videoimgwidth, videoimgheight), IPL_DEPTH_8U, 3);
	IplImage* overlayimage = cvCreateImage(cvSize(videoimgwidth, videoimgheight), IPL_DEPTH_8U, 3);
	
	cvSet(overlayimage, CV_RGB(0, 0, 0), NULL);
	int i = 0, j = 0, index = 0;

	CvFont font;
	char szText[256];
	cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 1.0f, 1.0f);

	EnterCriticalSection(&strtimeCS);
	sprintf(logballtaskfilename, LOG_FOLDER"logballtask_%.64s.csv", strtime_fns());
	LeaveCriticalSection(&strtimeCS);
	logballtaskfile = fopen(logballtaskfilename, "w");
	if (logballtaskfile == NULL)
	{
		printf("Unable to create log file.\n");
		if (!bExit) bExit = TRUE; // Unexpected program exit...
		return 0;
	}

	fprintf(logballtaskfile, 
		"%% Time (in s); Distance to the ball (in m); Bearing to the ball (in rad); Elevation to the ball (in rad); "
		"Light status (1 : on, 0 : off); "
		"x ball position (in m); y ball position (in m); z ball position (in m); "
		"Latitude of the ball (in decimal degrees); Longitude of the ball (in decimal degrees); Altitude of the ball (in m);\n"
		); 
	fflush(logballtaskfile);

	StartChrono(&chrono);
	StartChrono(&chrono_mindetectionduration);

	for (;;)
	{
		mSleep(captureperiod);

		if (bExit) break;
		if ((!bBallDetection)&&(!bBallTrackingControl)) continue;

		cvSet(overlayimage, CV_RGB(0, 0, 0), NULL);

		
		EnterCriticalSection(&BallCS);
#pragma region Object detection
		// Initializations...
		memset(nbSelectedPixelsj, 0, videoimgwidth*sizeof(int));
		memset(nbSelectedPixelsi, 0, videoimgheight*sizeof(int));
		nbSelectedPixels = 0;
		nbSelectedPixelsLight_ball = 0;
		obji = 0;
		objj = 0;
		objMinRadius = (int)(videoimgwidth*objMinRadiusRatio_ball);
		objMinnbSelectedPixelsij = objMinRadius/2;

		// Get an image from the webcam or video.
		EnterCriticalSection(&imgsCS[videoid_ball]);
		cvCopy(imgs[videoid_ball], image, 0);
		LeaveCriticalSection(&imgsCS[videoid_ball]);

		// Convert image->imageData from char* to unsigned char* to work with color values in 0..255.
		unsigned char* data = reinterpret_cast<unsigned char*>(image->imageData);
		unsigned char* overlaydata = reinterpret_cast<unsigned char*>(overlayimage->imageData);

		// Correction of bad lines on the borders of the video...
		CorrectImageBordersRawBGR(data, videoimgwidth, videoimgheight, 2, 0, 0, 0);
		detect_ball(image, overlayimage, ballFound);

		// Override number Selected Pixels
		if (ballFound) 
		{
			LeaveCriticalSection(&BallCS);
			EnterCriticalSection(&BallOverlayImgCS);
			//overlayimage = &ovlImage.operator IplImage();
			cvCopy(overlayimage, BallOverlayImg, 0);
			LeaveCriticalSection(&BallOverlayImgCS);
			if (bExit) break;
			continue;
		}

		// Compute an estimation of the radius of the detected object. 
		// sqrt() is used to virtually increase the radius because there are always missed selected pixels...
		objRadius = ball_radius;
		objDistance = ball_distance;

#pragma region Actions
			sprintf(szText, "RNG=%.2fm", objDistance);
			cvPutText(overlayimage, szText, cvPoint(10,videoimgheight-20), &font, CV_RGB(255,0,128));

			EnterCriticalSection(&StateVariablesCS);
			x_ball = ball_x;
			y_ball = ball_y;
			z_ball = 0;
			EnvCoordSystem2GPS(lat_env, long_env, alt_env, angle_env, x_ball, y_ball, z_ball, &lat_ball, &long_ball, &alt_ball);
			LeaveCriticalSection(&StateVariablesCS);

			fprintf(logballtaskfile, "%f;%f;%f;%f;%f;%f;%f;%f;\n", 
				GetTimeElapsedChronoQuick(&chrono), objDistance, x_ball, y_ball, z_ball, lat_ball, long_ball, alt_ball
				);
			fflush(logballtaskfile);

			if (bBallDetection)
			{
				// Save a picture showing the detection.
				memset(strtime_pic, 0, sizeof(strtime_pic));
				EnterCriticalSection(&strtimeCS);
				strcpy(strtime_pic, strtime_fns());
				LeaveCriticalSection(&strtimeCS);
				sprintf(snapfilename, "pic_%.64s.jpg", strtime_pic);
				sprintf(picsnapfilename, PIC_FOLDER"pic_%.64s.jpg", strtime_pic);
				if (!cvSaveImage(picsnapfilename, image, 0))
				{
					printf("Error saving a picture file.\n");
				}
				sprintf(dtcfilename, PIC_FOLDER"pic_%.64s.png", strtime_pic);
				if (!cvSaveImage(dtcfilename, overlayimage, 0))
				{
					printf("Error saving a picture file.\n");
				}
				sprintf(kmlfilename, PIC_FOLDER"pic_%.64s.kml", strtime_pic);
				kmlsnapfile = fopen(kmlfilename, "w");
				if (kmlsnapfile != NULL)
				{
					EnterCriticalSection(&StateVariablesCS);
					fprintf(kmlsnapfile, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
					fprintf(kmlsnapfile, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
					fprintf(kmlsnapfile, "<Document>\n<name>pic_%.64s</name>\n", strtime_pic);
					fprintf(kmlsnapfile, "\t<PhotoOverlay>\n\t\t<name>pic_%.64s</name>\n", strtime_pic);
					fprintf(kmlsnapfile, "\t\t<Camera>\n\t\t\t<longitude>%.8f</longitude>\n\t\t\t<latitude>%.8f</latitude>\n\t\t\t<altitude>%.3f</altitude>\n", long_ball, lat_ball, alt_ball);
					fprintf(kmlsnapfile, "\t\t\t<heading>%f</heading>\n\t\t\t<tilt>%f</tilt>\n\t\t\t<roll>%f</roll>\n", (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI, 0.0, 0.0);
					fprintf(kmlsnapfile, "\t\t\t<altitudeMode>relativeToGround</altitudeMode>\n\t\t\t<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n\t\t</Camera>\n");
					fprintf(kmlsnapfile, "\t\t<Style>\n\t\t\t<IconStyle>\n\t\t\t\t<Icon>\n\t\t\t\t\t<href>:/camera_mode.png</href>\n\t\t\t\t</Icon>\n\t\t\t</IconStyle>\n");
					fprintf(kmlsnapfile, "\t\t\t<ListStyle>\n\t\t\t\t<listItemType>check</listItemType>\n\t\t\t\t<ItemIcon>\n\t\t\t\t\t<state>open closed error fetching0 fetching1 fetching2</state>\n");
					fprintf(kmlsnapfile, "\t\t\t\t\t<href>http://maps.google.com/mapfiles/kml/shapes/camera-lv.png</href>\n\t\t\t\t</ItemIcon>\n\t\t\t\t<bgColor>00ffffff</bgColor>\n\t\t\t\t<maxSnippetLines>2</maxSnippetLines>\n");
					fprintf(kmlsnapfile, "\t\t\t</ListStyle>\n\t\t</Style>\n");
					fprintf(kmlsnapfile, "\t\t<Icon>\n\t\t\t<href>%.255s</href>\n\t\t</Icon>\n", snapfilename);
					fprintf(kmlsnapfile, "\t\t<ViewVolume>\n\t\t\t<leftFov>-25</leftFov>\n\t\t\t<rightFov>25</rightFov>\n\t\t\t<bottomFov>-16.25</bottomFov>\n\t\t\t<topFov>16.25</topFov>\n\t\t\t<near>7.92675</near>\n\t\t</ViewVolume>\n");
					fprintf(kmlsnapfile, "\t\t<Point>\n\t\t\t<altitudeMode>relativeToGround</altitudeMode>\n\t\t\t<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n\t\t\t<coordinates>%.8f,%.8f,%.3f</coordinates>\n\t\t</Point>\n", long_ball, lat_ball, alt_ball);
					fprintf(kmlsnapfile, "\t</PhotoOverlay>\n");
					fprintf(kmlsnapfile, "</Document>\n</kml>\n");
					LeaveCriticalSection(&StateVariablesCS);
					fclose(kmlsnapfile);
				}
				else
				{
					printf("Error saving a KML file.\n");
				}

				if (bBrake_ball)
				{
					// Temporary...
					EnterCriticalSection(&StateVariablesCS);
					u = 0;
					bDistanceControl = FALSE;
					bBrakeControl = TRUE;
					LeaveCriticalSection(&StateVariablesCS);
					mSleep(3000);
					EnterCriticalSection(&StateVariablesCS);
					u = 0;
					bBrakeControl = FALSE;
					LeaveCriticalSection(&StateVariablesCS);
				}
				bBallDetection = FALSE;
			}

			if (bBallTrackingControl)
			{
				if (pic_counter > (int)(1000/captureperiod))
				{
					pic_counter = 0;
					// Save a picture showing the detection.
					memset(strtime_pic, 0, sizeof(strtime_pic));
					EnterCriticalSection(&strtimeCS);
					strcpy(strtime_pic, strtime_fns());
					LeaveCriticalSection(&strtimeCS);
					sprintf(snapfilename, "pic_%.64s.jpg", strtime_pic);
					sprintf(picsnapfilename, PIC_FOLDER"pic_%.64s.jpg", strtime_pic);
					if (!cvSaveImage(picsnapfilename, image, 0))
					{
						printf("Error saving a picture file.\n");
					}
					sprintf(dtcfilename, PIC_FOLDER"pic_%.64s.png", strtime_pic);
					if (!cvSaveImage(dtcfilename, overlayimage, 0))
					{
						printf("Error saving a picture file.\n");
					}
					sprintf(kmlfilename, PIC_FOLDER"pic_%.64s.kml", strtime_pic);
					kmlsnapfile = fopen(kmlfilename, "w");
					if (kmlsnapfile != NULL)
					{
						EnterCriticalSection(&StateVariablesCS);
						fprintf(kmlsnapfile, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
						fprintf(kmlsnapfile, "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n");
						fprintf(kmlsnapfile, "<Document>\n<name>pic_%.64s</name>\n", strtime_pic);
						fprintf(kmlsnapfile, "\t<PhotoOverlay>\n\t\t<name>pic_%.64s</name>\n", strtime_pic);
						fprintf(kmlsnapfile, "\t\t<Camera>\n\t\t\t<longitude>%.8f</longitude>\n\t\t\t<latitude>%.8f</latitude>\n\t\t\t<altitude>%.3f</altitude>\n", long_ball, lat_ball, alt_ball);
						fprintf(kmlsnapfile, "\t\t\t<heading>%f</heading>\n\t\t\t<tilt>%f</tilt>\n\t\t\t<roll>%f</roll>\n", (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI, 0.0, 0.0);
						fprintf(kmlsnapfile, "\t\t\t<altitudeMode>relativeToGround</altitudeMode>\n\t\t\t<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n\t\t</Camera>\n");
						fprintf(kmlsnapfile, "\t\t<Style>\n\t\t\t<IconStyle>\n\t\t\t\t<Icon>\n\t\t\t\t\t<href>:/camera_mode.png</href>\n\t\t\t\t</Icon>\n\t\t\t</IconStyle>\n");
						fprintf(kmlsnapfile, "\t\t\t<ListStyle>\n\t\t\t\t<listItemType>check</listItemType>\n\t\t\t\t<ItemIcon>\n\t\t\t\t\t<state>open closed error fetching0 fetching1 fetching2</state>\n");
						fprintf(kmlsnapfile, "\t\t\t\t\t<href>http://maps.google.com/mapfiles/kml/shapes/camera-lv.png</href>\n\t\t\t\t</ItemIcon>\n\t\t\t\t<bgColor>00ffffff</bgColor>\n\t\t\t\t<maxSnippetLines>2</maxSnippetLines>\n");
						fprintf(kmlsnapfile, "\t\t\t</ListStyle>\n\t\t</Style>\n");
						fprintf(kmlsnapfile, "\t\t<Icon>\n\t\t\t<href>%.255s</href>\n\t\t</Icon>\n", snapfilename);
						fprintf(kmlsnapfile, "\t\t<ViewVolume>\n\t\t\t<leftFov>-25</leftFov>\n\t\t\t<rightFov>25</rightFov>\n\t\t\t<bottomFov>-16.25</bottomFov>\n\t\t\t<topFov>16.25</topFov>\n\t\t\t<near>7.92675</near>\n\t\t</ViewVolume>\n");
						fprintf(kmlsnapfile, "\t\t<Point>\n\t\t\t<altitudeMode>relativeToGround</altitudeMode>\n\t\t\t<gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n\t\t\t<coordinates>%.8f,%.8f,%.3f</coordinates>\n\t\t</Point>\n", long_ball, lat_ball, alt_ball);
						fprintf(kmlsnapfile, "\t</PhotoOverlay>\n");
						fprintf(kmlsnapfile, "</Document>\n</kml>\n");
						LeaveCriticalSection(&StateVariablesCS);
						fclose(kmlsnapfile);
					}
					else
					{
						printf("Error saving a KML file.\n");
					}
				}
				else pic_counter++;

				if (bBrake_ball)
				{
					// No need to really brake...
				}
				else
				{
					// Tracking.
					switch (camdir_ball)
					{
					case 0:
						EnterCriticalSection(&StateVariablesCS);
						/*
							objDistance_ball = objDistance;
							wpsi_ball = Center(psihat) + objBearing;
						*/
						dist = objDistance;
						wd = d0_ball;
						wu = u_ball;
						wpsi = Center(psihat)+objBearing;
						bDistanceControl = TRUE;
						bHeadingControl = TRUE;
						LeaveCriticalSection(&StateVariablesCS);
						break;
					case 1:
						EnterCriticalSection(&StateVariablesCS);
						u = u_ball;
						wpsi = Center(psihat)+objBearing+u_ball*(M_PI/4.0)*sign(objDistance-d0_ball, wdradius);
						LeaveCriticalSection(&StateVariablesCS);
						break;
					case -1:
						EnterCriticalSection(&StateVariablesCS);
						u = u_ball;
						wpsi = Center(psihat)+objBearing-u_ball*(M_PI/4.0)*sign(objDistance-d0_ball, wdradius);
						bHeadingControl = TRUE;
						LeaveCriticalSection(&StateVariablesCS);
						break;
					case 2:
						EnterCriticalSection(&StateVariablesCS);
						dist = objDistance*sin(objElevation);
						wd = 0;
						wu = u_ball;
						wpsi = Center(psihat)+objBearing;
						bDistanceControl = TRUE;
						bHeadingControl = TRUE;
						LeaveCriticalSection(&StateVariablesCS);
						break;
					default:
						break;
					}
				}
			}

			if (procid_ball != -1)
			{
				if (bBallTrackingControl)
				{
					// stopballtracking to avoid multiple execute...
					bBallTrackingControl = FALSE;
					bDistanceControl = FALSE;
					//if (bBrake_ball) bBrakeControl = FALSE;
					bHeadingControl = FALSE;
				}
				if (bEcho) printf("execute %d\n", procid_ball);
				ExecuteProcedure(procid_ball);
				bWaiting = FALSE; // To interrupt and force execution of the next commands...
			}
#pragma endregion

		LeaveCriticalSection(&BallCS);

		EnterCriticalSection(&BallOverlayImgCS);
		cvCopy(overlayimage, BallOverlayImg, 0);
		LeaveCriticalSection(&BallOverlayImgCS);

		if (bExit) break;
	}

	StopChronoQuick(&chrono_mindetectionduration);
	StopChronoQuick(&chrono);

	fclose(logballtaskfile);

	cvReleaseImage(&overlayimage);
	cvReleaseImage(&image);

	free(nbSelectedPixelsi);
	free(nbSelectedPixelsj);

	cvReleaseImage(&SelectedPixelsImage);

	if (!bExit) bExit = TRUE; // Unexpected program exit...

	return 0;
}

// min and max might cause incompatibilities with GCC...
#ifndef _MSC_VER
#ifdef max
#undef max
#endif // max
#ifdef min
#undef min
#endif // min
#endif // !_MSC_VER
