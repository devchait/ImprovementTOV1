#include "Serially.h"

Serially::Serially()
{
    //ctor
}

Serially::~Serially()
{
    //dtor
}
std::map<int,int> Serially:: getAllIndexSerially(std::vector<std::vector<int> > bucket)
{
    int allIndex_Size=0;
    for(int index_to_bucket=0; index_to_bucket<bucket.size();index_to_bucket++)
    {
        allIndex_Size=allIndex_Size+ (bucket.at(index_to_bucket)).size();
    }
    cout<<"Total Number of  Index or their sizes\t"<<allIndex_Size<<"\n";
    std::map<int,int> allIndex;

    for(int index_to_bucket=0; index_to_bucket<bucket.size();index_to_bucket++)
    {
        std::vector<int> temp=bucket.at(index_to_bucket);
        for(int index_to_value=0;index_to_value< temp.size();index_to_value++)
        {
            int key_value=temp.at(index_to_value);
            allIndex[key_value]=key_value;
            cout<<"Values in allIndex is\t"<<temp.at(index_to_value)<<"\n";
        }
    }
    return allIndex;
}
