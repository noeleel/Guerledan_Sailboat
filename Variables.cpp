// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include "Variables.h"

float getLatitude(float latitude = lat_env){
    return latitude;
};

float getLongitude(float longitude = long_env){
    return longitude;
};
float getWindAngle(float wind_angle = Center(psihat)*180.0/M_PI){
    return wind_angle;
};
int getYaw(int yaw = (int)fmod_360_rad2deg(-Center(psihat)-angle_env)){
    return yaw;
};
int getPitch(int pitch = (int)fmod_360_rad2deg(-Center(thetahat))){
    return pitch;
};
int getRoll(int roll = (int)fmod_360_rad2deg(Center(phihat))){
    return roll;
};
float getHeading(float heading = Center(psihat)){
    return heading;
};

float getHeadingNorth(float heading = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI)){
    return heading;
};
float getWindDirection(float wind_dir = (fmod_2PI(-angle_env-Center(psitwindhat)+M_PI+3.0*M_PI/2.0)+M_PI)*180.0/M_PI){
    return wind_dir;
};
float getWindSpeed(float wind_speed = vawind){
    return wind_speed;
};
float getNorth(float north = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI)){
    return north;
};

float getWindDirectionNorth( float wind_dir = (fmod_2PI(-psiawind+M_PI+M_PI)+M_PI)*180.0/M_PI){
    return wind_dir;
};
float getWindSpeedNorth(float wind_speed = Center(vtwindhat)){
    return wind_speed;
};

float getPosition_x(float x = Center(xhat)){
    return x;
};
float getPosition_y(float y =  Center(yhat)){
    return y;
};
float getGPS_x(float lat = latitude){
    return lat;
};
float getGPS_y(float longi = longitude){
    return longi;
};
float getWaypoint_x(float x = wxb){
    return x;
};
float getWaypoint_y(float y = wyb){
    return y;
};
float getGPSWaypoint_x(float lat = wlatb){
    return lat;
};
float getGPSWaypoint_y(float longi = wlongb){
    return longi;
};
float getWaypointDistance(float d = norm_bm){
    return d;
};
float getLineDistance(float d = e){
    return d;
};
float getRudderAngle(float angle = (uw >= 0)? fmod_360_rad2deg(ruddermidangle+uw*(rudderminangle-ruddermidangle)): fmod_360_rad2deg(ruddermidangle+uw*(ruddermidangle-ruddermaxangle))){
    return angle;
};
float getSailMaxAngle(float angle = u*q1*180.0/M_PI){
    return angle;
};


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/