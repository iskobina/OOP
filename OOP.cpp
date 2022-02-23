#include "OOP.h"
#include <string>

bool Skobina::Object_Oriented::Input(ifstream& fin)
{
	if (!Skobina::Language::Input(fin)) // проверка на корректность общих данных
	{
		return false;
	}

	string temp;
	fin >> temp;
	if (temp == "\0") // проверка на конец строки
	{
		return false;
	}
	if (temp.length() > 1) // проверка на длину строки
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front())))) // проверка на ввод цифры
	{
		return false;
	}

	int state = stoi(temp);

	getline(fin, temp, '\n'); // пропуск оставшихся данных

	switch (state)
	{
	case 1:
		number = Object_Oriented::inheritance::SINGLE;
		return true;
	case 2:
		number = Object_Oriented::inheritance::MULTIPLE;
		return true;
	case 3:
		number = Object_Oriented::inheritance::INTERFACE;
		return true;
	default:
		return false;
	}
}

void Skobina::Object_Oriented::Output(ofstream& fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (number)
	{
	case Object_Oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_Oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_Oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
	Skobina::Language::Output(fout);
}