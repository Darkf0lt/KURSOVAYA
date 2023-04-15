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
			cout << "|1.Ввод информации о студенте                                       |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|2.Вывод информации о студенте (поиск по индивидуальному номеру)    |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|3.Изменение данных о студенте                                      |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|4.Удаление информации о студенте                                   |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|5.'индивидуальное задание'                                         |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|6.Завершение работы                                                |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "Что хотите сделать(1 - 6): ";
			cin >> input;
			if (input < 7 && input>0) { system("cls"); break; }
			else { system("cls"); cout << "Введено неверное значение " << endl;}
		}
		switch (input)
		{
		case 1:
			menu::FirstOption();
			break;
		case 2:
			menu::SecondOption();
			break;
		case 6: flag = 0; system("cls"); cout << "Завершение работы"; break;
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
	cout << "Введите индивидуальный номер студента: ";
	cin >> ID;*/
	student tmpst;
	tmpst.ExtractFile();
	tmpst.PrintInfo();
}
	
// Серик Иван Никитич 2 12 2004 РТ РТ РТ-5-21 22к071 М 1 1 ЯП 5  