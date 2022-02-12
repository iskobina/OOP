#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include "Proc.h"
#include "OOP.h"
#include <ctime>

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

int Skobina::Language::Past_Years()
{
	time_t now = time(NULL);
	tm* localtm = localtime(&now);
	return 1900 + localtm->tm_year - year_of_development;
}