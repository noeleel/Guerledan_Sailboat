// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Config.h"
#include "Navigation.h"
#include "PositionEstimator.h"
#include "OurController.h"
#include "Security.h"
#include "Variables.h"
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41


#define Origin_lat 48.1997 // 48 11.9791 N 003 00.9541 W
#define Origin_long -3.0159

#define Ball_1_lat 48.2000 // 48°12.0020'N 3°0,9050'O
#define Ball_1_long -3.01508

#define Ball_2_lat 48.1995 // 48°11,9690'N 3°0.8840'O
#define Ball_2_long -3.01473 
=======
>>>>>>> MaJ Github

THREAD_PROC_RETURN_VALUE ControllerThread(void* pParam);

#endif // !CONTROLLER_H
