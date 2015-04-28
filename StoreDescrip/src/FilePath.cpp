#include "FilePath.h"

FilePath::FilePath()
{
    //ctor
}
std::vector<std::string> FilePath::getAllFiles(void)
		   {
			DIR *dir;

			std::vector<std::string> fileList;
			struct dirent *ent;
			if((dir=opendir("F:\\OpenCv_Practice_Programs\\Practice_Programs\\StoreDescrip\\image_dataset\\"))!=NULL)//may require c_str()
			{
				/* print all the files and directories within directory*/
				while((ent=readdir(dir))!=NULL)
				{
					printf("%s\n",ent->d_name);
					/**
					*
					*   put only .jpg files
                    *   logic begins
					**/
					std::string image_file_name=ent->d_name;
					std::string extension="jpg";
                    if (image_file_name.find(extension) != std::string::npos)
                    {
                      cout<<image_file_name<<endl;


					/**
					*   logic ends
					**/
                        fileList.push_back(ent->d_name);
                    }
				}
				closedir(dir);
				return fileList;
			}
			else{
				perror("couldn't open directory!!!\n");
				std::string nu="null";
				fileList.push_back(nu);
				return fileList;
			    }
		   }
FilePath::~FilePath()
{
    //dtor
}
