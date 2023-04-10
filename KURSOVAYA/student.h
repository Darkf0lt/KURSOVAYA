#pragma once
#include "session.h"

struct FIO
{
    char name[20];
    char surename[20];
    char lastname[20];
};
struct Date
{
    int day;
    int month;
    int year;
};

class student
{
public:
    FIO fio;
    Date dateofbirth;
    int yearofentery;
    char fac[20];
    char kaf[20];
    char group[11];
    char ID[8];
    char gender;
    int sessionsq;
    session* sessions;
    void GetInfo();
    void PrintInfo();
    void WriteDown();
    //void ExtractFile();
};


