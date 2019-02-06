// Prevent Visual Studio Intellisense from defining _WIN32 and _MSC_VER when we use 
// Visual Studio to edit Linux or Borland C++ code.
#ifdef __linux__
#	undef _WIN32
#endif // __linux__
#if defined(__GNUC__) || defined(__BORLANDC__)
#	undef _MSC_VER
#endif // defined(__GNUC__) || defined(__BORLANDC__)

#include "DetectBall.h"


/*
    File created for the SAILBOAT Project in Guerledan
    Used for defining the function for navigating with the Sailboat
*/

void detect_ball(IplImage* image, IplImage* overlayimage, bool ballFound){
    cv::Mat initImage = cv::cvarrToMat(image, true);
    cv::Mat gaussianImage = cv::cvarrToMat(image, true);
    cv::Mat hSVImage = cv::cvarrToMat(image, true);
    cv::Mat mask, thresh, hull;
    ovlImage = cv::cvarrToMat(overlayimage, false);
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size( 3, 3 ));
    cv::Moments oMoments;
    vector <vector <Point> > contours;
    vector <Point> cont;
    cv::Mat cnt;
    double cnt_len, radius, aArea, dM01, dM10, dM00;
    cv::RotatedRect eEllipse;
    cv::Rect rRect;
    int hull_length;

    ballFound = false;
    // Apply Gaussian Blur
    cv::GaussianBlur( initImage, gaussianImage, cv::Size(11, 11), 0, 0 );
    
    // Get the HSV Images
    cv::cvtColor(gaussianImage, hSVImage, CV_BGR2HSV);
    
    // Create Mask
    cv::inRange(hSVImage, Scalar(LOWER_H, LOWER_S, LOWER_V), Scalar(UPPER_H, UPPER_S, UPPER_V), mask);
    /// Apply Mask
    cv::dilate(mask, mask, element, Point(-1,-1), 2);
    cv::erode(mask, mask, element, Point(-1,-1),  2);

    // Find contours of ball
    cv::threshold(mask, thresh, 127, 255, 0);
    cv::findContours(thresh, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // Compute mandatory moments
    oMoments = cv::moments(thresh);
    dM01 = oMoments.m01;
    dM10 = oMoments.m10;
    dM00 = oMoments.m00;

    // Compute x,y coordinate of center
    ball_x = (dM00 == 0) ?  0 : (int) (dM10/dM00);
    ball_y = (dM00 == 0) ?  0 : (int) (dM01/dM00);
    
    // 0.0002645833 for converting pixels to meters
    ball_distance = (double) sqrt(pow(ball_x*0.0002645833, 2) + pow(ball_y*0.0002645833, 2));
    // Some contours are found, let's process them
    if((int) contours.size() != 0){
        // Stack the contours
        for(int i=0; i < contours.size(); i++){
            cont.insert(cont.end(), contours[i].begin(), contours[i].end());
        }
        
        // Approximate them as a ellipse-like shape. 
        cnt_len = cv::arcLength(cont, true);
        cv::approxPolyDP((cv::Mat)cont, cnt, 0.01*cnt_len, true);
        
        cv::convexHull(cnt, hull);

        hull_length =  (int) hull.rows * hull.cols;
        // If we have enough points in the shape, process it 
        if(hull_length > 5){
            // Shape it as an ellipse
	        fflush(stdout);
            eEllipse = cv::fitEllipse(hull);
            fflush(stdout);

            // Draw the ellipse
            cv::ellipse(ovlImage, eEllipse, Scalar(ELLIPSE_COLOR_R, ELLIPSE_COLOR_G, ELLIPSE_COLOR_B));
            ball_radius = 0;

            // Draw the best bouding rectangle
            rRect = cv::boundingRect(hull);
            cv::rectangle(ovlImage, rRect, Scalar(RECTANGLE_COLOR_R, RECTANGLE_COLOR_G, RECTANGLE_COLOR_B));
            aArea = cv::contourArea(hull);

            // Find the radius of the shape (we assume it is almost a circle, though it is not always true)
            ball_radius = sqrt((float) (aArea * pow(0.0002645833,2) /M_PI));

            // Assert the object is a ball. Tried with the ellipse eccentricity but it gave me absurd result
            // So I made an approximation with the properties of the bouding rectangle. (Almost work)
            ballFound = (abs((long) (rRect.height - rRect.width)) < 40) ? true : false;

        }
    }
}