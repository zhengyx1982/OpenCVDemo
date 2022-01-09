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

int main(int argc, const char * argv[]) {
    Mat image(512, 512, CV_8UC3, Scalar(255, 0 , 0) ); // background
    circle(image, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
    rectangle(image, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
    line(image, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 3);
    putText(image, "Hello world", Point(137, 262), FONT_ITALIC, 1, Scalar(255, 255,0), 2);
    imshow("draw image", image);

    //transform 

    Point2f src[4] = {{130, 226}, {382, 226}, {130, 286}, {382, 286}};
    Point2f dest[4] = {{0.0f, 0.0f},{0.0f, 250}, {60, 0.0f},  {60, 250}};
    Mat matrix, imgWarp;
    matrix = getPerspectiveTransform(src, dest);
    warpPerspective(image, imgWarp, matrix, Point(60, 250));
    imshow("PerspectiveTransform", imgWarp);
    
    waitKey(0);
    return 0;
}
