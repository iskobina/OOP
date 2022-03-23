#include "OOP.h"

void Skobina::Object_oriented::Input(ifstream& fin) //метод чтения данных из файла
{
	Skobina::Language::Input(fin); //получили "год"
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		number = Object_oriented::inheritance::SINGLE;
		break;
	case 2:
		number = Object_oriented::inheritance::MULTIPLE;
		break;
	case 3:
		number = Object_oriented::inheritance::INTERFACE;
		break;
	default:
		break;
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

void Skobina::Object_oriented::Multi_Method(Language* other, ofstream& fout)
{
	other->Multi_Method_OOP(fout);
}

void Skobina::Object_oriented::Multi_Method_OOP(ofstream& fout)
{
	fout << "OOP and OOP." << endl;
}

void Skobina::Object_oriented::Multi_Method_Proc(ofstream& fout)
{
	fout << "Procedural and OOP." << endl;
}