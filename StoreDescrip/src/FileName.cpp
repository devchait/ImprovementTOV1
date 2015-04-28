#include "FileName.h"

FileName::FileName()
{
    //ctor
}

FileName::~FileName()
{
    //dtor
}
/**
*   There must not be any gap in the names of files.1,2,3,...[no missing]
*   Missing not yet handle.Can have sever impact on whole program
**/
std::map<int,std::string> FileName:: getFileName(std::vector<std::string> fileList)
{

	int index_to_fileList=0;
	int temp=0;
	std::cout<<"fileList size is\t"<<fileList.size()<<"\n";
	std::map<int,std::string> _fileName;

	//char buffer[MAX];
	//int index_to_buffer=0;
	for(;index_to_fileList < fileList.size();index_to_fileList++)
	{
		std::cout<<"index_to_fileList\t"<<index_to_fileList<<"\n";
		std::string completFileName;
		completFileName=fileList.at(index_to_fileList);
		std::cout<<"completFileName\t"<<completFileName<<"\n";
		temp=completFileName.find(".");
		std::cout<<"index of .\t"<<temp<<"\n";

		//substring till index temp
		std::cout<<"subSting is\t"<<completFileName.substr(0,temp)<<"\n";
		//assign to tempName for integer equivalent Name
		std::string tempName=completFileName.substr(0,temp);
		//convert to tempNumb to get index to save file at particular location
		int tempNumb=atoi(tempName.c_str());
        tempNumb--;
		std::cout<<"value of tempNumb:: "<<tempNumb<<"\n";
		_fileName[tempNumb]=completFileName;
		//_fileName.at(tempNumb-1)=copletFileName;
		std::cout<<"\n"<<"\n";
	}

	return _fileName;
}

