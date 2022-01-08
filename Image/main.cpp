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
    // insert code here...
    string path = "sunflower-award.png";
    Mat image = imread(path);
    namedWindow("origin");
    imshow("origin", image);

    Mat gray;
    cvtColor(image, gray, COLOR_RGB2GRAY);
    namedWindow("gray");
    imshow("gray", gray);
    waitKey(0);
    
    
    return 0;
}
