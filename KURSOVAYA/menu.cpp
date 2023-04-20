#include "menu.h"
#include <fstream>
#include "student.h"
#include "Node.h"
using namespace std;

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
			cout << "|3.����� ���� ���������                                             |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|4.��������� ������ � ��������                                      |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|5.�������� ���������� � ��������                                   |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|6.'�������������� �������'                                         |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|7.���������� ������                                                |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "��� ������ �������(1 - 7): ";
			cin >> input;
			if (input < 8 && input>0) { system("cls"); break; }
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
		case 7: flag = 0; system("cls"); cout << "���������� ������"; break;
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
	char ID[8];
	cout << "������� �������������� ����� ��������: ";
	cin >> ID;
	student tmpst;
	ifstream file;
	tmpst = student::FindStudent(ID,"db.bin");
	if (tmpst.Check()) { tmpst.PrintInfo(); }
	else cout << "������ �������� ��� � ���� " << endl;
	system("pause");
	system("cls");
}

void menu::ThirdOption()
{
	student::PrintAll("db.bin");
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
	else{cout << "������ �������� ��� � ���� " << endl; system("pause");}
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
			student::CopyFile("buf.bin","db.bin");
			system("cls");
			break;
		case 'N':
			system("cls");
			break;
		}
	}
	else { cout << "������ �������� ��� � ���� " << endl; system("pause"); system("cls"); }
}

bool LookForArr(int k, int* arr,int start)
{
	for (int i = start; i < sizeof(arr); i++)
	{
		if (k == arr[i]) return true;
	}
	return false;
}

void menu::SixthOption()
{
	system("cls");
	List StudentList;
	ifstream file;
	student tmpst;
	int option;
	int* tmparr;
	cout << "�� ����� ���������� ��������� ������� ��������:" << endl;
	cout << "1. �� ��� ����� �������� ��� �� ����� ������ 3" << endl;
	cout << "2. �� ��� ����� �������� ��� �� ����� ������ 3 � 4" << endl;
	cout << "3. �� ��� ����� �������� ��� �� ����� ������ 5" << endl;
	cout << "��� �����: ";
	cin >> option;
	file.open("db.bin", ios::binary);
	switch (option)
	{
	case 1:
	{
		while (tmpst.ExtractFile(file))
			{
				tmparr = (int*) new int[tmpst.GetMarks()[0]];
				tmparr = tmpst.GetMarks();
				if (!LookForArr(3, tmparr,1))
				{
					StudentList.Add(tmpst);
				}
			}
			StudentList.Print();
			system("pause");
			system("cls");
			break;
	}

	case 2:
		{
			while (tmpst.ExtractFile(file))
			{
				tmparr = tmpst.GetMarks();
				if (!LookForArr(4, tmparr,1) && !LookForArr(3, tmparr,1))
				{
					StudentList.Add(tmpst);
				}
			}
			StudentList.Print();
			system("pause");
			system("cls");
			break;
		}
	case 3: 
		{
			while (tmpst.ExtractFile(file))
			{
				tmpst.ExtractFile(file);
				tmparr = tmpst.GetMarks();
				if (!LookForArr(5, tmparr,1))
				{
					StudentList.Add(tmpst);
				}
			}
			StudentList.Print();
			system("pause");
			system("cls");
			break;
			}
	}
	StudentList.Clear();
}


//������� 29. ����������� ���� ���������, � ������� �� ��� �����
//�������� ��� �� ����� ������
//�) 3;
//�) 3 � 4;
//�) 5.
//������������� ������������� ��� ������������� ����.�������� �) � �)
//���������� �� ������� ������������.
// 
// ����� ���� ������� 2 12 2004 �� �� ��-5-21 22�071 � 1 1 �� 5  