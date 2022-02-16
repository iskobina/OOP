#include "Proc.h"

void Skobina::Proc::Input(ifstream& fin) //метод чтение из файла
{
	Skobina::Language::Input(fin); //считали "год"
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
	Skobina::Language::Output(fout); //записали "год"
}

void Skobina::Proc::Only_Procedural(ofstream& fout)
{
	Skobina::Proc::Output(fout);
}