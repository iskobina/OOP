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
		static Language* Language_Input(ifstream& FileInput); // метод получения данных об объекте
		virtual bool Input(ifstream& FileInput); // метод чтения
		virtual void Output(ofstream& FileOutput); // метод записи
		virtual void Output_Only_Procedural(ofstream& FileOutput); // метод фильтрованного вывода

		int Past_Years();
		bool Compare(Language& Second);

		virtual void Multi_Method(Language* Other, ofstream& FileOutput) = 0;
		virtual void Multi_Method_Procedural(ofstream& FileOutput) = 0;
		virtual void Multi_Method_OOP(ofstream& FileOutput) = 0;
		virtual void Multi_Method_Functional(ofstream& FileOutput) = 0;
	private:
		unsigned int YearOfDevelopment;
		unsigned long long int Reference;
	};
}

#endif