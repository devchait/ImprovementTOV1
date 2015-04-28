#include "ReadMatFromFile.h"

ReadMatFromFile::ReadMatFromFile()
{
    //ctor

    point_NO=0;
    lower_value=0;
    upper_value=499;
    flag=1;
    _flag=1;
}

ReadMatFromFile::~ReadMatFromFile()
{
    //dtor
}

void ReadMatFromFile:: setAllIndex(std::map<int,int> _allIndex)
{
    allIndex=_allIndex;

}
void ReadMatFromFile:: openAllFiles(std::string infile,std::string outfile)
{
    in_file.open(infile.c_str());
    outFile.open(outfile.c_str());
    mapit =allIndex.begin();
}

void ReadMatFromFile:: closeAllFiles()
{
    in_file.close();
    outFile.close();
}

std::vector<std::vector<float> > ReadMatFromFile:: getAllDescriptor()
{
    return desxriptor_data;
}

cv::Mat ReadMatFromFile:: ReadDataSets(std::vector<int>allSize,int index_i)
{


    cout<<"called"<<endl;

    cv::Mat allMat;


    if (in_file.is_open())
    {
        cout<<"in if"<<endl;



            double arr[allSize.at(index_i)][2];

            int lable[allSize.at(index_i)];
            int index_to_arr=0;
                /**
                *   Read value of given index from file Mat.txt
                **/
                if(flag)
                 {

                     getline (in_file,line);
                     getline(in_file,line);
                     flag=0;
                     //get the index line
                     getline(in_file,line);
                     prev_line.assign(line);
                     cout<<prev_line<<"\n";
                     getline(in_file,line);
                     x_cor.assign(line);
                     cout<<x_cor<<"\n";
                     getline(in_file,line);
                     y_cor.assign(line);
                     cout<<y_cor<<"\n";
                 }
                  else
                  {
                      prev_line.assign(x_cor);
                      x_cor.assign(y_cor);
                      y_cor.assign(line);
                  }

                cout<<"Going in while\n";
                cout<<"previous line is:\t"<<prev_line<<"\n";



                while ( getline (in_file,line)&&((lower_value <= mapit->second)&&(mapit->second <= upper_value)) )
                {
                    /**
                    *   find properly and then pass the line
                    *
                    **/

                        /**
                        *   extract value from the line to check whether the index is required
                        *
                        **/
                        std::string str3 (":");
                        std::size_t foundd = prev_line.find(str3);
                        std:: string index_valu=prev_line.substr((int)foundd+1);
                        cout<<"Value of index\t"<<index_valu<<"\n";
                        int index_to_check=atoi(index_valu.c_str());
                        cout<<"Value of Index in int format\t:"<<index_to_check<<"\n";
                        cout<<"Value of mapit->second is\t:"<<mapit->second<<"\n";
                        cout<<"Value of index_i:\t"<<index_i<<"\n";
                        /**
                        * complet parsing of number
                        */


                        if(index_to_check==mapit->second)
                        {
                            /**
                            *   Writing contents to new file
                            *
                            **/
                            if(mapit->second==0)
                            {
                                outFile<<"Image Number:\t"<<1<<"\n";
                            }
                            else
                            {
                                outFile<<"Image Number:\t"<<(((mapit->second)/500)+1)<<"\n";
                            }
                            outFile<<"Index Number:\t"<<mapit->second<<"\n";
                            outFile<<x_cor<<"\n";
                            outFile<<y_cor<<"\n";
                            outFile<<line<<"\n";
                            /**
                            *   Extraction of coordinates and filling to array begins
                            *
                            **/

                            std::string equality ("=");
                            std::size_t equal_pos = x_cor.find(equality);
                            double _x=atof(((x_cor.substr(equal_pos+1)).c_str()));
                            equal_pos = y_cor.find(equality);
                            double _y=atof(((y_cor.substr(equal_pos+1)).c_str()));
                           // arr[index_to_arr][0]=mapit->second;
                            lable[index_to_arr]=mapit->second;
                            arr[index_to_arr][0]=_x;
                            arr[index_to_arr][1]=_y;
                            cout<<"_x:\t"<<_x<<"\t"<<"_y:\t"<<_y<<"_index:\t"<<mapit->second<<"\n";
                            /**
                            *   Extraction of coordinates and filling to array ends
                            *
                            **/

                            /**
                            *   need to call parseFromFileAndStore
                            **/

                            parseFromFileAndStore(line);
                            /**
                            *   Currently we donot need it
                            **/

                            index_to_arr++;
                            mapit++;
                        }
                        else
                        {
                            parseFromFileAndStore(line);
                        }
                        /**
                        * update prev_line
                        **/
                      //      cout<<"index_to_check < upper_value"<<"\n\n";
                            getline (in_file,line);
                            getline (in_file,line);
                            prev_line.assign(line);
                            getline(in_file,line);
                            x_cor.assign(line);
                            getline(in_file,line);
                            y_cor.assign(line);

                }
                /**
                *   Update lower and upper
                *
                **/
                lower_value=upper_value+1;//lower_value=500
                upper_value=lower_value+499;
                /**
                *  End Update lower and upper
                *
                **

            /**
            *   Convert array to Mat
            *
            int temp_size=allSize.at(index_i);
            cv::Mat tempMat=Mat(temp_size,3,CV_64F,arr);
            cout<<"printing trempMat"<<endl;
            cout<<tempMat<<endl;
            allMat=tempMat;
          /**
          * Problem we can't push different size of Mats in the same vector.
          *
          **
          std::vector<cv:: Mat> temVect;
            temVect.push_back(tempMat);
            allMat.push_back(temVect);
          /**
          * Problem definition ends
          */
          //  cout<<temp_size<<"\n\n";
            /**/

            /**
            *   logic with knn
            *
            **/
            int arr_size=(index_to_arr);
            Apply_knn apply_knn;
            apply_knn.display(arr, arr_size,lable );

            /**
            *   Now retrive the groups from first image.
            **/
            if(_flag)
            {




                first_image_group_lable=apply_knn.getFirstImageGroups();
                _flag=0;
            }
            /**
            *   Now take union for all groups in the first image
            **/

            /**
            *   end calling knn function
            *
            **/

    }



     /**
     *  Check the values of array
     *
     **/
    /////int arr_[2][5]={{257,250,259,270,5},{162,123,148,223,222}};
    //cv::Mat _t=Mat(2,5,CV_32S,&arr_);
    //cout<<"This Mar from 1D\t"<<_t<<endl;

return allMat;

}

