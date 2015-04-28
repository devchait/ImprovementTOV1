#ifndef GROUPMATCHINGANDPRUNING_H
#define GROUPMATCHINGANDPRUNING_H
#include<iostream>
#include<stdio.h>
#include<vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include<conio.h>

#include<stdlib.h>
#include<time.h>
#include<map>
#include<opencv/ml.h>
#include<fstream>

using namespace std;
using namespace cv;

class GroupMatchingAndPruning
{
    public:
        GroupMatchingAndPruning();
        virtual ~GroupMatchingAndPruning();

        void setLableBucket(std::vector<std::vector<float> > lable_bucket);

        void setUnitedIndexBucket(std::vector<std::vector<float> > united_index_bucket);

        void setFileName(std::string fileName);

        void getSimilarGroups();
        void setThreshold();
        void calculateValidSimilarGroups(std::vector<float> index_list[],int groups_matched);
        std::vector<std::vector<float> > lable_bucket;
        std::vector<std::vector<float> > united_index_bucket;
        std::vector<std::vector<float> > size_of_groups_matched;
        std::vector<std::vector<float> > group_lable_matched;
        std::vector<std::vector<float> > group_index_list;

        float count_;
        int flag_;
        float threshold_1,threshold_2;


    protected:
    private:
};

#endif // GROUPMATCHINGANDPRUNING_H
