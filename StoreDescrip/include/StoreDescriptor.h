#ifndef STOREDESCRIPTOR_H
#define STOREDESCRIPTOR_H
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "opencv2/nonfree/nonfree.hpp"
#include<opencv/cv.h>
#include <fstream>
#include <string>
#include<opencv2/flann/flann.hpp>

using namespace std;

using namespace cv;



class StoreDescriptor
{
    public:
        StoreDescriptor();
        int writeImageDescriptorsToFile(std::vector<cv::Mat>,std::vector<std::vector<cv::KeyPoint> >);
        virtual ~StoreDescriptor();


    protected:
    private:
        void openFile();
        void closeFile();
        int writeDescriptorsToFile(cv::Mat,std::vector<cv::KeyPoint>,int);
        void writeImageNumber(int index_to_image);
        std::ofstream outputFile;

};

#endif // STOREDESCRIPTOR_H
