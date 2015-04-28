#include "ValidBucket.h"

ValidBucket::ValidBucket()
{
    //ctor
}

ValidBucket::~ValidBucket()
{
    //dtor
}
std::vector<std::vector<int> > ValidBucket:: getValidBuckets(std::vector<std::vector<int> > bucket)
{
    int index_to_bucket=0;
    std::vector<std::vector<int> > validBucketList;
    for(;index_to_bucket< bucket.size();index_to_bucket++ )
    {
        std::vector<int> currentBucket=bucket.at(index_to_bucket);
        if(currentBucket.size()>0)
        {
            /**
            *   Inserting the vaild bucket number at end of this bucket
            *   then pushing this bucket to validBucketList
            **/
            currentBucket.push_back(index_to_bucket);
            //push the bucket to validBucketList
            validBucketList.push_back(currentBucket);
        }
    }
    return validBucketList;

}
