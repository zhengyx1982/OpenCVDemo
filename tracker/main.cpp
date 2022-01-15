//
//  main.cpp
//  testOpenCv
//
//  Created by nancy on 2022/1/3.
//
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using std::string;

int hmin = 0, smin = 0, vmin = 0;
int hmax = 255, smax = 255, vmax = 255;

int main(int argc, const char * argv[]) {
    // insert code here...
    string path = "../resources/shapecolor.jpg";
    Mat image = imread(path);
    Mat imgHSV, imgMask;
    cvtColor(image, imgHSV, COLOR_BGR2HSV);

    string winName = "TrackBars";

    namedWindow(winName, cv::WindowFlags::WINDOW_AUTOSIZE);
    createTrackbar("Hue Min", winName, &hmin, 179);
    createTrackbar("Hue Max", winName, &hmax, 255);
    createTrackbar("Sat Min", winName, &smin, 255);
    createTrackbar("Sat Max", winName, &smax, 255);
    createTrackbar("Val Min", winName, &vmin, 255);
    createTrackbar("Val Max", winName, &vmax, 255);
    imshow("Image", image);
    imshow("Image HSV", imgHSV);
    while (true)
    {
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, imgMask);     
       
        imshow("Image Mask", imgMask);
        waitKey(1);
    }
    return 0;
}
