#include "Union.h"

Union::Union()
{
    //ctor
}

Union::~Union()
{
    //dtor
}
void Union:: unite(std::vector<std::vector<float> > group,std::vector<std::vector<int> >bucket)
{
    /**
    *   group: contains only elements of the image which we are searching
    *   bucket: contains bucket for each element of the group
    */
    cout<<"Displaying all gropus in first image\n";

    for(int _i=0;_i<group.size();_i++)
    {
        cout<<(group.at(_i)).at(0)<<"\n";
        std::map<float,float> tempUniteElement;
        cout<<"Displaying all points in the groups:\n";
        for(int _j=0;_j<(group.at(_i)).size();_j++)
        {
            /**
            *   every element in every group is from image 1 thus we are sure that we will get the respective bucket for
            *   each and every index
            **/

            cout<<((group.at(_i)).at(_j))<<"\n";

            int index_to_bucket;
            index_to_bucket=(group.at(_i)).at(_j);
            //tempUniteElement[index_to_bucket]=index_to_bucket;
            for(int _l=0;_l<(bucket.at(index_to_bucket)).size();_l++)
            {
                int key,value;
                key=(bucket.at(index_to_bucket).at(_l));
                value=key;
                tempUniteElement[key]=value;
            }
        }
        cout<<"\n\n";
        /**
        *   Putting contents of map in vector. Its elements corresponds to the group serially
        *
        **/
        std::vector<float> tempElement;
        std::map<float,float>::iterator it_map;
        for(it_map=tempUniteElement.begin();it_map!=tempUniteElement.end();it_map++)
        {
           // cout<<"union contents:\t"<<it_map->second<<"\n";
            tempElement.push_back(it_map->second);
        }
        groups_bucket.push_back(tempElement);
    }
    /**
    *   Testing whether the size of group_bucket and label is same
    **/
    cout<<"Total Grouped Bucket\t"<<groups_bucket.size()<<"\n";
    cout<<"Total Groups in first Image\t"<<group.size()<<"\n";
    /**
    *   Testing is successful and both has same value.
    **/

}


std::vector<std::vector<float> > Union::getGroupBucket()
{
    return groups_bucket;
}
