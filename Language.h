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
		Language() {/**/ } // пустой конструктор
	public:
		static Language* Language_Input(ifstream& fin); // метод получения данных об объекте
		virtual void Input(ifstream& fin); // метод чтения "год"
		virtual void Output(ofstream& fout); // метод записи "год"

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