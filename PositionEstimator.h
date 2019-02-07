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
#include <Eigen/Dense>
#include "math.h"

using namespace Eigen;

void define_var();
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41

void position_estimator(double vitesse, double theta, double dt);

=======

void position_estimator(double vitesse, double theta, double dt);

>>>>>>> MaJ Github
void filter_kalman(Eigen::VectorXd X_hat, Eigen::MatrixXd Gx, Eigen::VectorXd u, Eigen::VectorXd z,Eigen::MatrixXd G_alpha, Eigen::MatrixXd G_beta, Eigen::MatrixXd A, Eigen::MatrixXd C );


#endif // !POSITIONESTIMATOR_H