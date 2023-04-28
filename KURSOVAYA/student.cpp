#include "student.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
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

void FIO::GetFIO()
{
    bool flag = true;
    while (flag)
    {
        cout << "������� ������� ��������: ";
        cin >> surename;
        if (CheckName(surename)) flag = false;
    }

    flag = true;
    while (flag)
    {
        cout << "������� ��� ��������: ";
        cin >> name;
        if (CheckName(name)) flag = false;
    }

    flag = true;
    while (flag)
    {
        cout << "������� �������� ��������: ";
        cin >> lastname;
        if (CheckName(lastname)) flag = false;
    }
}

void BDate::GetDate()
{
    while (true)
    {
        cout << "������� ���� �������� � ������� '���� ����� ���': ";
        cin >> day >> month >> year;
        if (!cin.fail())
        {
            if (!(month > 12 || month < 1 || day>31 || day < 1))//��������
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
}

void INFO::GetINFO()
{
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
    while (true)
    {
        cout << "������� ����� ������������� ������: ";
        cin >> ID;
        student tmp;
        ifstream file;
        file.open("db.bin", ios::binary);
        if (tmp.ExtractFile(file) && !strcmp(ID, student::FindStudent(ID, "db.bin").ReturnID()))

            cout << "������ �����: ������� � ����� ������� ��� ����������" << endl;

        else break;
    }
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
}

void student::PrintInfo()
{
    cout << surename << " " << name << " " << lastname << " " <<
        day << "." << month << "." << year << " " << yearofentery << " " <<
        fac << " " << kaf << " " << group << " " << ID << " " << gender << " " << endl;
    student::PrintSessions();
}

void FIO::PrintFIO()
{
    cout << surename << " " << name << " " << lastname << endl;
}

void session::GetDisc()
{
    int ExC = 0, ZaC = 0;
    while (true)
    {
        cout << "������� ���-�� ���������: ";
        cin >> disq;
        if (!cin.fail())
        {
            if (!(disq < 1 || disq>10))
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
    alldisc = (disciplineinfo*)new disciplineinfo[disq];
    for (int i = 0; i < disq; i++)
    {
        cout << "������� �������� " << i + 1 << " ����������: " << endl; 
        cin.get();
        cin.getline(alldisc[i].name,30);
        while (true)
        {
            cout << "������� ������(2-5/���/�����): ";
            cin >> alldisc[i].mark;
            if (!cin.fail())
            {
                if (!CheckName(alldisc[i].mark) && ExC<5)
                {
                    ExC++;
                    if (!(stoi(alldisc[i].mark) > 5 || stoi(alldisc[i].mark) < 1))
                    {
                        break;
                    }
                    cout << "��������� ������������ �������� ������ � ������� �� ������ (�������� ����� ���������� ���������/������ ������� �� ����� ��������) " << endl;
                }
                else
                {   
                    if(ZaC < 5)
                    {
                        ZaC++;
                        if (!(strcmp(alldisc[i].mark, "���")) || !(strcmp(alldisc[i].mark, "�����"))) break;
                        cout << "��������� ������������ �������� ������ � ������� �� ������ (�������� ����� ���������� �������/������ �� ������������� �������������� ���������) " << endl;
                    }
                }
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "�� ����� ������������ ����������" << endl;
            }
        }
    }
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

bool student::GetInfo()
{
    bool flag1 = true;
    while (flag1)
    {
        this->GetFIO();
        this->GetDate();
        this->GetINFO();
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
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "�� ����� ������������ ����������" << endl;
            }
        }
        sessions = (session*) new session[sessionsq];
        for (int i = 0; i < sessionsq; i++)
        {
            sessions[i].GetDisc();
        }
        bool flag = true;
        while (flag)
        {
            char answer;
            cout << "�� ����� ��������� ������: " << endl;
            this->PrintInfo();
            cout << "�� �� �����?(Y/N/E(exit)): ";
            cin >> answer;
            switch (answer)
            {
            case 'Y':
                flag = false;
                flag1 = false;
                break;
            case 'N':
                cout << "����������, ������� ������ ������" << endl;
                system("pause");
                system("cls");
                this->ChangeInfo();
                system("cls");
                break;
            case 'E':
                flag = false;
                flag1 = false;
                system("cls");
                return false;
                break;
            default:
                cout << "����� �������� �����" << endl;
                system("cls");
                break;
            }
        }
        system("cls");
        return true;
    }
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

void student::WriteDown(const char _filename[])
{
    ofstream file;
    file.open(_filename, ios::app | ios::binary);
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

bool student::ExtractFile(ifstream& file)
{
    if (file.read((char*)this, sizeof(student)))
    {
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
        return true;
    }
    else return false;
}

void student::ChangeInfo()
{
    bool flag = true;
    bool flag1 = true;
    while (flag)
    {
        int input;
        system("cls");
        cout << "����� ���� �� ������� ��������? " << endl;
        cout << "1. ���: " << surename << " " << name << " " << lastname << endl;
        cout << "2. ���� ��������: " << day << "." << month << "." << year << endl;
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
            
            while(flag1)
            {
                system("cls");
                cout << "����� ���� ����� ��������: " << endl;
                cout << "1. �������: " << this->surename << endl;
                cout << "2. ���: " << this->name << endl;
                cout << "3. ��������: " << this->lastname << endl;
                cout << "4. ����� ";
                cin >> input;
                switch (input)
                    {
                    case 1:
                        cout << "������� �������: ";
                        cin >> this->surename;
                        flag1 = false;
                        break;
                    case 2:
                        cout << "������� ���: ";
                        cin >> this->name;
                        flag1 = false;
                        break;
                    case 3:
                        cout << "������� ��������: ";
                        cin >> this->lastname;
                        flag1 = false;
                        break;
                    case 4:
                        flag1 = false;
                        break;
                    default:
                        cout << "������";
                        break;
                    }
            }
            system("cls");
            break;
        case 2:
            this->GetDate();
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
            while (true)
            {
                cout << "������� ����� ������������� ������: ";
                cin >> ID;

                if (!strcmp(ID, student::FindStudent(ID, "db.bin").ReturnID()))

                    cout << "������ �����: ������� � ����� ������� ��� ����������" << endl;

                else break;
            }
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
            system("cls");
            flag1 = true;
            while(flag1)
            {
                system("cls");
                cout << "��� ��������� ��������: " << endl;
                cout << "1. ���������� ��� ���������� " << endl;
                cout << "2. ��������� ��������� ��������� ������ " << endl;
                cout << "3. ����� " << endl;
                cin >> input;
                switch (input)
                {
                case 1:
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
                    flag1 = false;
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    this->PrintSessions();
                    flag1 = true;
                    while (flag1)
                    {
                        cout << "����� ������ ��������� ��������(1 - " << this->sessionsq << ")" << endl;
                        cin >> input;
                        input -= 1;
                        if (input<0 || input > this->sessionsq - 1)
                        {
                            cout << "������";
                        }
                        else
                        {
                            this->sessions[input].GetDisc();
                            flag1 = false;
                        }
                    }
                    break;
                case 3:
                    flag1 = false;
                    break;
                }
            }
            break;
        case 9:
            flag = false;
            break;
        }
    }
    system("cls");
}

bool student::Check()
{
    if (!strcmp(name, "NULL")) return false;
    else return true;
}

int student::PrintAll(const char _filename[])
{
    student tmpst;
    ifstream file;
    file.open(_filename, ios::binary | ios::in);
    while (tmpst.ExtractFile(file))
    {
        cout << "|----------------------------------------------------------------------------------------------|" << endl;
        tmpst.PrintInfo();
    }
    cout << "|----------------------------------------------------------------------------------------------|" << endl;
    system("pause");
    system("cls");
    return 1;
}

student student::FindStudent(char ID[8], const char _filename[])
{
    ifstream file;
    file.open(_filename, ios::binary);
    student tmpst, res;
    while (tmpst.ExtractFile(file))
    {
        if (!(strcmp(tmpst.ID, ID)))
        {
            res = tmpst;
        }
        else tmpst.WriteDown("buf.bin");
    }
    file.close();
    return res;
}

int student::CopyFile(const char _file1[], const char _file2[])
{
    ifstream file;
    student tmpst;
    ofstream copy;
    copy.open(_file2, ios::trunc | ios::out);
    copy.close();
    file.open(_file1, ios::binary);
    while (tmpst.ExtractFile(file))
    {
        tmpst.WriteDown(_file2);
    }
    return 1;
}

int* student::GetMarks()
{
    int count = 0;
    for (int i = 0; i < sessionsq; i++)
    {
        for (int j = 0; j < sessions[i].disq; j++) count++;
    }
    int* mkarr;
    mkarr = (int*) new int[count];
    mkarr[0] = count;
    for (int i = 0; i < sessionsq; i++)
    {
        for (int j = 0; j < sessions[i].disq && count > 0; j++, count--) 
            if (!CheckName(sessions[i].alldisc[j].mark))
            {
                if (stoi((sessions[i].alldisc[j].mark)) <= 5 || stoi((sessions[i].alldisc[j].mark)) >= 2)
                    mkarr[count] = stoi(sessions[i].alldisc[j].mark);
            }
    }
    return mkarr;
}