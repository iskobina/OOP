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
	private:
		bool abstract_type;
	};
}

#endif