#pragma once
#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Skobina
{
	class Object_oriented : public Language //����� �������� �������� "�����"
	{
	public:
		Object_oriented() {/**/ } //������ ����������� �� ���������
		void Input(ifstream& fin); //����� ������
		void Output(ofstream& fout);

		virtual void Multi_Method(Language* other, ofstream& fout);
		virtual void Multi_Method_Proc(ofstream& fout);
		virtual void Multi_Method_OOP(ofstream& fout);
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