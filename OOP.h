#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Skobina
{
	class Object_Oriented : public Language
	{
	public:
		Object_Oriented() {/**/ } // конструктор по умолчанию

		bool Input(ifstream& FileInput);
		void Output(ofstream& FileOutput);

		virtual void Multi_Method(Language* Other, ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_Procedural(ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_OOP(ofstream& FileOutput);
		virtual void Multi_Method_First_Obj_Functional(ofstream& FileOutput);

	private:
		enum Inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} Number;
	};
}

#endif