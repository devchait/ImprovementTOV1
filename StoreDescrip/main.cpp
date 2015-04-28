#include "FileName.h"
#include "FilePath.h"
#include "Apply_ORB.h"
#include "Apply_lsh.h"
#include "Apply_knn.h"
#include "WriteMatToFile.h"
#include "ReadMatFromFile.h"
#include "FormCompletPath.h"
#include"StoreDescriptor.h"
#include "ValidBucket.h"
#include"Serially.h"
#include"CollectDesriptorFromIndex.h"
#include "WrtieToXML.h"
#include "Union.h"
#include "GroupMatchingAndPruning.h"
using namespace std;


int main()
{
    /**
    *   Step 1:
    *   Get all images from the dataset. Get their paths
    *
    **/
    FilePath filePath;
    std::vector<std::string> completFileNames;
    completFileNames= filePath.getAllFiles();
    ////////////////////////////step ends////////////////////////////////////////////////////////////////////

    /**
    *   Step 2:
    *   Get all images names in sorted order. Get their paths serially sorted
    *
    **/
    FileName fileName;
	cout<<"size of tempFileNames\t"<<completFileNames.size();
	cout<<"\n";
	map<int,std::string> files=fileName.getFileName(completFileNames);
	/**
	*
	*   Checking results return by Step2
	**/
	for(int index_to_map=0;index_to_map<files.size();index_to_map++)
    {
        cout<<"Image No "<<index_to_map<<"\t Name of image "<<files[index_to_map]<<"\n";
    }
    ////////////////////////////////////steps 2 ends with checking of result////////////////////////////////////////////////

    /**
    *
    *   Step 3
    *   Get complete paths
    **/
    FormCompletPath formCompletPath;
    files=formCompletPath.getCompletPath(files);
    /**
    *   Checking result of step 3
    *
    **/

    for(int index_to_map=0;index_to_map<files.size();index_to_map++)
    {
        cout<<"Image No "<<index_to_map<<"\t Path of image "<<files[index_to_map]<<"\n";
    }


/////////////////////////////////////////step 3 completed///////////////////////////////////////////////////////////////////
    /**
    *
    *   Step 4:
    *   Apply ORB to all images
    **/

    Apply_ORB apply_ORB;
    int status=apply_ORB.applyORB(files);
    std::vector<cv::Mat> vectorOfMat=apply_ORB.getAllImageFeatureDescriptors();
    std::vector<std::vector<cv::KeyPoint> > vectorOfKeyPoint=apply_ORB.getAllImageKeyPoints();

    /**
    *   Test Step4
    *
    **/
    cout<<"Size of vectorOfMat::"<<vectorOfMat.size()<<"\n";
    cout<<"Size of vectorOfKeyPoint"<<vectorOfKeyPoint.size()<<"\n";

//////////////////////////////////////////step 4 ended//////////////////////////////////////////////////////////////////////////
    /**
    *
    *   Step5:
    *   Writing D to the files use StoreDescriptor
    **/
    StoreDescriptor storeDescriptor;
    storeDescriptor.writeImageDescriptorsToFile(vectorOfMat,vectorOfKeyPoint);
    /**
    *   Step6:
    *   Apply_lsh
    **/

    Apply_lsh apply_lsh;
    apply_lsh.apply_lsh(vectorOfMat);
    std::vector<std::vector<int> > buckets;/**Take array of bucket where each array element is a set of bucket <-> to its image*/
    std::vector<std::vector<int> > original_buckets;/**As per above**/
    buckets= apply_lsh.getAllBuckets();/**Must return array to hold all the image buckets set**/
    original_buckets=buckets;
    /**
    *   Testing the lsh
    **/
    cout<<"size of buckets is:: "<<buckets.size()<<"\n";


    /**
    *   Step 6.2: Check for validBuckets. Mp!=0.[remove such buckets]
    *
    **/
    ValidBucket validBucket;
    buckets=validBucket.getValidBuckets(buckets);/**Apply this for all the buckets[] and get valid bucket[] **/


    /**
    *   Testing the validBuckets
    **/
    cout<<"size of buckets is:: "<<buckets.size()<<"\n";

///////////////////////////////////////6.2 Completed///////////////////////////////////////////////////////////////////////////
    WriteMatToFile wF;
    std::string bucketFile="bucket.txt";/**Keep every bucket in its own bucket file**/
    wF.WriteCommonessScore();


  //  WrtieToXML _writeToXML;
   // _writeToXML.writeToXML();
   // int a= wF.WriteBuckets(buckets,bucketFile);

/////////////////////////////////////////////////Step 6 completed//////////////////////////////////////////////////////////////
    /**
    *   Arrange the points serially
    *   Map returns value serially and unique
    **/
    Serially serially;
    std::map<int,int> allIndex;
    allIndex=serially.getAllIndexSerially(buckets);/**   current same operation Retrieve for all array array of allIndex **/
    cout<<"Size of allIndex\t"<<allIndex.size()<<"\n";


    /**
    *   Step 7: Write the D1 take point number from buckets and write those to file D1.txt
    *   buckets already contain valid buckets so we have index and we need to retrive descriptors
    *
    **/
    CollectDesriptorFromIndex collectDesriptorFromIndex;
    std::vector<int> all_size;
    all_size=collectDesriptorFromIndex.findDescriptorFromIndexAndSave(allIndex);

    /**
    *   Testing the validBuckets
    **/


///////////////////////////////////////7 InComplete///////////////////////////////////////////////////////////////////////////



   // Apply_knn apply_knn;
   // Mat tempo=apply_knn.getTrainningSample(vectorOfMat.at(1));

    ReadMatFromFile rMF;
    std::string dataSetFileName="D.txt";



    std::string outFileName="D1.txt";
    rMF.setAllIndex(allIndex);
    rMF.openAllFiles(dataSetFileName,outFileName);

    for(int index_i=0;index_i<all_size.size();index_i++)
    {
        rMF.ReadDataSets(all_size,index_i);
    }
    rMF.closeAllFiles();

    std::vector<std::vector<float > > all_Descriptor;
    all_Descriptor=rMF.getAllDescriptor();
    cout<<"\n\n The size of all_Descriptor that is total rows are:\t"<<all_Descriptor.size()<<"\n";

    /**
    *   Now retrive the groups from first image. If possible hold all groups
    **/
    std::vector<std::vector<float> > first_image_group_lable;
    std::vector<std::vector<float> > unitedcontents_of_groups;
    first_image_group_lable=rMF.getFirstImageGroup();

    /**
    *   Now take union for all groups in the first image
    **/
    Union takeUnion;
    takeUnion.unite(first_image_group_lable,original_buckets);
    unitedcontents_of_groups=takeUnion.getGroupBucket();

    /**
    *  Begin: Rechecking whether first_image_group_lable contains index of first image only.
    *
    **/

    for(int _i=0;_i<first_image_group_lable.size();_i++)
    {
        cout<<"The united contains of group number:\t"<<(first_image_group_lable.at(_i)).at(0)<<"\n";
        for(int _j=0;_j<(first_image_group_lable.at(_i)).size();_j++)
        {
            cout<<(first_image_group_lable.at(_i)).at(_j)<<"\n";
        }
        cout<<"\n\n";
    }

    /**
    *  End.
    *
    **/


    /**
    *  Begin: Testing the union output.
    *
    **/

     for(int _i=0;_i<unitedcontents_of_groups.size();_i++)
    {
        cout<<"The united contains of group number:\t"<<"\n";
        for(int _j=0;_j<(unitedcontents_of_groups.at(_i)).size();_j++)
        {
            cout<<(unitedcontents_of_groups.at(_i)).at(_j)<<"\n";
        }
        cout<<"\n\n";
    }

    /**
    *  End: Testing the union output.
    *
    **/

/**
*   Uptill here everything is correct. Now the question is checking the similarity between the groups.
*   Update needs in the format of the group file
**/


    /**
    *   Matching the groups and pruning them Start on Date 21/04/2014
    *
    **/
    GroupMatchingAndPruning groupMatchingAndPruning;
    /**Set the unitedcontents_of_groups **/
    groupMatchingAndPruning.setUnitedIndexBucket(unitedcontents_of_groups);

    /** Set the first image lable**/
    groupMatchingAndPruning.setLableBucket(first_image_group_lable);
    /**
    *
    *
    **/
    groupMatchingAndPruning.getSimilarGroups();

return 0;
}
