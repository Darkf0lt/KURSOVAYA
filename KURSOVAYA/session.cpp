#include "session.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


void session::GetDisc()
{
	while (true)
	{
		cout << "Введите кол-во пердметов: ";
		cin >> disq;
		if (!cin.fail())
		{
			if (!(disq < 1 || disq>10))
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
	alldisc = (disciplineinfo*)new disciplineinfo[disq];
	for (int i = 0; i < disq; i++)
	{
		cout << "Введите название " << i + 1 << " дисциплины: ";
		cin >> alldisc[i].name;
		while (true)
		{
			cout << "Введите оценку: ";
			cin >> alldisc[i].mark;
			if (!cin.fail())
			{
				if (!(alldisc[i].mark > 5 || alldisc[i].mark < 1))
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
	}
}
