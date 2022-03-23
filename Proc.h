#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include "Language.h"

namespace Skobina
{
	class Procedural : public Language
	{
	public:
		Procedural() {/**/ } // конструктор по умолчанию

		bool Input(ifstream& FileInput);
		void Output(ofstream& FileOutput);
		void Output_Only_Procedural(ofstream& FileOutput);

		virtual void Multi_Method(Language* Other, ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_Procedural(ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_OOP(ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_Functional(ofstream& FileOutput);

	private:
		bool AbstractType;
	};
}

#endif