// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#ifndef POSITIONESTIMATOR_H
#define POSITIONESTIMATOR_H


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

#include "Config.h"
#include "Variables.h"

#include <iostream>
#include <vector>

using namespace Eigen;

void position_estimator(double vitesse, double theta);

void filter_kalman(VectorXd X_hat, MatrixXd Gx, VectorXd u, VectorXd z,MatrixXd G_alpha, MatrixXd G_beta, MatrixXd A, MatrixXd C );


#endif // !POSITIONESTIMATOR_H