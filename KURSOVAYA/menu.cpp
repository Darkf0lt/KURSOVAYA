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
	student tmpst;
	char ID[8];
	cout << "Введите индивидуальный номер студента: ";
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
	if (!flag) { cout << "Такого студента не существует" << endl; }
	file.close();
}
//Жемерикин Максим Алексеевич 22 10 2004 ИБ КБ-1 БАСО-04-22 0829 М 1 1 ЯП 5 Линт Артём Дмитриевич 22 10 2004 Иб КБ-1 БАСО-04-22 0830 М 1 1 ЯП 5 Серик Иван Никитич 2 12 2004 РТ РТ РТ-5-21 22к071 М 1 1 ЯП 5  