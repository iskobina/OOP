#include "Functional.h"
#include <string>

bool Skobina::Functional::Input(ifstream& fin)
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
		getline(fin, temp, '\n'); // пропуск оставшихся данных
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front())))) // проверка на ввод цифры
	{
		getline(fin, temp, '\n'); // пропуск оставшихся данных
		return false;
	}

	int state = stoi(temp);
	if (state > 0)
	{
		lazy_calculations = true;
	}
	else
	{
		lazy_calculations = false;
	}

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

	state = stoi(temp);

	getline(fin, temp, '\n'); // пропуск оставшихся данных

	switch (state)
	{
	case 1:
		type = Functional::typification::STRICT;
		return true;
	case 2:
		type = Functional::typification::DYNAMIC;
		return true;
	default:
		return false;
	}
}

void Skobina::Functional::Output(ofstream& fout)
{
	fout << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (lazy_calculations)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	fout << "Typification is ";
	switch (type)
	{
	case Functional::typification::STRICT:
		fout << "strict, ";
		break;
	case Functional::typification::DYNAMIC:
		fout << "dynamic, ";
		break;
	default:
		break;
	}
	Skobina::Language::Output(fout);
}