#include "student.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "session.h"
using namespace std;

bool CheckName(string _name)
{
    string alp = "0123456789";
    for (int i = 0; i < _name.length(); i++)
    {
        for (int j = 0; j < alp.length(); j++)
        {
            if (_name[i] == alp[j]) return false;
        }
    }
    return true;
}
void student::PrintInfo()
{
    cout << fio.surename << " " << fio.name << " " << fio.lastname << " " <<
        dateofbirth.day << "." << dateofbirth.month << "." << dateofbirth.year << " " <<
        fac << " " << kaf << " " << group << " " << ID << " " << gender<<endl;
    for (int i = 0; i < sessionsq; i++)
    {
        cout << "������ " << i+1 << ": "<< endl;
        for (int j = 0; j < sessions[i].disq; j++)
        {
            cout << "�������: " << sessions[i].alldisc[j].name << " ������: " << sessions[i].alldisc[j].mark << endl;
        }
    }
}

void student::GetInfo()
{
start:
    sng:
    cout << "������� ������� ��������: ";
    cin >> fio.surename;
    if (!CheckName(fio.surename)) goto sng;
ng:
    cout << "������� ��� ��������: ";
    cin >> fio.name;
    if (!CheckName(fio.name)) goto ng;
lng:
    cout << "������� �������� ��������: ";
    cin >> fio.lastname;
    if (!CheckName(fio.lastname)) goto lng;
    while (true)
    {
        cout << "������� ���� �������� � ������� '���� ����� ���': ";
        cin >> dateofbirth.day >> dateofbirth.month >> dateofbirth.year;
        if (!cin.fail())
        {
            if (!(dateofbirth.month > 12 || dateofbirth.month < 1 || dateofbirth.day>31 || dateofbirth.day < 1))//��������
            {

                break;
            }
            cout << "��������� ������������ �������� ������ � ������� �� ������ " << endl;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� ����� ������������ ����������" << endl;
        }
    }
    while (true)
    {
        cout << "������� ��� �����������: ";
        cin >> yearofentery;
        if (!cin.fail())
        {

            break;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� ����� ������������ ����������" << endl;
        }
    }
    cout << "������� ��������� ��������: ";
    cin >> fac;
    cout << "������� ������� ��������: ";
    cin >> kaf;
    cout << "������� ������ ��������: ";
    cin >> group;
    cout << "������� ����� ������������� ������: ";
    cin >> ID;

    while (true)
    {
        cout << "������� ��� �������� (�/�): ";
        cin >> gender;
        if ((gender == '�') || (gender == '�'))
        {

            break;
        }
        else cout << "��������� ������������ �������� ������ � ������� �� ������ " << endl;
    }

    while (true)
    {
        cout << "������� ���������� ������: ";
        cin >> sessionsq;
        if (!cin.fail())
        {

            break;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� ����� ������������ ����������" << endl;
        }
    }
    sessions = (session*) new session[sessionsq];
    for (int i = 0; i < sessionsq; i++)
    {
        sessions[i].GetDisc();
    }
checkpoint:
    char answer;
    cout << "�� ����� ��������� ������: " << endl;
    this->PrintInfo();
    cout << "�� �� �����?(Y/N): ";
    cin >> answer;
    switch (answer)
    {
        case 'Y':
            break;
        case 'N':
            cout << "����������, ������� ������ ������" << endl;
            goto start;
        default:
            cout << "����� �������� �����"<<endl;
            system("cls");
            goto checkpoint;
    }
    system("cls");
}



void student::WriteDown()
{
    ofstream file;
    file.open("db.bin", ios::app | ios::binary);
    file.write((char*)this,sizeof(this));
    //file.write((char*)&fio.surename, sizeof(fio.surename));
    //file.write((char*)&fio.name, sizeof(fio.name));
    //file.write((char*)&fio.lastname, sizeof(fio.lastname));
    //file.write((char*)&dateofbirth.day, sizeof(dateofbirth.day));
    //file.write((char*)&dateofbirth.month, sizeof(dateofbirth.month));
    //file.write((char*)&dateofbirth.year, sizeof(dateofbirth.year));
    //file.write((char*)&fac, sizeof(fac));
    //file.write((char*)&kaf, sizeof(kaf));
    //file.write((char*)&group, sizeof(group));
    //file.write((char*)&ID, sizeof(ID));
    //file.write((char*)&gender, sizeof(gender));
    //file.write((char*)&sessionsq, sizeof(sessionsq));
    //for (int i = 0; i < sessionsq; i++)
    //{
    //    file << " " << sessions[i].disq << " ";
    //    for (int j = 0; j < sessions[i].disq; j++)
    //    {
    //        file.write((char*)&sessions[i].alldisc[j].name,sizeof(sessions[i].alldisc[j].name)); 
    //        file.write((char*)&sessions[i].alldisc[j].mark, sizeof(sessions[i].alldisc[j].mark));
    //    }
    //}
    file.close();
}




