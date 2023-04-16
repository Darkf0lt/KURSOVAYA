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
			cout << "|3.Вывод всех студентов                                             |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|4.Изменение данных о студенте                                      |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|5.Удаление информации о студенте                                   |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|6.'индивидуальное задание'                                         |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "|7.Завершение работы                                                |" << endl;
			cout << "|-------------------------------------------------------------------|" << endl;
			cout << "Что хотите сделать(1 - 7): ";
			cin >> input;
			if (input < 8 && input>0) { system("cls"); break; }
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
		case 3:
			menu::ThirdOption();
			break;
		case 4:
			menu::FourthOption();
			break;
		case 5:
			menu::FifthOption();
			break;
		case 7: flag = 0; system("cls"); cout << "Завершение работы"; break;
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
	cout << "Введите индивидуальный номер студента: ";
	cin >> ID;
	student tmpst;
	ifstream file;
	bool flag = false;
	file.open("db.bin", ios::binary | ios::in);
	while (file.read((char*)&tmpst, sizeof(student)))
	{
		tmpst.sessions = (session*) new session[tmpst.sessionsq];
		file.read((char*)tmpst.sessions, sizeof(tmpst.sessions));
		for (int i = 0; i < tmpst.sessionsq; i++)
		{
			file.read((char*)&tmpst.sessions[i].disq, sizeof(int));
			tmpst.sessions[i].alldisc = (disciplineinfo*) new disciplineinfo[tmpst.sessions[i].disq];

			for (int j = 0; j < tmpst.sessions[i].disq; j++)
			{
				file.read((char*)&tmpst.sessions[i].alldisc[j].name, sizeof(tmpst.sessions[i].alldisc[j].name));
				file.read((char*)&tmpst.sessions[i].alldisc[j].mark, sizeof(tmpst.sessions[i].alldisc[j].mark));
			}
		}
		if (!(strcmp(tmpst.ID, ID)))
		{
			tmpst.PrintInfo();
			flag = true;
		}
	}
	if (!flag)
	{
		cout << "Такого студента нет в базе " << endl;
	}
	system("pause");
	system("cls");
}

void menu::ThirdOption()
{
	student tmpst;
	ifstream file;
	file.open("db.bin", ios::binary | ios::in);
	while (file.read((char*)&tmpst, sizeof(student)))
	{
		tmpst.sessions = (session*) new session[tmpst.sessionsq];
		file.read((char*)tmpst.sessions, sizeof(tmpst.sessions));
		for (int i = 0; i < tmpst.sessionsq; i++)
		{
			file.read((char*)&tmpst.sessions[i].disq, sizeof(int));
			tmpst.sessions[i].alldisc = (disciplineinfo*) new disciplineinfo[tmpst.sessions[i].disq];

			for (int j = 0; j < tmpst.sessions[i].disq; j++)
			{
				file.read((char*)&tmpst.sessions[i].alldisc[j].name, sizeof(tmpst.sessions[i].alldisc[j].name));
				file.read((char*)&tmpst.sessions[i].alldisc[j].mark, sizeof(tmpst.sessions[i].alldisc[j].mark));
			}
		}
		cout << "|----------------------------------------------------------------------------------------------|" << endl;
		tmpst.PrintInfo();
	}
	cout << "|----------------------------------------------------------------------------------------------|" << endl;
	system("pause");
	system("cls");
}

