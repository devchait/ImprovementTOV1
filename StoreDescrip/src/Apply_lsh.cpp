#include "Apply_lsh.h"

Apply_lsh::Apply_lsh()
{
    //ctor
}

Apply_lsh::~Apply_lsh()
{
    //dtor
}
void Apply_lsh:: apply_lsh(std::vector<cv::Mat> descriptorList)
{
	//apply lsh on first descriptor only.
	cv::flann::Index flannIndex(descriptorList.at(0), cv::flann::LshIndexParams(12, 20, 2), cvflann::FLANN_DIST_HAMMING);



        int image_number=FIRST;//main image has image_number=0;
        int index_to_descriptor=FIRST;

    for(;index_to_descriptor < descriptorList.size(); index_to_descriptor++)
    {

        cv::Mat results;
        cv::Mat dists;

		/**apply the knn for rest of the descriptor with respect to lsh and get
		* result in buckets
		*/
		flannIndex.knnSearch(descriptorList.at(index_to_descriptor), results, dists, K,cv::flann::SearchParams() );

		/**
        	*   collecting the results in the bucket we have 500 bucktes.
        	*   1st image points are 1 to 500. 2nd are 501 to 1000 and so on.
        	*   results is a two dimensional matrix of 500 rows and K cols.
        	*
        	**/
        for(int index_to_results_rows=0;index_to_results_rows < results.rows;index_to_results_rows++)
        {
            for(int index_to_result_cols=0;index_to_result_cols < results.cols; index_to_result_cols++)
            {
                if( -1 < results.at<int>(index_to_results_rows,index_to_result_cols))
                {
                    int temp=results.at<int>(index_to_results_rows,index_to_result_cols);
                    buckets[temp].push_back(500*index_to_descriptor+index_to_results_rows);
                    cout<<"bucket number\t"<<results.at<int>(index_to_results_rows,index_to_result_cols);
                    //cout<<"\t"<<"value in the bucket\t"<<500*image_number+index_to_results_rows;
                    cout<<endl;
              }
            }
        }
        //printing the values of vector
               cout<<"Values of each and every bucket:\n";
               for(int index_to_buckets=0;index_to_buckets<TOTAL_BUCKETS;index_to_buckets++)
               {
                	cout<<"bucket number is\t"<<index_to_buckets<<endl;
                	cout<<Mat(buckets[index_to_buckets]);
                	cout<<endl;
               }




    }


}

std::vector<std::vector<int> > Apply_lsh::getAllBuckets()
{
	std::vector<std::vector<int> > bucketList;
	int index_to_buckets=0;
	for(;index_to_buckets < TOTAL_BUCKETS;index_to_buckets++)
	{
		bucketList.push_back(buckets[index_to_buckets]);
	}
	return bucketList;
}
