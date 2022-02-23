#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "Language.h"

namespace Skobina
{
	class Functional : public Language
	{
	public:
		Functional() {/**/ } // пустой конструктор

		bool Input(ifstream& fin);
		void Output(ofstream& fout);

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