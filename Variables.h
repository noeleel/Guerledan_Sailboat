// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef VARIABLES_H
#define VARIABLES_H


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

#include <iostream>
#include "Config.h"

float getLatitude(float latitude = lat_env);
float getLongitude(float longitude = long_env);
float getWindAngle(float wind_angle = Center(psihat)*180.0/M_PI);
int getYaw(int yaw = (int)fmod_360_rad2deg(-Center(psihat)-angle_env));
int getPitch(int pitch = (int)fmod_360_rad2deg(-Center(thetahat)));
int getRoll(int roll = (int)fmod_360_rad2deg(Center(phihat)));
float getHeading(float heading = Center(psihat));

float getHeadingNorth(float heading = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI));
float getWindDirection(float wind_dir = (fmod_2PI(-angle_env-Center(psitwindhat)+M_PI+3.0*M_PI/2.0)+M_PI)*180.0/M_PI);
float getWindSpeed(float wind_speed = vawind);
float getNorth(float north = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI));

float getWindDirectionNorth( float wind_dir = (fmod_2PI(-psiawind+M_PI+M_PI)+M_PI)*180.0/M_PI);
float getWindSpeedNorth(float wind_speed = Center(vtwindhat));

float getPosition_x(float x = Center(xhat));
float getPosition_y(float y =  Center(yhat));
float getGPS_x(float lat = latitude);
float getGPS_y(float longi = longitude);
float getWaypoint_x(float x = wxb);
float getWaypoint_y(float y = wyb);
float getGPSWaypoint_x(float lat = wlatb);
float getGPSWaypoint_y(float longi = wlongb);
float getWaypointDistance(float d = norm_bm);
float getLineDistance(float d = e);
float getRudderAngle(float angle = (uw >= 0)? fmod_360_rad2deg(ruddermidangle+uw*(rudderminangle-ruddermidangle)): fmod_360_rad2deg(ruddermidangle+uw*(ruddermidangle-ruddermaxangle)));
float getSailMaxAngle(float angle = u*q1*180.0/M_PI);

// Variables renamed from the Controller of M. LEBARS


// Variables renamed from the Ball detection of M. LEBARS

#endif // !VARIABLES_H


/*
guer_x
guer_y
guer_theta
guer_omega
guer_v
guer_psi_wind
guer_psi_wind_true
guer_delta_sail
guer_delta_rudder
guer_d_bouee
guer_L_waypoints
guer_P_security
guer_UseVar
guer_Security
guer_alpha_ball

+ Autres variables si nécessaire
*/