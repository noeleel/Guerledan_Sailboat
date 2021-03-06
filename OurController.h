// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef OURCONTROLLER_H
#define OURCONTROLLER_H


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

#include "Config.h"
#include "Variables.h"
#include "Navigation.h"

void get_gps();

double calcul_cap(double x_robot, double y_robot, double x_ball , double y_ball);

void controller(double x_robot, double y_robot, double theta, double x_ball , double y_ball);

#endif // !OURCONTROLLER_H
