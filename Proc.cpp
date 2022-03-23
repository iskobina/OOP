#include "Proc.h"

void Skobina::Proc::Input(ifstream& fin) //����� ������ �� �����
{
	Skobina::Language::Input(fin); //������� "���"
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
	Skobina::Language::Output(fout); //�������� "���"
}

void Skobina::Proc::Multi_Method(Language* other, ofstream& fout)
{
	other->Multi_Method_First_Obj_Proc(fout);
}

void Skobina::Proc::Multi_Method_First_Obj_Proc(ofstream& fout)
{
	fout << "Procedural and Procedural." << endl;
}

void Skobina::Proc::Multi_Method_First_Obj_OOP(ofstream& fout)
{
	fout << "OOP and Procedural." << endl;
}