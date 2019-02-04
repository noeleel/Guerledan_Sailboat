// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef WHICHWAY_H
#define WHICHWAY_H


<<<<<<< f18921b102f1927e95f9e63c7177a61528cb0fb5
=======
/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
    If you need to copy or to set the variables in Global.cpp, you have to use the mutex. 
*/

#include <iostream>
#include "Config.h"
#include "Variables.h"
#include "math.h"



#endif // !WHICHWAY_H


>>>>>>> WhichWay
/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
    If you need to copy or to set the variables in Global.cpp, you have to use the mutex. 
*/

#include <iostream>
#include "Config.h"
#include "Variables.h"
#include "math.h"

int compute_adjacency(float distance, float alpha, float r_vision);

void compute_matrix(double List_of_buoys[4][2], int Matrix[4][4]);

void mission_Indices(int List_indices[4] , double List_of_buoys[4][2]);


#endif // !WHICHWAY_H