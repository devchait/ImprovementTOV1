#ifndef COLLECTDESRIPTORFROMINDEX_H
#define COLLECTDESRIPTORFROMINDEX_H
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

class CollectDesriptorFromIndex
{
    public:
        CollectDesriptorFromIndex();
        std::vector<int> findDescriptorFromIndexAndSave(std::map<int,int>);
        std::vector<cv::Mat> findAllValidMat(std::map<int,int>,std::vector<int>);
        virtual ~CollectDesriptorFromIndex();
    protected:
    private:
};

#endif // COLLECTDESRIPTORFROMINDEX_H
