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
        cout << "Сессия " << i + 1 << ": " << endl;
        for (int j = 0; j < sessions[i].disq; j++)
        {
            cout << "Предмет: " << sessions[i].alldisc[j].name << " Оценка: " << sessions[i].alldisc[j].mark << endl;
        }
    }
}

void student::GetInfo()
{
start:
    sng:
    cout << "Введите фамилию студента: ";
    cin >> fio.surename;
    if (!CheckName(fio.surename)) goto sng;
ng:
    cout << "Введите имя студента: ";
    cin >> fio.name;
    if (!CheckName(fio.name)) goto ng;
lng:
    cout << "Введите отчество студента: ";
    cin >> fio.lastname;
    if (!CheckName(fio.lastname)) goto lng;
    while (true)
    {
        cout << "Введите дату рождения в формате 'День Месяц Год': ";
        cin >> dateofbirth.day >> dateofbirth.month >> dateofbirth.year;
        if (!cin.fail())
        {
            if (!(dateofbirth.month > 12 || dateofbirth.month < 1 || dateofbirth.day>31 || dateofbirth.day < 1))//УЛУЧШИТЬ
            {

                break;
            }
            cout << "Проверьте корректность введённых данных и введите их заново " << endl;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы ввели некорректную информацию" << endl;
        }
    }
    while (true)
    {
        cout << "Введите год поступления: ";
        cin >> yearofentery;
        if (!cin.fail())
        {

            break;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы ввели некорректную информацию" << endl;
        }
    }
    cout << "Введите факультет студента: ";
    cin >> fac;
    cout << "Введите кафедру студента: ";
    cin >> kaf;
    cout << "Введите группу студента: ";
    cin >> group;
    cout << "Введите номер студенческого билета: ";
    cin >> ID;

    while (true)
    {
        cout << "Введите пол студента (М/Ж): ";
        cin >> gender;
        if ((gender == 'М') || (gender == 'Ж'))
        {

            break;
        }
        else cout << "Проверьте корректность введённых данных и введите их заново " << endl;
    }

    while (true)
    {
        cout << "Введите количество сессий: ";
        cin >> sessionsq;
        if (!cin.fail())
        {

            break;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы ввели некорректную информацию" << endl;
        }
    }
    sessions = (session*) new session[sessionsq];
    for (int i = 0; i < sessionsq; i++)
    {
        sessions[i].GetDisc();
    }
checkpoint:
    char answer;
    cout << "Вы ввели следующие даныые: " << endl;
    this->PrintInfo();
    cout << "Всё ли верно?(Y/N): ";
    cin >> answer;
    switch (answer)
    {
        case 'Y':
            break;
        case 'N':
            cout << "Пожалуйста, введите данные заново" << endl;
            system("pause");
            system("cls");
            goto start;
        default:
            cout << "Введён неверный ответ"<<endl;
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

void student::ChangeInfo()//ЗДЕСЬ ПОМЕНЯТЬ ВВОД КАК В GETINFO~!!!!!
{
    while (true)
    {
        int input;
        cout << "Какое поле вы желаете изменить? " << endl;
        cout << "1. ФИО: " << fio.surename << " " << fio.name << " " << fio.lastname << endl;
        cout << "2. Дата рождения: " << dateofbirth.day << "." << dateofbirth.month << "." << dateofbirth.year << endl;
        cout << "3. Факультет: " << fac << endl;
        cout << "4. Кафедра: " << kaf << endl;
        cout << "5. Группа: " << group << endl;
        cout << "6. Номер студенческого билета: " << ID << endl;
        cout << "7. Пол: " << gender << endl;
        cout << "8. Информация о сессиях: " << endl;
        student::PrintSessions();
        cout << "9. Завершить изменения " << endl;
        cout << " Ваш выбор: ";
        cin >> input;
        switch (input)
        {
        case 1:
        sng:
            cout << "Введите фамилию студента: ";
            cin >> fio.surename;
            if (!CheckName(fio.surename)) goto sng;
        ng:
            cout << "Введите имя студента: ";
            cin >> fio.name;
            if (!CheckName(fio.name)) goto ng;
        lng:
            cout << "Введите отчество студента: ";
            cin >> fio.lastname;
            if (!CheckName(fio.lastname)) goto lng;
            system("cls");
            break;
        case 2:
            while (true)
            {
                cout << "Введите дату рождения в формате 'День Месяц Год': ";
                cin >> dateofbirth.day >> dateofbirth.month >> dateofbirth.year;
                if (!cin.fail())
                {
                    if (!(dateofbirth.month > 12 || dateofbirth.month < 1 || dateofbirth.day>31 || dateofbirth.day < 1))//УЛУЧШИТЬ
                    {

                        break;
                    }
                    cout << "Проверьте корректность введённых данных и введите их заново " << endl;
                }
                else
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Вы ввели некорректную информацию" << endl;
                }
            }
            system("cls");
            break;
        case 3:
            cout << "Введите факультет студента: ";
            cin >> fac;
            system("cls");
            break;
        case 4:
            cout << "Введите кафедру студента: ";
            cin >> kaf;
            system("cls");
            break;
        case 5:
            cout << "Введите группу студента: ";
            cin >> group;
            system("cls");
            break;
        case 6:
            cout << "Введите номер студенческого билета: ";
            cin >> ID;
            system("cls");
            break;
        case 7:
            while (true)
            {
                cout << "Введите пол студента (М/Ж): ";
                cin >> gender;
                if ((gender == 'М') || (gender == 'Ж'))
                {

                    break;
                }
                else cout << "Проверьте корректность введённых данных и введите их заново " << endl;
            }
            system("cls");
            break;
        case 8:
            while (true)
            {
                cout << "Введите количество сессий: ";
                cin >> sessionsq;
                if (!cin.fail())
                {

                    break;
                }
                else
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Вы ввели некорректную информацию" << endl;
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
