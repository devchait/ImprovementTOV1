#ifndef WRITEGROUPFILE_H
#define WRITEGROUPFILE_H
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
#include<fstream>

class WriteGroupFile
{
    public:
        WriteGroupFile();
        void writeGroups(std::vector<float> label_bucket[],std::vector<float> values_of_bucket[]);
        virtual ~WriteGroupFile();
        void setFileName(std::string);
        void openFile();
        void closeFile();
        void setTotalBuckets(int total_bucket);

        int imageNumber;
        int number_of_bucket;
       std:: fstream gr_out_file;
        std::string gr_out_fileName;
    protected:
    private:
};

#endif // WRITEGROUPFILE_H
