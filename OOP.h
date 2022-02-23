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
		bool Input(ifstream& fin); //����� ������
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