#ifndef WRITEMATTOFILE_H
#define WRITEMATTOFILE_H
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
#include<cmath>
#define LEVEL 5


using namespace std;
using namespace cv;

class WriteMatToFile
{
    public:
        WriteMatToFile();
        int WriteDataSets(std::vector<cv::Mat>,std::string);

        int WriteBuckets(std::vector<std::vector<int> >,std::string);

        int WritePrunePoints(std::vector<cv::Mat>,std::string);
        int WriteCommonessScore(void);

        std::ofstream out_file;

        virtual ~WriteMatToFile();
    protected:
    private:


};

#endif // WRITEMATTOFILE_H
