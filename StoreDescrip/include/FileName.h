#ifndef FILENAME_H
#define FILENAME_H
#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
class FileName
{
    public:
        FileName();
        std::map<int,std::string> getFileName(std::vector<std::string>);
        virtual ~FileName();
    protected:
    private:
};

#endif // FILENAME_H
