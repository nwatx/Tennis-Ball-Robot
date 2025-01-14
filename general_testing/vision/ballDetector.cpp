#include "ballDetector.h"
#include "camera.h"
#include <iostream>
#include <thread>
#include <atomic>

using namespace cv;
using namespace std;

// original day values
int hmin = 30, smin = 102, vmin = 130;
int hmax = 70, smax = 255, vmax = 255;

//new, summer day values
// int hmin = 47, smin = 38, vmin = 105;
// int hmax = 68, smax = 255, vmax = 255;

//burning night light values
// int hmin = 38, smin = 0, vmin = 0;
// int hmax = 82, smax = 208, vmax = 255;

double currentBallX;
double currentBallY;

std::atomic<bool> track;

std::mutex mtx;

Camera cam(0);

std::thread th;

int getImageWidth()
{
    return cam.getImageWidth();
}

int getImageHeight()
{
    return cam.getImageHeight();
}

double getBallX()
{
    return currentBallX;
}

double getBallY()
{
    return currentBallY;
}

void startTracking(Rect2d initialBB)
{
    track = true;
    th = std::thread(trackBall, initialBB);
}

void stopTracking()
{
    cout << "starrting method" << endl;
    track = false;
    th.join();
    cout << "joined" << endl;
}

void setMask()
{
    cout << "PLEASE POINT THE CAMERA AT A BALL" << endl << "TRY TO ENSURE THAT THE BALL FILLS THE CENTER OF THE SCREEN" << endl << "WHEN THE CAMERA IS READY, PRESS ANY KEY" << endl;
    namedWindow("waiting window", WINDOW_AUTOSIZE);
    waitKey(0);

    Mat img = cam.getFrame();
    Mat hsv;

    cvtColor(img, hsv, COLOR_BGR2HSV);
    int midCol = hsv.cols / 2;
    int midRow = hsv.rows / 2;
    Vec3b values = hsv.at<Vec3b>(midRow, midCol);

    int h = values.val[0]; //hue
    int s = values.val[1]; //saturation
    int v = values.val[2]; //value

    hmin = max(h - 20, 0), smin = max(s - 150, 0), vmin = max(v - 20, 0);
    hmax = h + 20, smax = 255, vmax = 255; //dont need min max check because a value greater than 255 changes nothing
    cout << hmin << "\t" << smin << "\t" << vmin << endl;
    cout << hmax << "\t" << smax << "\t" << vmax << endl;
    cout << "set mask" << endl;
}

void trackBall(Rect2d initialBBox)
{
    Ptr<Tracker> tracker = TrackerMedianFlow::create();
    Mat frame = cam.getFrame();

    Rect2d currentBBox = initialBBox;
    rectangle(frame, initialBBox, Scalar(255, 0, 0), 2, 1);

    imshow("Tracking", frame);
    tracker->init(frame, currentBBox);
    //ofstream output("ballx.txt");
    while (track.load())
    {
        double timer = (double)getTickCount();
        frame = cam.getFrame();

        bool ok = tracker->update(frame, currentBBox);
        if (ok)
        {
            rectangle(frame, currentBBox, Scalar(255, 0, 0), 2, 1);
        }
        else
        {
            putText(frame, "Tracking failure detected", Point(100, 80), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2);
        }
        mtx.lock();
        currentBallX = currentBBox.x + currentBBox.width / 2;
        currentBallY = currentBBox.y + currentBBox.height / 2;
        mtx.unlock();
        //output << currentBallX << endl;

        float fps = getTickFrequency() / ((double)getTickCount() - timer);
        stringstream stream;
        stream << "FPS: " << (int)fps;
        putText(frame, stream.str(), Point(100, 50), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50, 170, 50), 2);
        imshow("Tracking", frame);
        waitKey(1);
    }
   // output.close();
}

vector<Rect2d> getBoundingBoxes()
{
    Mat img, imgCrop, imgHSV, imgMask, imgDilate;

    img = cam.getFrame();

    //img = imread("new_images/image_1.png");
    
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);
    inRange(imgHSV, lower, upper, imgMask);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
    dilate(imgMask, imgDilate, kernel);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect2d> boundRect(contours.size());


    for (int i = 0; i < contours.size(); i++)
    {
        float peri = arcLength(contours[i], true);
        approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
        boundRect[i] = boundingRect(conPoly[i]);

        rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
    }

    imshow("mask", imgMask);
    imshow("dilated", imgDilate);
    imshow("orig", img);
    // if (boundRect.size() == 0)
    // {
    //     cout << "RETURNING EMPTY" << endl;
    // }
    return boundRect;
}

/*
vector<Ball> getBalls()
{
    if (!cameraStarted)
    {
        startCamera();
    }

    Mat img, imgCrop, imgHSV, imgMask, imgDilate;

    cap.grab();
    cap.retrieve(img);

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);
    inRange(imgHSV, lower, upper, imgMask);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
    dilate(imgMask, imgDilate, kernel);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(img, contours, -1, Scalar(255, 0, 255), 1);

    vector<Ball> balls;
    for (vector<Point> &contour : contours)
    {
        Moments m = moments(contour);
        double xCenter = m.m10 / m.m00;
        double yCenter = m.m01 / m.m00;

        stringstream stream;
        stream << "(" << xCenter << ", " << yCenter << ")";

        Point p((int)xCenter, (int)yCenter);

        double area = contourArea(contour);
        stream << " " << area;

        Ball b{area, p};
        balls.push_back(b);

        string text = stream.str();
        putText(img, text, p, FONT_HERSHEY_DUPLEX, .3, Scalar(255, 255, 255), .2);
    }

    imshow("mask", imgMask);
    imshow("dilated", imgDilate);
    imshow("orig", img);
    return balls;
}
*/
