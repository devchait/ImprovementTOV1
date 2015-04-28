#include "Apply_knn.h"
#include "WriteGroupFile.h"
Apply_knn::Apply_knn()
{
    //ctor


}

void  Apply_knn:: getAll_knn(int sizeOfMat,std::vector<float> label_bucket[],std::vector<float> values_of_bucket[])
{
    /**
    *   Begin   Apply knn to the Mat
    *
    **/
    std::vector<float> container[sizeOfMat];

    int k=15;
    cv::Mat result=Mat(sizeOfMat,k,CV_32F);



    /**
    *   Load data for knn
    **/
    CvKNearest knn(&trainningMat,&labelMat);


    /**
    *   Loading complet
    **/

        knn.find_nearest(&testingMat,k,&result);

        cout<<"get max_k\t"<<knn.get_max_k()<<"\n";
        cout<<"get total trainn samples\t"<<knn.get_sample_count()<<"\n";
        cout<<result;
        cout<<"\n";


    /**
    *  End Apply knn to the Mat
    *
    **/


    /**
    *   Put values in the bucket appropriately begins
    *
    **/
    cv::Mat tempMat=cv::Mat(&testingMat);
    for(int _i=0;_i<result.rows;_i++)
    {
        /**
        *   _i points to the first row of result which corresponds to the first row of testing sample.
        *   So points at testing sample of _i must be put to the same index of index_to_bucket
        **/
        for(int _j=0;_j<result.cols;_j++)
        {
            int key_of_map=result.at<float>(_i);/**here will be change jth index needs to be added. So check cols of result**/
            int index_to_bucket=vect_indexMap[key_of_map];
            cout<<index_to_bucket<<"\t"<<key_of_map<<"\n";

            /** index of testing sample serially from begin to end*/
            int index_to_testingSample=testingIndexMat.at<int>(_i);
            (label_bucket[index_to_bucket]).push_back(index_to_testingSample);




            float _x=tempMat.at<float>(_i,0);
            float _y=tempMat.at<float>(_i,1);
            (values_of_bucket[index_to_bucket]).push_back(_x);
            (values_of_bucket[index_to_bucket]).push_back(_y);
        }/**check this again**/

    }


    /**
    *   Put values in the bucket appropriately ends
    *
    **/

    /**
    *   Printing the values in the buckets begin
    *
    **/
        for(int _j=0;_j<result.rows-1;_j++)
        {
            //std::vector<float>::iterator it_to_label_bucket;
            cout<<"Contains of bucket:\t"<<(label_bucket[_j]).at(0)<<"\n";
            for(int _k=0;_k<(label_bucket[_j]).size();_k++)
            {
                cout<<(label_bucket[_j]).at(_k)<<"\t:";
                cout<<"_x\t:"<<(values_of_bucket[_j]).at(_k*2)<<"\t";
                cout<<"_y\t:"<<(values_of_bucket[_j]).at(_k*2+1);
                cout<<"\n";
            }
            cout<<"\n\n";
        }



    /**
    *   Printing the values in the buckets end
    *
    **/
    WriteGroupFile wgrF;
    wgrF.setFileName("gr_1nnD.txt");
    wgrF.openFile();
    wgrF.imageNumber=((label_bucket[0]).at(0))/500+1;

    if(wgrF.imageNumber==1)
    {
        /**
        *   Saving all contents of lable_bucket in
        **/
        cout<<"here\n";
        int total_groups=0;
        if(result.rows%2==0)
            total_groups=result.rows;
        else
            total_groups=result.rows-1;

        cout<<"Total groups:\t"<<total_groups<<"\n";

        getFirstImageVector(label_bucket,total_groups);
    }

    wgrF.setTotalBuckets(sizeOfMat);
    wgrF.writeGroups(label_bucket,values_of_bucket);
    wgrF.closeFile();
   // return listOfMat;
}

cv::Mat Apply_knn:: getTrainningSample(cv::Mat completMat)
{

}

cv::Mat Apply_knn:: getTestSample(cv::Mat completMat)
{

}

Apply_knn::~Apply_knn()
{
    //dtor
}

