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


/*

Partie Elodie
Definir ici quel chemin de bouées nous allons emprunter

E : Point de départ & Point final

Predictor ()

S : Liste des points GPS à suivre ou le point Targer 
*/