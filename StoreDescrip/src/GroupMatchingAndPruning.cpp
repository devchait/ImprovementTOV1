#include "GroupMatchingAndPruning.h"

GroupMatchingAndPruning::GroupMatchingAndPruning()
{
    //ctor
    flag_=1;
    count_=0;
    threshold_1=threshold_2=0;
}


void GroupMatchingAndPruning:: setLableBucket(std::vector<std::vector<float> > _lable_bucket)
{
    lable_bucket=_lable_bucket;
    cout<<"The size of lable bucket:\t"<<lable_bucket.size();
    cout<<"\n";
}

void GroupMatchingAndPruning:: setUnitedIndexBucket(std::vector<std::vector<float> > _united_index_bucket)
{
    united_index_bucket=_united_index_bucket;
    cout<<"The size of united_index_bucket is:\t"<<united_index_bucket.size();
    cout<<"\n";
}


void GroupMatchingAndPruning:: setFileName(std::string fileName)
{

}

void GroupMatchingAndPruning:: getSimilarGroups()
{
    cout<<"\n\n::\n";
    for(int _i=0;_i<united_index_bucket.size();_i++)
    {
        std::vector<float> temp_bucket;
        std::vector<float> temp_size;
        std::vector<float> index_list[(united_index_bucket.at(_i)).size()];
        float group_lable;
        float point_lable;
        for(int _j=0;_j<(united_index_bucket.at(_i)).size();_j++)
        {
            std::ifstream in_file;
            in_file.open("gr_1nnD.txt");
            std::string line;
            float index_[united_index_bucket.at(_i).size()];
            std::string word("original");
            std::string first_separator(":");
            std::string second_separator("-");
            int point_index,group_index;
            while ( getline (in_file,line))
            {
                std::size_t found_word = line.find(word);
                if (found_word==std::string::npos)
                {
                    continue;
                }
                else
                {
                   std::size_t first_separator_position=line.find(first_separator.c_str());
                   std:: string tempstr=line.substr((first_separator_position)+1);
                   //cout<<tempstr<<"\n";
                   line.assign(tempstr);
                   //cout<<line<<"\n";
                   std:: size_t second_separator_position=line.find(second_separator);
                  // cout<<first_separator_position<<"\n";
                  // cout<<second_separator_position<<"\n";

                   tempstr=line.substr(0,second_separator_position);
                   point_lable=atoi(tempstr.c_str());

                   tempstr=line.substr(second_separator_position+1);
                   group_lable=atoi(tempstr.c_str());


                   if(point_lable==(united_index_bucket.at(_i)).at(_j))
                   {
                 //      cout<<"point_lable:\t"<<point_lable<<"-\t";
                //       cout<<"group_lable:\t"<<group_lable<<"\n";
                  //     cout<<"first value of united_index_bucket:\t"<<(united_index_bucket.at(_i)).at(_j)<<"\n";
                       if(temp_bucket.size()==0)
                       {
              //             cout<<"Inside tempbucket\n";
                      //     cout<<"group_lable is:\t"<<group_lable<<"\n";
                           temp_bucket.push_back(group_lable);
                           count_++;
                           temp_size.push_back(count_);
                           count_=0;
                           index_list[_j].push_back(point_lable);
                           break;
                       }
                       else
                       {
                           int _l=0;
                           while(_l!=temp_bucket.size())
                           {
                      //         cout<<"size of tem_bucket:\t"<<temp_bucket.size()<<"\n";
                               if(temp_bucket.at(_l)==group_lable)
                               {
                           //         cout<<"Inside while\n";
                          //          cout<<"matched found between:\t"<<temp_bucket.at(_l)<<"\t at index"<<_l<<"\n";
                                    count_= temp_size.at(_l);
                                    count_++;
                          //        cout<<"Insert count:\t"<<count_<<"at location\t"<< _l<<"\n";
                                   std::vector<float> tempor_;
                                   std::vector<float> tempList;
                                   /**Adding the pointlable in indexlist_l**/
                                   (index_list[_l]).push_back(point_lable);

                                   for(int _k=0;_k<temp_size.size();_k++)
                                    {
                                        if(_k==_l)
                                        {
                                            tempor_.push_back(count_);
                                //            cout<<"Pushed items at location:\t"<<temp_size.at(_k)<<"\t"<<_k<<"\n";
                                        }
                                        else
                                        {
                                            tempor_.push_back(temp_size.at(_k));
                              //              cout<<"Pushed items at location:\t"<<temp_size.at(_k)<<"\t"<<_k<<"\n";
                                        }



                                    }
                                    temp_size=tempor_;

                                   flag_=0;
                                   count_=0;
                                   break;

                               }
                               flag_=1;
                               _l++;
                           }
                           if(flag_)
                           {
                               temp_bucket.push_back(group_lable);
                            //   cout<<"no matched found thus inserting new group_lable:\t"<<group_lable<<"\n";
                               count_++;
                              // cout<<"the count is:\t"<<count_<<"\n";
                               temp_size.push_back(count_);
                               count_=0;
                            //   cout<<"Inside the flag_\n";

                               /**pushing the point lable at new index**/
                                 (index_list[_j]).push_back(point_lable);
                               break;
                           }

                       }
                       break;
                   }
                   else
                    continue;

                }

            }
            in_file.close();
           // break;
        }
        /**Collecting the vector in their respective buckets**/
        cout<<"The index lable\n";
        for(int _m=0;_m<(united_index_bucket.at(_i)).size();_m++)
        {
            for(int _n=0;_n<(index_list[_m]).size();_n++)
            {
                cout<<(index_list[_m]).at(_n)<<"\t";
            }
            cout<<"\nlables end ";
            cout<<"\n\n";
        }
        /**indexList display ends**/
        /**Calculate similarity calling the function**/
        calculateValidSimilarGroups(index_list,temp_bucket.size());

        /**End call**/

        cout<<"Size of temp_bucket:\t"<<temp_bucket.size()<<"\n";
        cout<<"Size of temp_size:\t"<<temp_size.size()<<"\n";

        group_lable_matched.push_back(temp_bucket);/**Push the groups those are matched by the group in first image**/

        size_of_groups_matched.push_back(temp_size);/**Push the size of each group that is matched to the first group**/

      //  cout<<"size of group_lable_matched:\t"<<group_lable_matched.size()<<"\n";
     //   cout<<"size of size_of_groups_mathced:\t"<<size_of_groups_matched.size()<<"\n";

      //  break;
    }
}

void GroupMatchingAndPruning::setThreshold()
{
    /**
    *   Formula to set the threshold
    *
    **/
}

/**
*   This function will get called for N number of times
*   N is the total number of unitedIndex per image.
*  This computes the similarity between the groups.
**/


void GroupMatchingAndPruning:: calculateValidSimilarGroups(std::vector<float> index_list[],int groups_matched)
{
    /**For total number of groups to be matched with first group from first_image_lable**
    for(int _i=0;_i<groups_matched;_i++)
    {
        /**Extract the first group of descriptor from first_image_lable**



        /**For each element in the first_lable's first group

        /**Extract the first descriptor from first_image_lable and match it with all of the descriptors from first group

        /**index_list[_i]:-indicates the size of the i'th group which is matched.
        for(int _j=0;_j<(index_list[_i]).size();_j++)
        {
            /**Compute the difference between the descriptors**

        }
    }*/
    cout<<"Inside calculateValidSimilarGroups\n";
}



GroupMatchingAndPruning::~GroupMatchingAndPruning()
{
    //dtor
}