void Apply_knn:: display(double arr[][2],int arr_size,int lable[] )
{
    double temp[arr_size][2];
    cout<<"\n\nInside the display of Apply_knn\n";
    cout<<"\nDisplaying the contents of the array\n";
    for(int index_i=0;index_i<arr_size;index_i++)
    {
        cout<<"Index Number:\t"<<index_i<<"\n";
        cout<<arr[index_i][0]<<"\t"<<arr[index_i][1]<<"\n";
        temp[index_i][0]=arr[index_i][0];
        temp[index_i][1]=arr[index_i][1];
    }
    cout<<"Total Size is: \t"<<arr_size<<"\n";
    getRandomIndex(arr_size,temp,lable);
}


void Apply_knn:: getRandomIndex(int arr_size,double arr[][2],int lable_original[])
{

    int half_size=arr_size/2;
    int iseven=0;
    if(arr_size%2==0)
        iseven=1;
    srand(time(NULL));//initialize the random seed




    int random_index;
    float trainningSample[half_size][2];
    float label[half_size];
    std::vector<float> lable_bucket[half_size];

    std::vector<float> values_of_bucket[half_size];
    std::vector<float> descriptor;
    std::map<int,int> map_index;
    for(int _i=0;_i<arr_size;_i++)
    {
        map_index[_i]=-1;

    }
    int j=0;
    cout<<"Printing trainning sample\n";
    while(j<half_size)
    {
        random_index=rand()%arr_size ;
        if(map_index[random_index]==-1&& random_index!=0)
        {

            map_index[random_index]=random_index;
            label[j]=lable_original[random_index];

            trainningSample[j][0]=arr[random_index][0];
            /**
            *   pushing values of arr serially in all values_of_bucket
            **/
            (values_of_bucket[j]).push_back(arr[random_index][0]);
            (values_of_bucket[j]).push_back(arr[random_index][1]);

            trainningSample[j][1]=arr[random_index][1];
            lable_bucket[j].push_back(label[j]);
            vect_indexMap[label[j]]=j;
            //cout<<"index of j:\t"<<j<<"\n";
            //cout<<"random index:\t"<<random_index<<"\n";
            //cout<<trainningSample[j][0]<<"\t"<<trainningSample[j][1]<<"\n";
            cout<<"trainning original index:\t"<<lable_bucket[j].at(0)<<"\n";
            j++;

        }

    }
    trainningMat=cvMat(half_size,2,CV_32FC1,trainningSample);
    labelMat=cvMat(half_size,1,CV_32FC1,label);
    cout<<"End printing trainning sample\n";
    /**
    *   Logic for testing sample begins
    *
    *
    **/

    cout<<"Begin printing testing sample\n";
    int testingSize=0;
        if(iseven)
        {

             testingSize=half_size;
        }
        else
        {
            testingSize=half_size+1;
        }
        float testingSample[half_size][2];

int _j=0;
int testing_original_index[half_size];
    cout<<"Training SampleIndex\t"<<"Testing Sample Index\n";
    for(int index_=0;index_<arr_size;index_++)
    {

        if((map_index[index_]==-1)&&(_j<testingSize))
        {
            testingSample[_j][0]=arr[index_][0];
            testingSample[_j][1]=arr[index_][1];
            testing_original_index[_j]=lable_original[index_];
           // cout<<testingSample[_j][0]<<"\t"<<testingSample[_j][1]<<"\n";
           //   cout<<"testing original index:\t"<<testing_original_index[_j]<<"\n";
            _j++;
        }

    }
    /**
    *   Logic for testing sample ends
    *
    *
    **/
    /**
    *   CV_32F is same as CV_32FC1
    **/
    testingIndexMat=Mat(testingSize,1,CV_32S,testing_original_index);

    testingMat=cvMat(testingSize,2,CV_32FC1,testingSample);
    cout<<"Trainning Mat\n";
//    cout<<testingMat<<"\n";
    cout<<"Trainning lables\n";
 //   cout<<labelMat<<"\n";
    cout<<"trainning mat\n";
  //  cout<<trainningMat<<"\n";
    cout<<"End printing testing sample\n";
    cout<<testingIndexMat<<"\n";
    getAll_knn(half_size,lable_bucket,values_of_bucket);

}

void  Apply_knn::getFirstImageVector(std::vector<float> first_image_lable[],int total_groups)
{
    for(int _i=0;_i<total_groups;_i++)
    {
            std::vector<float> tempVect;
        for(int _j=0;_j<((first_image_lable[_i])).size();_j++)
        {
            tempVect.push_back(((first_image_lable[_i])).at(_j));
        }
        first_image_Vect.push_back(tempVect);
    }

}

std::vector<std::vector<float> > Apply_knn:: getFirstImageGroups()
{
    return first_image_Vect;
}
