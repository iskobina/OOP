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
		bool Input(ifstream& fin);
		void Output(ofstream& fout);

		void Only_Procedural(ofstream& fout);
	private:
		bool abstract_type;
	};
}

#endif