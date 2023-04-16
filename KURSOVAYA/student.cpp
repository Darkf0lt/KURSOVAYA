#include "student.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "session.h"
#include <string.h>
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
        dateofbirth.day << "." << dateofbirth.month << "." << dateofbirth.year << " " <<yearofentery<<" "<<
        fac << " " << kaf << " " << group << " " << ID << " " << gender<<" " << endl;
    student::PrintSessions();
}

void student::PrintSessions()
{
    for (int i = 0; i < sessionsq; i++)
    {
        cout << "������ " << i + 1 << ": " << endl;
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
            system("pause");
            system("cls");
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
    file.write((char*)this, sizeof(student));
    file.write((char*)sessions, sizeof(sessions));
    for (int i = 0; i < sessionsq; i++)
    {
        file.write((char*)&sessions[i].disq, sizeof(int));
        for (int j = 0; j < sessions[i].disq; j++)
        {
            file.write((char*)&sessions[i].alldisc[j].name, sizeof(sessions[i].alldisc[j].name));
            file.write((char*)&sessions[i].alldisc[j].mark, sizeof(sessions[i].alldisc[j].mark));
        }
    }
    file.close();
}

void student::WriteDownBuf()
{
    ofstream file;
    file.open("buf.bin",  ios::app | ios::binary);
    file.write((char*)this, sizeof(student));
    file.write((char*)sessions, sizeof(sessions));
    for (int i = 0; i < sessionsq; i++)
    {
        file.write((char*)&sessions[i].disq, sizeof(int));
        for (int j = 0; j < sessions[i].disq; j++)
        {
            file.write((char*)&sessions[i].alldisc[j].name, sizeof(sessions[i].alldisc[j].name));
            file.write((char*)&sessions[i].alldisc[j].mark, sizeof(sessions[i].alldisc[j].mark));
        }
    }
    file.close();
}

void student::ExtractFile()
{
    ifstream file;
    file.open("db.bin", ios::binary | ios::in);
    file.read((char*)this, sizeof(student));
    sessions = (session*) new session[sessionsq];
    file.read((char*)sessions, sizeof(sessions));
    for (int i = 0; i < sessionsq; i++)
    {
        file.read((char*)&sessions[i].disq, sizeof(int));
        sessions[i].alldisc = (disciplineinfo*) new disciplineinfo[sessions[i].disq];
    
       for (int j = 0; j < sessions[i].disq; j++)
        {
            file.read((char*)&sessions[i].alldisc[j].name, sizeof(sessions[i].alldisc[j].name));
            file.read((char*)&sessions[i].alldisc[j].mark, sizeof(sessions[i].alldisc[j].mark));
        }
    }
    file.close();
}

void student::ChangeInfo()//����� �������� ���� ��� � GETINFO~!!!!!
{
    while (true)
    {
        int input;
        cout << "����� ���� �� ������� ��������? " << endl;
        cout << "1. ���: " << fio.surename << " " << fio.name << " " << fio.lastname << endl;
        cout << "2. ���� ��������: " << dateofbirth.day << "." << dateofbirth.month << "." << dateofbirth.year << endl;
        cout << "3. ���������: " << fac << endl;
        cout << "4. �������: " << kaf << endl;
        cout << "5. ������: " << group << endl;
        cout << "6. ����� ������������� ������: " << ID << endl;
        cout << "7. ���: " << gender << endl;
        cout << "8. ���������� � �������: " << endl;
        student::PrintSessions();
        cout << "9. ��������� ��������� " << endl;
        cout << " ��� �����: ";
        cin >> input;
        switch (input)
        {
        case 1:
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
            system("cls");
            break;
        case 2:
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
            system("cls");
            break;
        case 3:
            cout << "������� ��������� ��������: ";
            cin >> fac;
            system("cls");
            break;
        case 4:
            cout << "������� ������� ��������: ";
            cin >> kaf;
            system("cls");
            break;
        case 5:
            cout << "������� ������ ��������: ";
            cin >> group;
            system("cls");
            break;
        case 6:
            cout << "������� ����� ������������� ������: ";
            cin >> ID;
            system("cls");
            break;
        case 7:
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
            system("cls");
            break;
        case 8:
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
            system("cls");
            break;
        case 9:
            goto finish;
            break;
        }
    }
finish:
    system("cls");
}
