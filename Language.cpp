#include "Language.h"
#include "Proc.h"
#include "OOP.h"

Skobina::Language* Skobina::Language::Language_Input(ifstream& fin)
{
	Language* language;
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		language = new Proc; 
		break;
	case 2:
		language = new Object_oriented;
		break;
	default:
		return 0;
	}
	language->Input(fin); //переопределенный input (либо input из Proc, либо input из OOP)
	return language;
}

void Skobina::Language::Input(ifstream& fin)
{
	fin >> year_of_development;
}

void Skobina::Language::Output(ofstream& fout)
{
	fout << "Year of development = " << year_of_development << endl;
}