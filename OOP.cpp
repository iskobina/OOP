#include "OOP.h"
#include <string>

bool Skobina::Object_oriented::Input(ifstream& fin) //метод чтения данных из файла
{
	if (!Skobina::Language::Input(fin))
	{
		return false;
	}

	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() > 1)
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		return false;
	}

	int state = stoi(temp);
	switch (state)
	{
	case 1:
		number = Object_oriented::inheritance::SINGLE;
		return true;
	case 2:
		number = Object_oriented::inheritance::MULTIPLE;
		return true;
	case 3:
		number = Object_oriented::inheritance::INTERFACE;
		return true;
	default:
		return false;
	}
}

void Skobina::Object_oriented::Output(ofstream& fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (number)
	{
	case Object_oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
	Skobina::Language::Output(fout); //печатаем "год"
}