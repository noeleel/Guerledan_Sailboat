#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include <iostream>
#include <vector>

#include "PositionEstimator.h"

void define_var(){
	X_hat  = Eigen::VectorXd(2); // state
	U = Eigen::VectorXd(2); // external motion
	Y = Eigen::VectorXd(1,1);;
	Gx = Eigen::MatrixXd(2, 2); // covariance matrix 
	A = Eigen::MatrixXd(2, 2); // state transition matrix
	C = Eigen::MatrixXd(1, 2);
	G_beta = Eigen::MatrixXd(1, 1);
	G_alpha = Eigen::MatrixXd(2, 2);

	X_hat << 0, 0;
	Gx << 1000, 0, 0, 1000;
	U << 0, 0;
	Y << 0;
	A << 0, 0, 0, 0;
	C << 0, 0;
	G_beta << 0;
	G_alpha << 0, 0, 0, 0;

	return;
}

<<<<<<< da2f41442163fe7c2b0e455853f7dcf57bf9b5cb
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
void position_estimator(double vitesse, double theta, double dt)
=======
void position_estimator(double vitesse, double theta)
>>>>>>> MaJ Github
=======
void position_estimator(double vitesse, double theta, double dt)
>>>>>>>  Add last functional version of sailboat
{
	/*
	estimation de position du robot
	Input :
		- le position et la vitesse du robot
		- destination: position a atteindre
	*/
	//Kalman Filter variables
	
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41

	U << dt*cos(theta)*vitesse, dt*sin(theta)*vitesse;

	filter_kalman(X_hat, Gx, U, Y, G_alpha, G_beta, A, C);

	return;
}


void filter_kalman(Eigen::VectorXd X_hat, Eigen::MatrixXd Gx, Eigen::VectorXd U, Eigen::VectorXd Y, Eigen::MatrixXd G_alpha, Eigen::MatrixXd G_beta, Eigen::MatrixXd A, Eigen::MatrixXd C )
{	
<<<<<<< da2f41442163fe7c2b0e455853f7dcf57bf9b5cb
=======

	U << dt*cos(theta)*vitesse, dt*sin(theta)*vitesse;

	filter_kalman(X_hat, Gx, U, Y, G_alpha, G_beta, A, C);

	return;
}


void filter_kalman(Eigen::VectorXd X_hat, Eigen::MatrixXd Gx, Eigen::VectorXd U, Eigen::VectorXd Y, Eigen::MatrixXd G_alpha, Eigen::MatrixXd G_beta, Eigen::MatrixXd A, Eigen::MatrixXd C )
{	

>>>>>>> MaJ Github
=======
>>>>>>>  Add last functional version of sailboat
	Eigen::VectorXd ytilde;
	Eigen::MatrixXd Ct;
	Eigen::MatrixXd S;
	Eigen::MatrixXd Si;
	Eigen::MatrixXd K;
	Eigen::MatrixXd I;
	Eigen::MatrixXd At;


    Ct = C.transpose();
    S = C * Gx * Ct + G_beta;
    Si = S.inverse();
    K =  Gx * Ct * Si;
	ytilde = Y - C * X_hat;

	I = Eigen::MatrixXd::Identity(2, 2);

    //kalman predictor
    X_hat = X_hat + (K * ytilde);
    Gx = (I - K * C) * Gx;

    // kalman corrector
    X_hat = A * X_hat + U;
	At = A.transpose();
    Gx = A * Gx * At + G_alpha;
<<<<<<< da2f41442163fe7c2b0e455853f7dcf57bf9b5cb
<<<<<<< 23640b94544d6823898682ec695cb4b5547ebb41
	
	
=======

>>>>>>> MaJ Github
=======
	
	
>>>>>>>  Add last functional version of sailboat
	if (!(isnan(abs(X_hat(0)))))
    	guer_boat_x = (double) X_hat(0);
	else 
		guer_boat_x = 0;
	if (!(isnan(abs(X_hat(1)))))
    	guer_boat_y = (double) X_hat(1);
	else 
		guer_boat_y = 0;

    return;
}