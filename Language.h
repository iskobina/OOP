#pragma once
#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <fstream>

using namespace std;

namespace Skobina
{
	class Language
	{
	protected:
		Language() {/**/ } // ������ �����������
	public:
		static Language* Language_Input(ifstream& fin); // ����� ��������� ������ �� �������
		virtual void Input(ifstream& fin); // ����� ������ "���"
		virtual void Output(ofstream& fout); // ����� ������ "���"

<<<<<<< HEAD
		int Past_Years();
		bool Compare(Language& second);
=======
		virtual void Only_Procedural(ofstream& fout);
>>>>>>> lab2.5
	private:
		unsigned short int year_of_development;
		int reference;
	};
}

#endif