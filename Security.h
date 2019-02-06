

// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef SECURITY_H
#define SECURITY_H


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

#include <iostream>
#include "Config.h"
#include "Variables.h"

#define MIN_LONGITUDE 3.0147400
#define MAX_LONGITUDE 3.0167500
#define MIN_LATITUDE 48.198900
#define MAX_LATITUDE 48.200800

// Define the safety Zone here 
bool IsItSafe(); // Should be modified to take into account the environment

bool AssertVariablesClose(void); // If the variables are too far from the true variables, 
// take the true values

bool SelectController(bool safe);

#endif // !SECURITY_H


/*

Entree : GPS + fichiers configuration (tolérance & zone de sécurité)

Function 1: Check si en zone sécu
Function 2 : Check if variables estimées similaires à variables capteurs


Function 1 : Use Controller.cpp si en pas zone sécu
Function 2 : Use OurController.cpp si en zone sécur

S : UseVar & Sécu (booléens)



*/