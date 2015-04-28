#ifndef APPLY_ORB_H
#define APPLY_ORB_H
#include<iostream>
#include<stdio.h>
#include<vector>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include<conio.h>
#include<stdio.h>
#include<map>

using namespace std;

using namespace cv;
using namespace std;


class Apply_ORB
{
    public:
        Apply_ORB();
        int applyORB(std::map<int,std::string>);
        std::vector<cv::Mat> getAllImageFeatureDescriptors();
        std::vector<std::vector<cv::KeyPoint> > getAllImageKeyPoints();
        virtual ~Apply_ORB();
    protected:
    private:
        std::vector<cv::Mat> all_descriptors;
        std::vector<std::vector<KeyPoint> > all_keypoints;
};

#endif // APPLY_ORB_H
