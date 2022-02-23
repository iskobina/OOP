#include "Functional.h"
#include <string>

bool Skobina::Functional::Input(ifstream& fin)
{
	if (!Skobina::Language::Input(fin)) // �������� �� ������������ ����� ������
	{
		return false;
	}

	string temp;
	fin >> temp;
	if (temp == "\0") // �������� �� ����� ������
	{
		return false;
	}
	if (temp.length() > 1) // �������� �� ����� ������
	{
		getline(fin, temp, '\n'); // ������� ���������� ������
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front())))) // �������� �� ���� �����
	{
		getline(fin, temp, '\n'); // ������� ���������� ������
		return false;
	}

	int state = stoi(temp);
	if (state > 0)
	{
		LazyCalculations = true;
	}
	else
	{
		LazyCalculations = false;
	}

	fin >> temp;
	if (temp == "\0") // �������� �� ����� ������
	{
		return false;
	}
	if (temp.length() > 1) // �������� �� ����� ������
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front())))) // �������� �� ���� �����
	{
		return false;
	}

	state = stoi(temp);

	getline(fin, temp, '\n'); // ������� ���������� ������

	switch (state)
	{
	case 1:
		Type = Functional::Typification::STRICT;
		return true;
	case 2:
		Type = Functional::Typification::DYNAMIC;
		return true;
	default:
		return false;
	}
}

void Skobina::Functional::Output(ofstream& fout)
{
	fout << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (LazyCalculations)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}

	fout << "Typification is ";
	switch (Type)
	{
	case Functional::Typification::STRICT:
		fout << "strict, ";
		break;
	case Functional::Typification::DYNAMIC:
		fout << "dynamic, ";
		break;
	default:
		break;
	}

	Skobina::Language::Output(fout);
}