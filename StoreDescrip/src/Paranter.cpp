#include "Paranter.h"

Paranter::Paranter()
{
    //ctor
        ROOTDIR="F:\\OpenCv_Practice_Programs\\Practice_Programs\\StoreDescrip\\";
        SEPARATOR='.';
        LSH_BUCKETS=20;
         LSH_K=2;
         LSH_PARAM1;
         FIRST=1;
         ZERO=0;
         TOTAL_BUCKETS=500;//only for initial purpose
         READ_MAT=1;
         READ_MAT_TO_ARRAY=4;
         READ_BUCKET=2;
         WRITE_DATASET=1;
         WRITE_BUCKET=2;
         WRITE_PRUNE_SET=3;
         READ_PRUNE_SET=3;


         fileName.at(D)="D.txt";
         fileName.at(D1)="D1.txt";
         fileName.at(D2)="D2.txt";
         fileName.at(D3)="D3.txt";
         fileName.at(D4)="D4.txt";
         fileName.at(BUCKET)="BUCKET.txt";
         fileName.at(BUCKET1)="BUCKET1.txt";
         fileName.at(BUCKET2)="BUCKET2.txt";
         fileName.at(BUCKET3)="BUCKET3.txt";
         fileName.at(BUCKET4)="BUCKET4.txt";
}

Paranter::~Paranter()
{
    //dtor
}
