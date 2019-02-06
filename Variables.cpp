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
double commande_gouvernail = 0;
double angle_critique = M_PI/3.0;
bool IsSecure = true;
bool InSafety = true;

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

double ball_distance;
double ball_radius;

bool ballFound;

double dt =  0.1;
double x_hat;
double y_hat;
double List_of_buoys[4][2];

double vitesse;

cv::Mat ovlImage;

Eigen::VectorXd X_hat;// state
Eigen::VectorXd U; // external motion
Eigen::VectorXd Y;
Eigen::MatrixXd Gx; // covariance matrix 
Eigen::MatrixXd A; // state transition matrix
Eigen::MatrixXd C;
Eigen::MatrixXd G_beta;
Eigen::MatrixXd G_alpha;


double getLatitude(double latitude){
    return latitude;
};

double getLongitude(double longitude){
    return longitude;
};
double getWindAngle(double wind_angle){
    return wind_angle;
};
int getYaw(int yaw){
    return yaw;
};
int getPitch(int pitch){
    return pitch;
};
int getRoll(int roll){
    return roll;
};
double getHeading(double heading){
    return heading;
};

double getHeadingNorth(double heading){
    return heading;
};
double getWindDirection(double wind_dir){
    return wind_dir;
};
double getWindSpeed(double wind_speed){
    return wind_speed;
};
double getNorth(double north){
    return north;
};

double getWindDirectionNorth( double wind_dir){
    return wind_dir;
};
double getWindSpeedNorth(double wind_speed){
    return wind_speed;
};

double getPosition_x(double x){ 
    return x;
};
double getPosition_y(double y){
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
double getRudderAngle(double angle){
    return angle;
};
double getSailMaxAngle(double angle){ // u*q1*180.0/M_PI
    return angle;
};


double getBall_x(double x){
    return x;
};
double getBall_y(double y){
    return y;
};


double getBalldistance(void){
    return (double) 1.0;
};

// vitesse vrxhat = sqrt(sqr(Center(xhat-xhat_prev))+sqr(Center(yhat-yhat_prev)))/dt+vrxdotnoise