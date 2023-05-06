#include "menu.h"
#include <fstream>
#include <stdio.h>
#include "student.h"
#include "Node.h"
#include "CRYPT.h"
using namespace std;

void menu::StartMenu()
{
	//Decrypt();
	int flag = 1;
	while (flag)
	{
		system("cls");
		short int input;
		while (true)
		{
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|1.���� ���������� � ��������                                       |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|2.����� ���������� � �������� (����� �� ��������������� ������)    |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|3.����� ���� ���������                                             |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|4.��������� ������ � ��������                                      |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|5.�������� ���������� � ��������                                   |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|6.����� ��������� �� ���������                                     |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|7.���������� ������                                                |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "��� ������ �������(1 - 7): ";
			cin >> input;
			if (!cin.fail())
			{
				if (input < 8 && input>0) { system("cls"); break; }
				else { system("cls"); cout << "������� �������� �������� " << endl; }
			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "������� �������� �������� " << endl;
				system("pause");
				system("cls");
			}
		}
		switch (input)
		{
		case 1:
			menu::FirstOption();
			break;
		case 2:
			menu::SecondOption();
			break;
		case 3:
			menu::ThirdOption();
			break;
		case 4:
			menu::FourthOption();
			break;
		case 5:
			menu::FifthOption();
			break;
		case 6:
			menu::SixthOption();
			break;
		case 7: flag = 0;  cout << "���������� ������" << endl; system("cls"); break;
		}
	}
	//Crypt();
	remove("buf.bin");
	system("cls");
}

void menu::FirstOption()
{
	student currentstudent, cmp;
	if (currentstudent.GetInfo())  currentstudent.WriteDown();
}

void menu::SecondOption()
{
	char ID[8];
	cout << "������� �������������� ����� ��������: ";
	cin >> ID;
	student tmpst;
	ifstream file;
	tmpst = student::FindStudent(ID, "db.bin");
	if (tmpst.Check()) { tmpst.PrintInfo(); }
	else cout << "������ �������� ��� � ���� " << endl;
	system("pause");
	system("cls");
}

void menu::ThirdOption()
{
	student tmp;
	ifstream file;
	file.open("db.bin", ios::binary);
	if (tmp.ExtractFile(file)) student::PrintAll("db.bin");
	file.close();
}

void menu::FourthOption()
{
	ofstream copy;
	copy.open("buf.bin", ios::trunc | ios::out);
	copy.close();
	char ID[8];
	cout << "������� �������������� ����� ��������: ";
	cin >> ID;
	student tmpst;
	tmpst = student::FindStudent(ID, "db.bin");
	if (tmpst.Check())
	{
		tmpst.ChangeInfo();
		copy.open("db.bin", ios::trunc);
		copy.close();
		tmpst.WriteDown("buf.bin");
	}
	else { cout << "������ �������� ��� � ���� " << endl; system("pause"); }
	student::CopyFile("buf.bin", "db.bin");
	system("cls");
}

void menu::FifthOption()
{
	ofstream copy;
	char ID[8];
	copy.open("buf.bin", ios::trunc | ios::out);
	copy.close();
	cout << "������� �������������� ����� ��������: ";
	cin >> ID;
	student tmpst;
	tmpst = student::FindStudent(ID, "db.bin");
	if (tmpst.Check())
	{
		char answer;
		cout << "������� ��������(Y/N)?" << endl;
		tmpst.PrintFIO();
		cin >> answer;
		switch (answer)
		{
		case 'Y':
			student::CopyFile("buf.bin", "db.bin");
			system("cls");
			break;
		case 'N':
			system("cls");
			break;
		}
	}
	else { cout << "������ �������� ��� � ���� " << endl; system("pause"); system("cls"); }
}

void menu::SixthOption()
{
	system("cls");
	List StudentList1;
	ifstream file;
	file.open("db.bin", ios::binary);
	student tmpst;
	int option1, option2;
	int* tmparr;
	bool flag = true;
	while (flag)
	{
		cout << "�� ����� ���������� ��������� ������� ��������:" << endl;
		cout << "1. �� ��� ����� �������� ��� �� ����� ������ 3" << endl;
		cout << "2. �� ��� ����� �������� ��� �� ����� ������ 3 � 4" << endl;
		cout << "3. �� ��� ����� �������� ��� �� ����� ������ 5" << endl;
		cout << "4. �����" << endl;
		cout << "��� �����: ";
		cin >> option2;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "�� ����� ������������ ����������" << endl;
		}
		else if (option2 > 0 && option2 < 5)
		{
			flag = false;
		}
	}
	system("cls");
	flag = true;
	while (flag)
	{
		cout << "������� ������� ������� �� ���� ���������? (1 - �/2 - �/3 - �� �����): ";
		cin >> option1;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "�� ����� ������������ ����������" << endl;
		}
		else if (option1 > 0 && option1 < 4)
		{
			flag = false;
		}
	}
	flag = true;
	switch (option1)
	{
		case 1:
		{
			while (tmpst.ExtractFile(file))
			{
				if (tmpst.ReturnGender() == '�') StudentList1.Add(tmpst);
			}
			break;
		}
		case 2:
		{
			while (tmpst.ExtractFile(file))
			{
				if (tmpst.ReturnGender() == '�') StudentList1.Add(tmpst);
			}
			break;
		}
		case 3:
		{
			while (tmpst.ExtractFile(file)) StudentList1.Add(tmpst);
			break;
		}
		case 4:
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		StudentList1.Print(option2);
	}
	else system("cls");		
	StudentList1.Clear();
}
