#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Skobina
{
	class Object_Oriented : public Language
	{
	public:
		Object_Oriented() {/**/ } // конструктор по умолчанию
		bool Input(ifstream& fin);
		void Output(ofstream& fout);
	private:
		enum inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} number;
	};
}

#endif