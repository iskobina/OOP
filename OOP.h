#pragma once
#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Skobina
{
	class Object_oriented : public Language //класс является потомком "Языка"
	{
	public:
		Object_oriented() {/**/ } //пустой конструктор по умолчанию
		bool Input(ifstream& fin); //метод класса
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