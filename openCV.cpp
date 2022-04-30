// openCV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;
int main() {
    cout << "Enter picture path:\n";
    string in;
    cin >> in;

    string path = in;
    Mat img = imread(path);
    Mat resized;
    CascadeClassifier faceCascade;

    faceCascade.load("D:/haarcascade_frontalface_default.xml");
    if (faceCascade.empty()) { cout << "could not be loaded"; return 1; }
    if (img.empty()) { cout << "ERROR IMAGE COULD NOT BE LOADED! "; return 1; }
    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
    }
    resize(img, resized, Size(250, 250));
    imshow("Image", resized);
    waitKey(0);
    return 0;
}
