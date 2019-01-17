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
#ifndef DETECTBALL_H
#define DETECTBALL_H

#include "Config.h"


#endif // !DETECTBALL_H

/* E: Flux video

Detection Balle par OpenCV

S: Positiond e la balle & sa distance
*/
