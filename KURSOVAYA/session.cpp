#include "session.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


void session::GetDisc()
{
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
		cout << "������� �������� " << i + 1 << " ����������: ";
		cin >> alldisc[i].name;
		while (true)
		{
			cout << "������� ������: ";
			cin >> alldisc[i].mark;
			if (!cin.fail())
			{
				if (!(alldisc[i].mark > 5 || alldisc[i].mark < 1))
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
}
