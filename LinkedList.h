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

<<<<<<< HEAD
		void Sort_List(); //����� ����������
=======
		void Only_Procedural(ofstream& fout);
>>>>>>> lab2.5
	private:
		Node* First;
		Node* Last;
		size_t SizeList;

		void Swap(Node* first, Node* second);
	};
}

#endif