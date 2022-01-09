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
     string path = "../resources/video.mov";
    VideoCapture cap(path);
     Mat image;
     while (cap.read(image))
     {
        imshow("Video", image);
        waitKey(1);
     }
     
     waitKey(0);
    
    return 0;
}
