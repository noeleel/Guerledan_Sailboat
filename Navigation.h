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
#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "Config.h"
#include "Variables.h"

// Define Macro for the functions here

bool vent_favorable(double cap);

void navigation_cap_favorable(double theta, double cap);

bool cap_correct(double theta, double cap, double tolerance = M_PI/12.0);

void navigation_cap(double theta, double cap, double temps_sequence=100);


#endif // !NAVIGATION_H
