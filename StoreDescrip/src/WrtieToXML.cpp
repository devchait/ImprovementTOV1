#include "WrtieToXML.h"

WrtieToXML::WrtieToXML()
{
    //ctor
}

WrtieToXML::~WrtieToXML()
{
    //dtor
}
void WrtieToXML:: writeToXML()
{

   cv::FileStorage fs("test.xml",FileStorage::WRITE);
    /**
    *trial data
    *
    **/
    for(int index_i=1;index_i<3;index_i++)
    {


    int arr[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
    cv::Mat temp= Mat(2,5,CV_32S,&arr);
    fs<<"imageNumber"<<index_i;
    fs<<"index"<<index_i;
    fs<<"x_coordinate"<<23+index_i;
    fs<<"y_coordinate"<<45+index_i;
    fs<<"descriptor"<<temp;
    }

    fs.release();


    cv::FileStorage fs2("test.xml",FileStorage::READ);
    cv::Mat temp_r;

    cv::FileNode image_number=fs2["imageNumber"];
 //   cv::FileNode mat_=fs2["descriptor"];
    cv::FileNodeIterator it;
  //  cv::FileNodeIterator matIt=mat_.begin();
    for(it=image_number.begin();it!=image_number.end();it++)
    {
        int x;
        (int)(*it)["imageNumber"]>>x;
        cout<<"imageNumber:\t"<<x<<"\n";
        /*cv::Mat tempMat_;
        (*matIt)["descriptor"]>>tempMat_;
        cout<<"Mat are:\t"<<tempMat_;
        cout<<"\n";*/
    }


        fs2.release();

}
