#ifndef APPLY_KNN_H
#define APPLY_KNN_H
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
class Apply_knn
{
    public:
        Apply_knn();
        void  getAll_knn(int,std::vector<float>[],std::vector<float>[]);
        cv::Mat getTrainningSample(cv::Mat);
        void display(double arr[][2],int arr_size,int lable[]);
        virtual ~Apply_knn();
       void getFirstImageVector(std::vector<float> label_bucket[],int);

       std::vector<std::vector<float> > getFirstImageGroups();



        std::map<int,int> vect_indexMap;
        std::vector<float> first_image_lable1[];
        std::vector<std::vector<float> >first_image_Vect;



        cv::Mat testingIndexMat;
        CvMat trainningMat;
        CvMat testingMat;
        CvMat labelMat;


    protected:
    private:
        std::vector<int> indexOfTestSample;

        void getRandomIndex(int arr_size,double arr[][2],int lable[]);
        cv::Mat getTestSample(cv::Mat);

};

#endif // APPLY_KNN_H
