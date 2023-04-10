#pragma once
#include "student.h"
#include <fstream>
#include <iostream>
using namespace std;
class menu
{
	
	student GetInfo(ifstream &file);
	void FirstOption();
	void SecondOption();
public:
	void StartMenu();
	
};

