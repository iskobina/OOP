#pragma once
#ifndef PROC_H
#define PROC_H

#include "Language.h"

namespace Skobina
{
	class Proc : public Language
	{
	public:
		Proc() {/**/ }
		void Input(ifstream& fin);
		void Output(ofstream& fout);
	private:
		bool abstract_type;
	};
}

#endif