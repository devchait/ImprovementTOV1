#ifndef PARANTER_H
#define PARANTER_H
#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Paranter
{
    public:
        Paranter();
        virtual ~Paranter();
        /**
        *   define the members used by all
        **/
        std::string ROOTDIR;
        char SEPARATOR;
        int LSH_BUCKETS;
        int LSH_K;
        int LSH_PARAM1;
        int FIRST;
        int ZERO;
        int TOTAL_BUCKETS;//only for initial purpose
        int READ_MAT;
        int READ_MAT_TO_ARRAY;
        int READ_BUCKET;
        int WRITE_DATASET;
        int WRITE_BUCKET;
        int WRITE_PRUNE_SET;
        int READ_PRUNE_SET;
        std::vector<std::string> fileName;
        enum index_to_fileName{D,D1,D2,D3,D4,BUCKET,BUCKET1,BUCKET2,BUCKET3,BUCKET4};//use to index fileName
    protected:
    private:
};

#endif // PARANTER_H
