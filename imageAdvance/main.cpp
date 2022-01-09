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
    string path = "../resources/sunflower.png";
    Mat image = imread(path); 
    Mat imgBlur, imgCanny;
    GaussianBlur(image, imgBlur, Size(9, 9), 10, 0);
    Canny(image, imgCanny, 70, 30);

    Mat imgDil, imgErode, kernel;
    kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(image, imgDil, kernel);
    erode(image, imgErode, kernel);
    
    imshow("origin", image);
    imshow("blur", imgBlur);
    imshow("canny", imgCanny);

    imshow("dilate", imgDil);
    imshow("erode", imgErode);
    waitKey(0);
    
    
    return 0;
}