int ReadMatFromFile:: ReadBuckets(std::vector<std::vector<int> > bucketMat,std::string fileName)
{

    return 1;
}

int ReadMatFromFile:: ReadPrunePoints(std::vector<cv::Mat> pruneMat,string fileName)
{
    return 1;
}

void ReadMatFromFile:: parseFromFileAndStore(std::string line)
{

            std::vector<float> descriptor_row;

            std:: string str (line);

            std::string str2 ("[");
            std::string str3 ("]");
            std::size_t foundd = str.find(str2);
            std::size_t founddend = str.find(str3);

            if (foundd!=std::string::npos)
            {
                int indexOfDescriptor=0;

               std:: string descriptor=str.substr((int)foundd+1);
                cout<<"descriptor has "<<descriptor<<endl;
                //we have started indexOfDescriptor from 1 so the last value of loop is 127

                for(;indexOfDescriptor<31;indexOfDescriptor++)
                {
                    std::size_t commaIndex=descriptor.find(",");

                    //which occurs between index 0 to index of ','
                   std:: string descriptorValue=descriptor.substr(0,(int)(commaIndex));
                //   std::cout<< "value of first descriptor is:"<< descriptorValue<<endl;
                   /**
                   *    Converting to integer and storing in array of
                   *
                   **/
                  descriptor_row.push_back(atof(descriptorValue.c_str()));
                   cout<<"Integer values are:: "<<descriptor_row.at(indexOfDescriptor)<<endl;
                    //No need of foundd
                    //foundd=commaIndex;
                    descriptor=descriptor.substr((int)commaIndex+1);
                }
                //print the last value of descriptor
                std::size_t closeBracket=descriptor.find("]");
             //   cout<<"value of closeBracket:="<<closeBracket<<endl;


               std:: string descriptorValue=descriptor.substr(0,(int)(closeBracket));
                descriptor_row.push_back(atof(descriptorValue.c_str()));
               //columarr[indexOfDescriptor] =atoi(descriptorValue.c_str());
               cout<<"Integer values are:: "<<descriptor_row.at(indexOfDescriptor)<<endl;
/**
*   Values are put correctly in order.
**/
            }
        desxriptor_data.push_back(descriptor_row);

}
std::vector<std::vector<float> > ReadMatFromFile:: getFirstImageGroup()
{
    return first_image_group_lable;
}



