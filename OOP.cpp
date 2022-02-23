#include "OOP.h"
#include <string>

bool Skobina::Object_Oriented::Input(ifstream& fin)
{
	if (!Skobina::Language::Input(fin)) // �������� �� ������������ ����� ������
	{
		return false;
	}

	string TempString;

	fin >> TempString;
	if (TempString == "\0") // �������� �� ����� ������
	{
		return false;
	}
	if (TempString.length() > 1) // �������� �� ����� ������
	{
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // �������� �� ���� �����
	{
		return false;
	}
	int state = stoi(TempString);
	getline(fin, TempString, '\n'); // ������� ���������� ������

	switch (state)
	{
	case 1:
		Number = Object_Oriented::Inheritance::SINGLE;
		return true;
	case 2:
		Number = Object_Oriented::Inheritance::MULTIPLE;
		return true;
	case 3:
		Number = Object_Oriented::Inheritance::INTERFACE;
		return true;
	default:
		return false;
	}
}


void Skobina::Object_Oriented::Output(ofstream& fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (Number)
	{
	case Object_Oriented::Inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_Oriented::Inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_Oriented::Inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}

	Skobina::Language::Output(fout);
}