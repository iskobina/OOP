#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include "Proc.h"
#include "OOP.h"
<<<<<<< HEAD
#include "Functional.h"
=======
#include <ctime>
>>>>>>> lab2.2

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
	case 3:
		language = new Functional;
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
	fin >> reference;
}

void Skobina::Language::Output(ofstream& fout)
{
<<<<<<< HEAD
	fout << "Year of development = " << year_of_development << endl;
}

<<<<<<< HEAD
int Skobina::Language::Past_Years()
{
	time_t now = time(NULL);
	tm* localtm = localtime(&now);
	return 1900 + localtm->tm_year - year_of_development;
}

bool Skobina::Language::Compare(Language& second)
{
	return Past_Years() < second.Past_Years();
=======
	fout << "Year of development = " << year_of_development
		<< ", The number of references of this language on the Internet = " << reference << endl;
>>>>>>> lab2.3
=======
void Skobina::Language::Only_Procedural(ofstream& fout)
{
	fout << endl;
>>>>>>> lab2.5
}