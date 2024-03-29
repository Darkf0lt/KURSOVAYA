#pragma once
#include <string>
#include <string.h>
using namespace std;
class FIO
{
protected:
    char name[20];
    char surename[20];
    char lastname[20];
    FIO()
    {
        strcpy_s(name, "NULL"); strcpy_s(surename, "NULL"); strcpy_s(lastname, "NULL");
    }
    void GetFIO();
public:
    void PrintFIO();
};

class BDate
{
protected:
    int day;
    int month;
    int year;
    BDate()
    {
        day = 0; month = 0; year = 0;
    }
    void GetDate();
};

class INFO
{
protected:
    int yearofentery;
    char fac[20];
    char kaf[20];
    char group[11];
    char ID[8];
    char gender;
    INFO()
    {
        yearofentery = 0; strcpy_s(fac, "NULL"); strcpy_s(kaf, "NULL"); strcpy_s(group, "NULL"); strcpy_s(ID, "NULL"); gender = 'N';
    }
    void GetINFO();
public:
    char* ReturnID()
    {
        return ID;
    }
    char ReturnGender()
    {
        return gender;
    }
};

class disciplineinfo
{
public:
    char name[20];
    char mark[6];
};

class session
{
public:
    int disq;
    disciplineinfo* alldisc;
    void GetDisc();
};

class student :public FIO, protected BDate, public INFO
{
    int sessionsq;
    session* sessions;
public:
    bool GetInfo();
    void PrintSessions();
    void PrintInfo();
    void WriteDown();
    void WriteDown(const char _filename[]);
    bool ExtractFile(ifstream &file);
    void ChangeInfo();
    bool Check();
    static bool PrintAll(const char _filename[]);
    static student FindStudent(char ID[8], const char _filename[]);
    static bool CopyFile(const char _file1[], const char _file2[]);
    int* GetMarks();
};
