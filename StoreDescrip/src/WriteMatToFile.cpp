#include "WriteMatToFile.h"

WriteMatToFile::WriteMatToFile()
{
    //ctor
}

WriteMatToFile::~WriteMatToFile()
{
    //dtor
}

int WriteMatToFile:: WriteDataSets(std::vector<cv::Mat> dataSetMat,string fileName)
{
    int index_to_dataSetMat=0;
    WriteMatToFile wM;
    wM.out_file.open(fileName.c_str());
    for(;index_to_dataSetMat< dataSetMat.size();index_to_dataSetMat++)
    {

        /**
        *   Write to the file
        *
        **/
        Mat tempMat=dataSetMat.at(index_to_dataSetMat);

       wM.out_file<<" Begin Descriptors of Image :\t"<<index_to_dataSetMat<<endl;
        /**
        *   Writing every descriptor of Mat
        *   0->FromColumnNumber
        *   1->NumberOfRows
        **/
        int index_to_rowOfMat=0;
        for(;index_to_rowOfMat<tempMat.rows;index_to_rowOfMat++)
        {
            Mat eachDescriptor (tempMat,Rect(0,index_to_rowOfMat,tempMat.cols,1));
            wM.out_file<<"Point Number:\t"<<index_to_dataSetMat+1<<"."<<index_to_rowOfMat<<endl;
            wM.out_file<<"Index Number:\t"<<index_to_rowOfMat+500*index_to_dataSetMat<<endl;
            wM.out_file<<eachDescriptor;
            wM.out_file<<endl;
        }

    }
    wM.out_file.close();
    return 1;
}
int WriteMatToFile:: WriteCommonessScore(void)
{
    std::string scoresfile="scores.txt";
    ofstream outFile;
    std::vector<double> base;
    base.push_back(1);
    base.push_back(5);
    base.push_back(10);
    base.push_back(15);
    int taw=-2;
    outFile.open(scoresfile.c_str());
    outFile<<"Value of Taw:\t"<<taw<<"\n";
    for(int level=2;level<=LEVEL;level++)
    {

        double temp_base=base.at(level-2);
        double result=pow(temp_base,level);
        outFile<<"Commoness Score for level:\t"<<level<<":\t:"<<result<<":\n";
    }
    outFile.close();

}


int WriteMatToFile:: WriteBuckets(std::vector<std::vector<int> > bucketMat,std::string fileName)
{
    int index_to_bucketMat=0;
    WriteMatToFile wM;
    wM.out_file.open(fileName.c_str());
    for(;index_to_bucketMat< bucketMat.size();index_to_bucketMat++)
    {

        /**
        *   Write to the file
        *
        **/
        std::vector<int> tempVect=bucketMat.at(index_to_bucketMat);
        cout<<index_to_bucketMat<<endl;
        int size_temp;
        size_temp=tempVect.size();//checking Mp!=0

            //size_temp-1 index of last number in temp_vect
            int bucketNumber=tempVect.at(size_temp-1);//last index contains the bucket number
            wM.out_file<<"Writing the Bucket Number:\t"<< bucketNumber<<endl;

            /**
            * Writing every point of bucket in the file
            **/
            int index_to_vectorPoint=0;
            for(;index_to_vectorPoint<tempVect.size();index_to_vectorPoint++)
            {
                cout<<tempVect.at(index_to_vectorPoint)<<endl;
                wM.out_file<<tempVect.at(index_to_vectorPoint)<<endl;

            }


    }
    wM.out_file.close();
    return 1;
}
int WriteMatToFile:: WritePrunePoints(std::vector<cv::Mat> pruneMat,string fileName)
{
    int index_to_pruneMat=0;
    for(;index_to_pruneMat< pruneMat.size();index_to_pruneMat++)
    {

        /**
        *   Write to the file
        *
        **/

    }
    return 1;
}
