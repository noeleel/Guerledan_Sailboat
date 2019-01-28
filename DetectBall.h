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
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <deque>
#include <numeric>
#include <list>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

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

#define ELLIPSE_COLOR_R 0
#define ELLIPSE_COLOR_G 0
#define ELLIPSE_COLOR_B 255

#define RECTANGLE_COLOR_R 255
#define RECTANGLE_COLOR_G 0
#define RECTANGLE_COLOR_B 0

void detect_ball(IplImage* image, IplImage* overlayimage, bool bBallFound);
#endif // !DETECTBALL_H

