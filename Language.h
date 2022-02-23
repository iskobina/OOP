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
		virtual bool Input(ifstream& fin); // метод чтения
		virtual void Output(ofstream& fout); // метод записи
		virtual void Only_Procedural(ofstream& fout); // метод фильтрованного вывода

		int Past_Years();
		bool Compare(Language& second);
	private:
		unsigned int year_of_development;
		unsigned long long int reference;
	};
}

#endif