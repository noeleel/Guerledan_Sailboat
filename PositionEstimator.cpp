#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include <iostream>
#include <vector>

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
	Eigen::VectorXd X_hat;
	Eigen::VectorXd u;
	Eigen::VectorXd y;
	Eigen::MatrixXd Gx;
	Eigen::MatrixXd A;
	Eigen::MatrixXd C;
	Eigen::MatrixXd G_beta;
	Eigen::MatrixXd G_alpha;

	
	X_hat = Eigen::VectorXd(2); //  state
	X_hat << x_hat, y_hat;

	Gx = Eigen::MatrixXd(2, 2); 	//  covariance matrix
	Gx << 1000, 0, 0, 1000;

	u = Eigen::VectorXd(2);    // external motion
	u << dt*cos(theta)*vitesse, dt*sin(theta)*vitesse;

    y = Eigen::VectorXd(2);
	y << 0, 0;

	A = Eigen::MatrixXd(2, 2); // state transition matrix
	A << 0, 0, 0, 0;

	C = Eigen::MatrixXd(1, 2);
	C << 0, 0;

	G_beta = Eigen::MatrixXd(1, 1);
	G_beta << 0;

	G_alpha = Eigen::MatrixXd(2, 2);
	G_alpha << 0, 0, 0, 0;

	//call Kalman filter algorithm
	filter_kalman(X_hat, Gx, u, y, G_alpha, G_beta, A, C);

	return;
}


void filter_kalman(Eigen::VectorXd X_hat, Eigen::MatrixXd Gx, Eigen::VectorXd u, Eigen::VectorXd y, Eigen::MatrixXd G_alpha, Eigen::MatrixXd G_beta, Eigen::MatrixXd A, Eigen::MatrixXd C )
{
    Eigen::VectorXd ytilde = y - C * X_hat;
    Eigen::MatrixXd Ct = C.transpose();
    Eigen::MatrixXd S = C * Gx * Ct + G_beta;
    Eigen::MatrixXd Si = S.inverse();
    Eigen::MatrixXd K =  Gx * Ct * Si;
	Eigen::MatrixXd I = Eigen::MatrixXd::Identity(2, 2);

    //kalman predictor
    X_hat = X_hat + (K * ytilde);
    Gx = (I - K * C) * Gx;

    // kalman corrector
    X_hat = A * X_hat + u;
    Eigen::MatrixXd At = A.transpose();
    Gx = A * Gx * At + G_alpha;

    x_hat = X_hat(0);
    y_hat = X_hat(1);

    return;
}