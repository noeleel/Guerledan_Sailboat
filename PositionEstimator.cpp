#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include <iostream>
#include <vector>
using namespace Eigen;

#include "PositionEstimator.h"

void position_estimator( double vitesse, double theta)
{
	/*
	estimation de position du robot
	Input :
		- le position et la vitesse du robot
		- destination: position a atteindre
	*/
	//Kalman Filter variables

	X_hat = VectorXd(2); //  state
	X_hat << x_hat, y_hat;

	Gx = MatrixXd(2, 2); 	//  covariance matrix
	Gx << 1000, 0, 0, 1000;

	u = VectorXd(2);    // external motion
	u << dt*cos(theta)*vitesse, dt*sin(theta)*vitesse;

    y = VectorXd(2);
	y << 0, 0;

	A = MatrixXd(2, 2); // state transition matrix
	A << 0, 0, 0, 0;

	C = MatrixXd(1, 2);
	C << 0, 0;

	G_beta = MatrixXd(1, 1);
	G_beta << 0;

	G_alpha = MatrixXd(2, 2);
	G_alpha << 0, 0, 0, 0;

	//call Kalman filter algorithm
	filter_kalman(X_hat, Gx, u, y, G_alpha, G_beta, A, C);

	return;
}


void filter_kalman(VectorXd X_hat, MatrixXd Gx, VectorXd u, VectorXd y, MatrixXd G_alpha, MatrixXd G_beta, MatrixXd A, MatrixXd C )
{
    VectorXd ytilde = y - C * X_hat;
    MatrixXd Ct = C.transpose();
    MatrixXd S = C * Gx * Ct + G_beta;
    MatrixXd Si = S.inverse();
    MatrixXd K =  Gx * Ct * Si;
	I = MatrixXd::Identity(2, 2);

    //kalman predictor
    X_hat = X_hat + (K * ytilde);
    Gx = (I - K * C) * Gx;

    // kalman corrector
    X_hat = A * X_hat + u;
    MatrixXd At = A.transpose();
    Gx = A * Gx * At + G_alpha;

    x_hat = X_hat(0);
    y_hat = X_hat(1);

    return;
}