#ifndef APPLY_LSH_H
#define APPLY_LSH_H
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

using namespace std;

using namespace cv;


#define FIRST 1
#define K 2
#define TOTAL_BUCKETS 500

class Apply_lsh
{
    public:
        Apply_lsh();
        virtual ~Apply_lsh();
        void apply_lsh(std::vector<cv::Mat> descriptorList);
        std::vector<std::vector<int> > getAllBuckets();


    protected:
    private:
        vector<int>buckets[TOTAL_BUCKETS];
};

#endif // APPLY_LSH_H
