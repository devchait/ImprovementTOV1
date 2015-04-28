#ifndef READMATFROMFILE_H
#define READMATFROMFILE_H
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
#include"Apply_knn.h"
using namespace std;
using namespace cv;

class ReadMatFromFile
{
    public:
        ReadMatFromFile();
        cv::Mat  ReadDataSets(std::vector<int>,int);

        int ReadBuckets(std::vector<std::vector<int> >,std::string);
        void setAllIndex(std::map<int,int>);

        int ReadPrunePoints(std::vector<cv::Mat>,std::string);
        void parseFromFileAndStore(std::string);
       void openAllFiles(std::string infile,std::string outfile);
       void closeAllFiles();
       std::vector<std::vector<float> > getAllDescriptor();

       std::vector<std::vector<float> > getFirstImageGroup();
       std::vector<std::vector<float> >desxriptor_data;

        std::ifstream in_file;
        std::ofstream outFile;
        std::map<int,int>:: iterator mapit;
        std::map<int,int> allIndex;
        std::string x_cor,y_cor,prev_line,line;
        int flag;
        int _flag;
        int point_NO;
        int lower_value,upper_value;

        std::vector<std::vector<float> > first_image_group_lable;

        virtual ~ReadMatFromFile();
    protected:
    private:
};

#endif // READMATFROMFILE_H
