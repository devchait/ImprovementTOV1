#ifndef SERIALLY_H
#define SERIALLY_H
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
#include<map>
using namespace std;
using namespace cv;

class Serially
{
    public:
        Serially();
        std::map<int,int> getAllIndexSerially(std::vector<std::vector<int> >);
        virtual ~Serially();
    protected:
    private:
};

#endif // SERIALLY_H
