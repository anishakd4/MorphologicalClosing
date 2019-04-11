#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    //Read image over which morphological closing is to applied
    Mat image = imread("../assets/closing.jpeg");

    //Create a strcuturing element and select an elliptical kernel
    int closingSize = 3;
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2*closingSize + 1, 2*closingSize + 1), Point(closingSize, closingSize));

    Mat result;
    //Apply dilaiton on the image followed by erosion.
    morphologyEx(image, result, MORPH_CLOSE, element);

    //Create windows to show images
    namedWindow("input image", WINDOW_NORMAL);
    namedWindow("closed image", WINDOW_NORMAL);

    //Display the images
    imshow("input image", image);
    imshow("closed image", result);

    //Press esc on keyboard to exit the program
    waitKey(0);

    //Close all the opened windows
    destroyAllWindows();

    return 0;
}