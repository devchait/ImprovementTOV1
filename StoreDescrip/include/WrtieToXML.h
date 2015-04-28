#ifndef WRTIETOXML_H
#define WRTIETOXML_H
#include<vector>
#include<iostream>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include<conio.h>
#include<fstream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class WrtieToXML
{
    public:
        WrtieToXML();
        virtual ~WrtieToXML();
        void writeToXML();
    protected:
    private:
};

#endif // WRTIETOXML_H
