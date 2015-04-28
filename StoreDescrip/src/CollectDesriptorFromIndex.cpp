#include "CollectDesriptorFromIndex.h"


/**
*   Count the size of each bucket
*
**/

CollectDesriptorFromIndex::CollectDesriptorFromIndex()
{
    //ctor
}

CollectDesriptorFromIndex::~CollectDesriptorFromIndex()
{
    //dtor
}
std::vector<int> CollectDesriptorFromIndex:: findDescriptorFromIndexAndSave(std::map<int,int>allIndex)
{
    std::vector<int> vector_of_size;

    int temp;
    int flag=1;
    int size_counter=0;


    for(std::map<int,int>::iterator mapit=allIndex.begin();mapit!=allIndex.end();mapit++)
    {
        int index_to_Mat=0;
        int index_to_descriptor=0;
        int value_in_allIndex=0;

        if((value_in_allIndex=mapit->second)!=0)
        {
            index_to_Mat=value_in_allIndex/500;

            index_to_descriptor=(value_in_allIndex-(index_to_Mat*500));

        }
        else
        {
            index_to_Mat=0;
            index_to_descriptor=0;
        }

        if(flag)
        {
            temp=index_to_Mat;
            cout<<"Inside flag, value of index_to_Mat and temp:\t"<<index_to_Mat<<"\t"<<temp<<"\n";
            flag=0;
        }
        if(temp==index_to_Mat)
        {
            /**
            *   Calculate the number of rows in Mat also we are in same Mat save Mat values
            **/
            size_counter++;
        }
        else
        {
            /**
            *   Here means it has calculated the size and we need to push it in sizeVector then set temp=index_to_Mat
            *   reset value of size_counter
            **/
            cout<<"Value of size_counter:\t"<<size_counter<<"\n";
            vector_of_size.push_back(size_counter);
            size_counter=0;
            temp=index_to_Mat;
            cout<<"Inside else of temp==index_to_Mat, value of temp and index_to_Mat:"<<temp<<"\t"<<index_to_Mat<<"\n";
            cout<<"Value in allIndex\t"<<value_in_allIndex<<"\n";
            cout<<"Derived Image Number is\t"<<index_to_Mat<<"\n";
            cout<<"Derived Descriptor number is\t"<<index_to_descriptor<<"\n";

       }

    }
    /**
    *   Since for last descriptor there is no transition so add value of size_counter to vecotr_of_size
    *
    **/
    vector_of_size.push_back(size_counter);
    cout<<"Value of size_counter:\t"<<size_counter<<"\n";

    return vector_of_size;

}

std::vector<cv::Mat> CollectDesriptorFromIndex:: findAllValidMat(std::map<int,int> allIndex,std::vector<int>allSize)
{
    std::vector<cv::Mat> allMat;
    std::map<int,int>::iterator mapit=allIndex.begin();
    int lower_value=0;
    int upper_value=499;

    for(int index_i=0;index_i<allSize.size();index_i++)
    {
        int arr[allSize.at(index_i)][32];

        for(;(lower_value <= mapit->second)&&(mapit->second <= upper_value);mapit++)
        {
            /**
            *   Read value of given index from file Mat.txt
            **/

        }
    }
}
