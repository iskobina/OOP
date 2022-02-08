#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	class LinkedList
	{
		struct Node //��������� ���� � ������� ������
		{
			Language* language;
			Node* Next;
			Node* Prev;
		};
	public:
		LinkedList(); //�����������
		~LinkedList(); //����������

		void LinkedList_Input(ifstream& fin);
		void LinkedList_Output(ofstream& fout);
	private:
		Node* First;
		Node* Last;
		size_t SizeList;
	};
}

#endif