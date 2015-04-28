#ifndef FILEPATH_H
#define FILEPATH_H
#include<iostream>
#include<dirent.h>
#include<vector>
#include<stdio.h>

using namespace std;


class FilePath
{
    public:
        FilePath();
        std::vector<std::string> getAllFiles(void);
        virtual ~FilePath();
    protected:
    private:
};

#endif // FILEPATH_H
