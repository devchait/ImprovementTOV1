#ifndef UNION_H
#define UNION_H
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
#include<stdlib.h>
#include<time.h>
#include<map>
#include<opencv/ml.h>

using namespace std;
using namespace cv;

class Union
{
    public:
        Union();
        void unite(std::vector<std::vector<float> > group,std::vector<std::vector<int> > bucket);

        std::vector<std::vector<float> > groups_bucket;

        std::vector<std::vector<float> > getGroupBucket();

        virtual ~Union();
    protected:
    private:
};

#endif // UNION_H
