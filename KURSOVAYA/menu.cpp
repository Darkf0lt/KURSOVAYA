#include "menu.h"
#include <fstream>
using namespace std;

student menu::GetInfo(ifstream &file)
{	
	student st;
	{
		file >> st.fio.surename >> st.fio.name >> st.fio.lastname >> st.dateofbirth.day
			>> st.dateofbirth.month >> st.dateofbirth.year >> st.fac >> st.kaf >> st.group >> st.ID >> st.gender >> st.sessionsq;
		st.sessions = (session*) new session[st.sessionsq];
		for (int i = 0; i < st.sessionsq; i++)
		{
			file >> st.sessions[i].disq;
			st.sessions[i].alldisc = (disciplineinfo*)new disciplineinfo[st.sessions[i].disq];
			for (int j = 0; j < st.sessions[i].disq; j++)
			{
				file >> st.sessions[i].alldisc[j].name >> st.sessions[i].alldisc[j].mark;
			}
		}
	}
	return st;
}

void menu::StartMenu()
{	
	int flag = 1;
	while (flag)
	{
		short int input;
		while (true)
		{
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|1.���� ���������� � ��������                                       |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|2.����� ���������� � �������� (����� �� ��������������� ������)    |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|3.��������� ������ � ��������                                      |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|4.�������� ���������� � ��������                                   |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|5.'�������������� �������'                                         |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|6.���������� ������                                                |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "��� ������ �������(1 - 6): ";
			cin >> input;
			if (input < 7 && input>0) { system("cls"); break; }
			else { system("cls"); cout << "������� �������� �������� " << endl;}
		}
		switch (input)
		{
		case 1:
			menu::FirstOption();
			break;
		case 2:
			menu::SecondOption();
			break;
		case 6: flag = 0; system("cls"); cout << "���������� ������"; break;
		}
	}
}

void menu::FirstOption()
{
	student currentstudent;
	currentstudent.GetInfo();
	currentstudent.WriteDown();
}

void menu::SecondOption()
{
	student tmpst;
	char ID[8];
	cout << "������� �������������� ����� ��������: ";
	cin >> ID;
	ifstream file;
	int flag = 0;
	file.open("db.bin", ios::in && ios::binary);
	while (!flag)
	{
		if (file.eof()) break;
		tmpst = GetInfo(file);
		if (!(strcmp(ID, tmpst.ID))) { flag = 1; tmpst.PrintInfo(); break; }
	}
	if (!flag) { cout << "������ �������� �� ����������" << endl; }
	file.close();
}
//��������� ������ ���������� 22 10 2004 �� ��-1 ����-04-22 0829 � 1 1 �� 5 ���� ���� ���������� 22 10 2004 �� ��-1 ����-04-22 0830 � 1 1 �� 5 ����� ���� ������� 2 12 2004 �� �� ��-5-21 22�071 � 1 1 �� 5  