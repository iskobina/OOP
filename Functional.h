#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "Language.h"

namespace Skobina
{
	class Functional : public Language
	{
	public:
		Functional() {/**/ } // конструктор по умолчанию

		bool Input(ifstream& FileInput);
		void Output(ofstream& FileOutput);

		virtual void Multi_Method(Language* Other, ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_Procedural(ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_OOP(ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_Functional(ofstream& FileOutput);

	private:
		bool LazyCalculations;
		enum Typification
		{
			STRICT,
			DYNAMIC
		} Type;
	};
}

#endif