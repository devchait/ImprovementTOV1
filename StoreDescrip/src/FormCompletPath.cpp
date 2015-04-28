#include "FormCompletPath.h"

FormCompletPath::FormCompletPath()
{
    //ctor
}

FormCompletPath::~FormCompletPath()
{
    //dtor
}
std::map<int,std::string> FormCompletPath:: getCompletPath(std::map<int,std::string> fileName)
{

    std::map<int,std::string> completPath;
    for(int index_to_fileName=0;index_to_fileName< fileName.size(); index_to_fileName++)
    {
        std::string partialPath="F:\\OpenCv_Practice_Programs\\Practice_Programs\\StoreDescrip\\image_dataset\\";
        partialPath.append((fileName[index_to_fileName]).c_str());
        cout<<partialPath<<"\n";
        completPath[index_to_fileName]=partialPath;
    }
    return completPath;
}
