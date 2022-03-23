#pragma once
#ifndef PROC_H
#define PROC_H

#include "Language.h"

namespace Skobina
{
	class Proc : public Language //класс наследует "язык"
	{
	public:
		Proc() {/**/ } //пустой конструктор
		void Input(ifstream& fin);
		void Output(ofstream& fout);

		virtual void Multi_Method(Language* other, ofstream& fout);
		virtual void Multi_Method_Proc(ofstream& fout);
		virtual void Multi_Method_OOP(ofstream& fout);
	private:
		bool abstract_type;
	};
}

#endif