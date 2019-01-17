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

// Define Macro here

extern double guer_boat_x;
extern double guer_boat_y;
extern double commande_voile;
extern double commande_gourvernail;
extern double angle_critique;
extern bool IsSecure;

// Getter functions

double getLatitude(double latitude = lat_env);
double getLongitude(double longitude = long_env);
double getWindAngle(double wind_angle = Center(psihat)*180.0/M_PI);
int getYaw(int yaw = (int)fmod_360_rad2deg(-Center(psihat)-angle_env));
int getPitch(int pitch = (int)fmod_360_rad2deg(-Center(thetahat)));
int getRoll(int roll = (int)fmod_360_rad2deg(Center(phihat)));
double getHeading(double heading = Center(psihat));

double getHeadingNorth(double heading = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI);
double getWindDirection(double wind_dir = (fmod_2PI(-angle_env-Center(psitwindhat)+M_PI+3.0*M_PI/2.0)+M_PI)*180.0/M_PI);
double getWindSpeed(double wind_speed = vawind);
double getNorth(double north = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI);

double getWindDirectionNorth( double wind_dir = (fmod_2PI(-psiawind+M_PI+M_PI)+M_PI)*180.0/M_PI);
double getWindSpeedNorth(double wind_speed = Center(vtwindhat));

double getPosition_x(double x = Center(xhat));
double getPosition_y(double y =  Center(yhat));
double getGPS_x(double lat); // latitude
double getGPS_y(double longi); // longitude
double getWaypoint_x(double x); // wxb
double getWaypoint_y(double y); // wyb
double getGPSWaypoint_x(double lat); // wlatb
double getGPSWaypoint_y(double longi); // wlongb
double getWaypointDistance(double d); // norm_bm
double getLineDistance(double d); // e
double getRudderAngle(double angle = (uw >= 0)? fmod_360_rad2deg(ruddermidangle+uw*(rudderminangle-ruddermidangle)): fmod_360_rad2deg(ruddermidangle+uw*(ruddermidangle-ruddermaxangle)));
double getSailMaxAngle(double angle); // u*q1*180.0/M_PI

double getBall_x(double x = x_ball);
double getBall_y(double y = y_ball);
double getBall_z(double z = z_ball);
// Setter functions


#endif // !VARIABLES_H


