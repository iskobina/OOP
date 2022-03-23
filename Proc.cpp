#include "Proc.h"
#include <string>

bool Skobina::Procedural::Input(ifstream& FileInput)
{
	if (!Skobina::Language::Input(FileInput)) // �������� �� ������������ ����� ������
	{
		return false;
	}

	string TempString;

	FileInput >> TempString;
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
	int State = stoi(TempString);
	getline(FileInput, TempString, '\n'); // ������� ���������� ������

	if (State > 0)
	{
		AbstractType = true;
	}
	else
	{
		AbstractType = false;
	}
	return true;
}


void Skobina::Procedural::Output(ofstream& FileOutput)
{
	FileOutput << "It is Procedural programming language: Abstract data types is ";
	if (AbstractType)
	{
		FileOutput << "present, ";
	}
	else
	{
		FileOutput << "missing, ";
	}

	Skobina::Language::Output(FileOutput);
}


void Skobina::Procedural::Output_Only_Procedural(ofstream& FileOutput)
{
	Skobina::Procedural::Output(FileOutput);
}


void Skobina::Procedural::Multi_Method(Language* Other, ofstream& FileOutput)
{
	Other->Multi_Method_First_Obj_Procedural(FileOutput);
}


void Skobina::Procedural::Multi_Method_First_Obj_Procedural(ofstream& FileOutput)
{
	FileOutput << "Procedural and Procedural." << endl;
}


void Skobina::Procedural::Multi_Method_First_Obj_OOP(ofstream& FileOutput)
{
	FileOutput << "OOP and Procedural." << endl;
}


void Skobina::Procedural::Multi_Method_First_Obj_Functional(ofstream& FileOutput)
{
	FileOutput << "Functional and Procedural." << endl;
}