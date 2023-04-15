#include "menu.h"
#include <fstream>
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
	/*char ID[8];
	cout << "������� �������������� ����� ��������: ";
	cin >> ID;*/
	student tmpst;
	tmpst.ExtractFile();
	tmpst.PrintInfo();
}
	
// ����� ���� ������� 2 12 2004 �� �� ��-5-21 22�071 � 1 1 �� 5  