// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef REPORTER_H
#define REPORTER_H


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

#include "Config.h"
#include "Variables.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void createLogFile();


#endif // !REPORTER_H