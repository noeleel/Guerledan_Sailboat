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
#include "Variables.h"
#include "OSCore.h"
#include "rmatrix.h"

#include <deque>
#include <numeric>
#include <list>
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;

//Image Macros
#define VIDEO_IMAGE_WIDTH 320
#define VIDEO_IMAGE_HEIGHT 240

// HSV Detection Macros
#define LOWER_H 0
#define LOWER_S 80
#define LOWER_V 160

#define UPPER_H 13
#define UPPER_S 255
#define UPPER_V 255

void detect_ball(IplImage* image, IplImage* overlayimage)
#endif // !DETECTBALL_H

/* E: Flux video

Detection Balle par OpenCV

S: Positiond e la balle & sa distance
*/
