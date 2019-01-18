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
double getEccentricity(Moments &mu){
    double bigSqrt = sqrt( ( mu.m20 - mu.m02 ) *  ( mu.m20 - mu.m02 )  + 4 * mu.m11 * mu.m11  );
    return (double) ( mu.m20 + mu.m02 + bigSqrt ) / ( mu.m20 + mu.m02 - bigSqrt );
}

void detect_ball(IplImage* image, IplImage* overlayimage){
    //unsigned char* data = reinterpret_cast<unsigned char*>(image->imageData);
	//unsigned char* overlaydata = reinterpret_cast<unsigned char*>(overlayimage->imageData);
    //CorrectImageBordersRawBGR(data, VIDEO_IMAGE_WIDTH, VIDEO_IMAGE_HEIGHT, 2, 0, 0, 0);
    cv::Mat initImage = cv::cvarrToMat(image, true);
    cv::Mat gaussianImage = cv::cvarrToMat(image, false);
    cv::Mat hSVImage = cv::cvarrToMat(image, false);

    cv::Mat mask;
    cv::Mat element = getStructuringElement( 2,
                                       Size( 3, 3 ),
                                       Point( 1, 1 ) );
  
    // Apply Gaussian Blur
    cv::GaussianBlur( initImage, gaussianImage, Size(11, 11), 0, 0 );
    
    // Get the HSV Images
    cv::cvtColor(gaussianImage, hSVImage, cv::CV_BGR2HSV);
    
    // Create Mask
    cv::inRange(hSVImage, cv::Scalar(LOWER_H, LOWER_S, LOWER_V), cv::Scalar(UPPER_H, UPPER_S, UPPER_V), mask);
    /// Apply Mask
    cv::dilate( mask, mask, element, iterations = 2);
    cv::erode( mask, mask, element, iterations = 2);

    // Find contours of ball

}

 # Find the contours of the orange ball
        ret, thresh = cv2.threshold(mask, 127,255,0)
        im2, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        M = cv2.moments(thresh)
        if M["m00"] == 0:
            cX, cY = 0, 0
        else : 
            # calculate x,y coordinate of center
            cX = int(M["m10"] / M["m00"])
            cY = int(M["m01"] / M["m00"])
        center = (cX, cY)
        print(center)
        length = len(contours)
        d = 100
        radius = 100
        if length > 0 : 
            cont = np.vstack(contours[i] for i in range(length))
      
            cnt_len = cv2.arcLength(cont, True)
            cont = cv2.approxPolyDP(cont, .01*cnt_len, True)
            hull = cv2.convexHull(cont)
      
                  
            uni_hull = []
            uni_hull.append(hull) # <- array as first element of list
            #cv2.drawContours(cvImg,contours,-1,(0, 255, 0),2)
            # calculate points for each contour
            if len(hull) > 4 :
                ellipse = cv2.fitEllipse(hull)
                
                cv2.ellipse(cvImg, ellipse, (0,0,255), thickness = 2)

                radius = 0
                if (len(contours) > 0) :
                    x, y, w, h = cv2.boundingRect(contours[0])                    
                    ellipse = cv2.fitEllipse(contours[0])
                    cv2.rectangle(cvImg,(x,y),(x+w,y+h),(0,255,0),3)
                    area = cv2.contourArea(contours[0])
                    radius = math.sqrt(area* 2.54/300)/(math.pi) #cm
                    d = abs(h - w)
                    print("ecc" , d)
                    if d < 4:
                        print("It is a ball!")
                        is_it+=["It is a ball!"]
                    else:
                        print("It is not a ball!")
                        is_it+=["It is not a ball!"]

                print("radius", radius)
                # create a window
        
                cv2.namedWindow("Nao Image")
                # show the image
                cv2.imshow("Nao Image",cvImg)
        
                # wait until a key is pressed
                cv2.waitKey(0)
                cv2.destroyWindow("Nao Image")
                N+=1
            else:
                print("No contour found")
                is_it+=["No contour found"]

        else:
            print("No contour found")
            is_it+=["No contour found"]
        ecc_l+= [d]
        radius_l+=[radius]
    print(N)
    for i in range(len(is_it)):
        print(image_name[i])
        print(ecc_l[i])
        print(is_it[i])
        print(radius_l[i])
    cv2.destroyAllWindows()