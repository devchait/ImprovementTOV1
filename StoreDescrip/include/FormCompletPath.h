#ifndef FORMCOMPLETPATH_H
#define FORMCOMPLETPATH_H
#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>

using namespace std;

class FormCompletPath
{
    public:
        FormCompletPath();
        std::map<int,std::string> getCompletPath(std::map<int,std::string>);
        virtual ~FormCompletPath();
    protected:
    private:
};

#endif // FORMCOMPLETPATH_H
