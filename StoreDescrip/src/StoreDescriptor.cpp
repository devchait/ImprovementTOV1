#include "StoreDescriptor.h"

StoreDescriptor::StoreDescriptor()
{
    //ctor
}
int StoreDescriptor::writeImageDescriptorsToFile(std::vector<cv::Mat> descriptors,std::vector<std::vector<cv::KeyPoint> >keypoints)
{
/**
*	the keypoints at location i describes the descriptors at location i of ith image.
*	It assumes that first descriptor and first keypoints are from first image and so on.
*
**/


/**
*	storing to the file and calling the file as D.txt
**/

	int index_to_descriptors=0;//descriptor of image.
	int index_to_keypoints=0;//keypoints is a vector.
	int index_to_image=0;
    openFile();
  for(;index_to_descriptors < descriptors.size();index_to_descriptors++,index_to_keypoints++)
 {
 	cv::Mat T=descriptors.at(index_to_descriptors);
	//T has all decriptors from one image.
	std::vector<cv::KeyPoint> _kp=keypoints.at(index_to_keypoints);
	//_kp has all keypoints from one image.
	writeImageNumber(index_to_image);
	writeDescriptorsToFile(T,_kp,index_to_image);
	index_to_image++;
 }
    closeFile();
	return 1;

}

int StoreDescriptor::writeDescriptorsToFile(cv::Mat D, std::vector<cv::KeyPoint> keyPoint,int imageNo)
{
	std::vector<cv::KeyPoint>::iterator itk;
	int index_i=0;
	for (itk = keyPoint.begin(); itk != keyPoint.end(); ++itk)
   	{
        //pt means cocordinates of keypoints.
        outputFile<<"Point Number:\t"<<imageNo+1<<"."<<index_i<<endl;
        outputFile<<"Index Number:\t"<<index_i+500*imageNo<<endl;
        outputFile<<"x= " <<itk->pt.x <<endl<<"y= "<<itk->pt.y<<std::endl;
        cv::Mat _D (D, Rect(0,index_i,D.cols,1));
        outputFile<<_D<<endl;

        index_i++;

    }

	return 1;
}

void StoreDescriptor::writeImageNumber(int index_to_image)
{
    outputFile<<"Below starts Descriptors of Image Number:\t"<<index_to_image<<std::endl;

}

void StoreDescriptor:: openFile()
{
	outputFile.open("D.txt");

}

void StoreDescriptor:: closeFile()
{

	outputFile.close();
}


StoreDescriptor::~StoreDescriptor()
{
    //dtor
}
