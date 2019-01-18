// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

#include "Variables.h"

double guer_boat_x = 0;
double guer_boat_y = 0;
double commande_voile = 0;
double commande_gourvernail = 0;
double angle_critique = M_PI/3.0;
bool IsSecure = true;

double dt =  0.1;

double latitude;
double longitude;
double wind_angle;

int yaw;
int pitch;
int roll;

double heading;
double heading_north;
double wind_dir;
double wind_speed;
double north;
double wind_dir_north;
double wind_speed_north;

double x;
double y;
double gps_x;
double gps_y;

double x_hat;
double y_hat;

double waypoint_x;
double waypoint_y;
double gps_waypoint_x;
double gps_waypoint_y;

double waypoint_distance;
double line_distance;

double rudder_angle;
double sail_max_angle;

double ball_x;
double ball_y;
double ball_z;

double getLatitude(double latitude = lat_env){
    return latitude;
};

double getLongitude(double longitude = long_env){
    return longitude;
};
double getWindAngle(double wind_angle = Center(psihat)*180.0/M_PI){
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
double getHeading(double heading = Center(psihat)){
    return heading;
};

double getHeadingNorth(double heading = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI){
    return heading;
};
double getWindDirection(double wind_dir = (fmod_2PI(-angle_env-Center(psitwindhat)+M_PI+3.0*M_PI/2.0)+M_PI)*180.0/M_PI){
    return wind_dir;
};
double getWindSpeed(double wind_speed = vawind){
    return wind_speed;
};
double getNorth(double north = (fmod_2PI(-angle_env-Center(psihat)+3.0*M_PI/2.0)+M_PI)*180.0/M_PI){
    return north;
};

double getWindDirectionNorth( double wind_dir = (fmod_2PI(-psiawind+M_PI+M_PI)+M_PI)*180.0/M_PI){
    return wind_dir;
};
double getWindSpeedNorth(double wind_speed = Center(vtwindhat)){
    return wind_speed;
};

double getPosition_x(double x = Center(xhat)){ 
    return x;
};
double getPosition_y(double y =  Center(yhat)){
    return y;
};
double getGPS_x(double lat){ // latitude
    return lat;
};
double getGPS_y(double longi){ // longitude
    return longi;
};
double getWaypoint_x(double x){ // wxb
    return x;
};
double getWaypoint_y(double y){ // wyb
    return y;
};
double getGPSWaypoint_x(double lat){ // wlatb
    return lat;
};
double getGPSWaypoint_y(double longi){ // wlongb
    return longi;
};
double getWaypointDistance(double d){ // norm_bm
    return d;
};
double getLineDistance(double d){ // e
    return d;
};
double getRudderAngle(double angle = (uw >= 0)? fmod_360_rad2deg(ruddermidangle+uw*(rudderminangle-ruddermidangle)): fmod_360_rad2deg(ruddermidangle+uw*(ruddermidangle-ruddermaxangle))){
    return angle;
};
double getSailMaxAngle(double angle){ // u*q1*180.0/M_PI
    return angle;
};


double getBall_x(double x = x_ball){
    return x;
};
double getBall_y(double y = y_ball){
    return y;
};
double getBall_z(double z = z_ball){
    return z;
};

double getBalldistance(void){
    
};