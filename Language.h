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
		virtual bool Input(ifstream& fin); // ����� ������
		virtual void Output(ofstream& fout); // ����� ������
		virtual void Only_Procedural(ofstream& fout); // ����� �������������� ������

		int Past_Years();
		bool Compare(Language& second);
	private:
		unsigned int year_of_development;
		unsigned long long int reference;
	};
}

#endif