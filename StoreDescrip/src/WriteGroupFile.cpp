#include "WriteGroupFile.h"

WriteGroupFile::WriteGroupFile()
{
    //ctor
    imageNumber=0;
    number_of_bucket=0;

}

WriteGroupFile::~WriteGroupFile()
{
    //dtor
    closeFile();
}
void WriteGroupFile:: writeGroups(std::vector<float> label_bucket[],std::vector<float> values_of_bucket[])
{
    /**
    *   Currently assuming the file name. Later create a function to accept the name of file
    *
    **/
    gr_out_file<<"Image Number is:\t"<<imageNumber++<<"\n";
    for(int _i=0;_i<number_of_bucket;_i++)
    {



        gr_out_file<<"Group Lable:\t"<<(label_bucket[_i]).at(0)<<"\n";
        gr_out_file<<"Points in group:\n";



        for(int _j=0;_j<(label_bucket[_i]).size();_j++)
        {


            gr_out_file<<"original index-lable:\t"<<(label_bucket[_i]).at(_j)<<"-"<<(label_bucket[_i]).at(0)<<"\n";
            gr_out_file<<"x:\t"<<(values_of_bucket[_i]).at(2*_j)<<"\n";
            gr_out_file<<"y:\t"<<(values_of_bucket[_i]).at(2*_j+1)<<"\n";
        }

    }
}

void WriteGroupFile::setFileName(std:: string fileName)
{
    gr_out_fileName.assign(fileName);
}

void WriteGroupFile::openFile()
{
    gr_out_file.open(gr_out_fileName.c_str(),std::fstream::app| std::fstream::out);
}

void WriteGroupFile::closeFile()
{
    gr_out_file.close();

}

void WriteGroupFile::setTotalBuckets(int total_bucket)
{
    number_of_bucket=total_bucket;

}
