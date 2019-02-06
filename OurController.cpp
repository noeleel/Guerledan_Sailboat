// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include "OurController.h"

/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/
void get_gps()
{
    if (ball_distance < 3){
        guer_boat_x = Center(xhat);
        guer_boat_y = Center(yhat);
    }
}


double calcul_cap(double x_robot, double y_robot, double x_ball , double y_ball)
{
    /*
    renvoie le cap que doit prendre le navire pour atteindre la bouée
    */
    double cap = atan2(y_ball - y_robot, x_ball - x_robot);
    return cap;
}

void controller(double x_robot, double y_robot, double theta, double x_ball , double y_ball)
{
    /*
    inputs:
        - le position et le theta du robot de vecteur d'état
        - coordonnées x,y du point a atteindre
    outputs:
        recalcule des commandes: commande_voile et commande_gourvernail
    */
    cap = calcul_cap(x_robot, y_robot, x_ball , y_ball);
    navigation_cap(theta,cap);
    return;
}