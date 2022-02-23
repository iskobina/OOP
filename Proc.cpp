#include "Proc.h"
#include <string>

bool Skobina::Procedural::Input(ifstream& fin)
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

	getline(fin, temp, '\n');

	if (state > 0)
	{
		abstract_type = true;
	}
	else
	{
		abstract_type = false;
	}
	return true;
}

void Skobina::Procedural::Output(ofstream& fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	Skobina::Language::Output(fout);
}

void Skobina::Procedural::Only_Procedural(ofstream& fout)
{
	Skobina::Procedural::Output(fout);
}