void menu::FourthOption()
{
	ifstream file;
	ofstream copy;
	copy.open("buf.bin", ios::trunc | ios::out);
	copy.close();
	char ID[8];
	cout << "Введите индивидуальный номер студента: ";
	cin >> ID;
	file.open("db.bin", ios::binary);
	student tmpst;
	bool flag = false;
	while (file.read((char*)&tmpst, sizeof(student)))
	{
		tmpst.sessions = (session*) new session[tmpst.sessionsq];
		file.read((char*)tmpst.sessions, sizeof(tmpst.sessions));
		for (int i = 0; i < tmpst.sessionsq; i++)
		{
			file.read((char*)&tmpst.sessions[i].disq, sizeof(int));
			tmpst.sessions[i].alldisc = (disciplineinfo*) new disciplineinfo[tmpst.sessions[i].disq];

			for (int j = 0; j < tmpst.sessions[i].disq; j++)
			{
				file.read((char*)&tmpst.sessions[i].alldisc[j].name, sizeof(tmpst.sessions[i].alldisc[j].name));
				file.read((char*)&tmpst.sessions[i].alldisc[j].mark, sizeof(tmpst.sessions[i].alldisc[j].mark));
			}
		}
		if (!(strcmp(tmpst.ID, ID)))
		{
			tmpst.ChangeInfo();
			flag = true;
		}
		tmpst.WriteDownBuf();
	}
	if (!flag)
	{
		cout << "Такого студента нет в базе " << endl;
	}
	system("cls");
	file.close();
	copy.open("db.bin", ios::trunc);
	file.close();
	file.open("buf.bin", ios::binary);
	while (file.read((char*)&tmpst, sizeof(student)))
	{
		tmpst.sessions = (session*) new session[tmpst.sessionsq];
		file.read((char*)tmpst.sessions, sizeof(tmpst.sessions));
		for (int i = 0; i < tmpst.sessionsq; i++)
		{
			file.read((char*)&tmpst.sessions[i].disq, sizeof(int));
			tmpst.sessions[i].alldisc = (disciplineinfo*) new disciplineinfo[tmpst.sessions[i].disq];

			for (int j = 0; j < tmpst.sessions[i].disq; j++)
			{
				file.read((char*)&tmpst.sessions[i].alldisc[j].name, sizeof(tmpst.sessions[i].alldisc[j].name));
				file.read((char*)&tmpst.sessions[i].alldisc[j].mark, sizeof(tmpst.sessions[i].alldisc[j].mark));
			}
		}
		tmpst.WriteDown();
	}
	copy.open("buf.bin", ios::trunc | ios::out);
	copy.close();
}

void menu::FifthOption()
{
	ifstream file;
	ofstream copy;
	char ID[8];
	copy.open("buf.bin", ios::trunc | ios::out);
	copy.close();
	cout << "Введите индивидуальный номер студента: ";
	cin >> ID;
	file.open("db.bin", ios::binary);
	student tmpst;
	bool flag = false;
	while (file.read((char*)&tmpst, sizeof(student)))
	{
		tmpst.sessions = (session*) new session[tmpst.sessionsq];
		file.read((char*)tmpst.sessions, sizeof(tmpst.sessions));
		for (int i = 0; i < tmpst.sessionsq; i++)
		{
			file.read((char*)&tmpst.sessions[i].disq, sizeof(int));
			tmpst.sessions[i].alldisc = (disciplineinfo*) new disciplineinfo[tmpst.sessions[i].disq];

			for (int j = 0; j < tmpst.sessions[i].disq; j++)
			{
				file.read((char*)&tmpst.sessions[i].alldisc[j].name, sizeof(tmpst.sessions[i].alldisc[j].name));
				file.read((char*)&tmpst.sessions[i].alldisc[j].mark, sizeof(tmpst.sessions[i].alldisc[j].mark));
			}
		}
		if (!(strcmp(tmpst.ID, ID)))
		{
			flag = true;
			char answer;
			cout << "Удалить студента '" << tmpst.fio.surename << " " << tmpst.fio.name << " " << tmpst.fio.lastname << "'(Y/N)?" << endl;
			cin >> answer;
			switch (answer)
			{
			case 'Y':
				break;
			case 'N':
				goto end;
			}
		}
		if ((strcmp(tmpst.ID, ID)))tmpst.WriteDownBuf();

		if (!flag)
		{
			cout << "Такого студента нет в базе " << endl;
			system("pause");
		}
	}

		system("cls");
		file.close();
		copy.open("db.bin", ios::trunc|ios::out);
		file.close();
		file.open("buf.bin", ios::binary);
		while (file.read((char*)&tmpst, sizeof(student)))
		{
			tmpst.sessions = (session*) new session[tmpst.sessionsq];
			file.read((char*)tmpst.sessions, sizeof(tmpst.sessions));
			for (int i = 0; i < tmpst.sessionsq; i++)
			{
				file.read((char*)&tmpst.sessions[i].disq, sizeof(int));
				tmpst.sessions[i].alldisc = (disciplineinfo*) new disciplineinfo[tmpst.sessions[i].disq];

				for (int j = 0; j < tmpst.sessions[i].disq; j++)
				{
					file.read((char*)&tmpst.sessions[i].alldisc[j].name, sizeof(tmpst.sessions[i].alldisc[j].name));
					file.read((char*)&tmpst.sessions[i].alldisc[j].mark, sizeof(tmpst.sessions[i].alldisc[j].mark));
				}
			}
			tmpst.WriteDown();
		}
	end:
		copy.open("buf.bin", ios::trunc|ios::out);
		copy.close();
}

// Серик Иван Никитич 2 12 2004 РТ РТ РТ-5-21 22к071 М 1 1 ЯП 5  