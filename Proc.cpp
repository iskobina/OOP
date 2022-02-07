#include "Proc.h"

void Skobina::Proc::Input(ifstream& fin)
{
	Skobina::Language::Input(fin);
	fin >> abstract_type;
}

void Skobina::Proc::Output(ofstream& fout)
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