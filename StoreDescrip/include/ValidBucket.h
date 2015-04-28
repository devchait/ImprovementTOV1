#ifndef VALIDBUCKET_H
#define VALIDBUCKET_H
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



using namespace std;
using namespace cv;

class ValidBucket
{
    public:
        ValidBucket();
        std::vector<std::vector<int> > getValidBuckets(std::vector<std::vector<int> >);
        virtual ~ValidBucket();
    protected:
    private:
};

#endif // VALIDBUCKET_H
