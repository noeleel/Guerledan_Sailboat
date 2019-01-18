import sys
import time
import cv2
import numpy as np
#import Image
import random
import math
import os
import warnings
warnings.filterwarnings("ignore")

def detect_ball_image():
    N = 0
    L = ["ball_"+str(i) for i in range(1,9)]
    ecc_l = []
    is_it = []
    image_name = []
    radius_l = []
    for x in L :
        x  = x + '.png'
        image_name+=[x]

        # read image from file
        cvImg = cv2.imread(x)
        cvImg_blur = cv2.GaussianBlur(cvImg, (11,11),0)
        # Get the HSV image
        cvImg_hsv = cv2.cvtColor(cvImg_blur, cv2.COLOR_BGR2HSV)
        # get dimensions
        imageHeight, imageWidth, imageChannels = cvImg.shape
    

        # Find the ornage ball
        lower_orange = (0,80,160)
        upper_orange = (13,255,255)
    
        mask = cv2.inRange(cvImg_hsv, lower_orange, upper_orange)
        mask = cv2.erode(mask, None, iterations=2)
        mask = cv2.dilate(mask, None, iterations=2)
    
    
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


detect_ball_image()
#print(detect_ball(cv2.imread("ball_3.png")))