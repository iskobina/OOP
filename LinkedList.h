#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	class Linked_List
	{
		struct Node
		{
			Language* language; // ��������� ���� � ������� ������
			Node* next;
			Node* prev;
		};
	public:
		Linked_List(); // �����������
		~Linked_List(); // ����������

		void Linked_List_Input(ifstream& fin);
		void Linked_List_Output(ofstream& fout);
		void Only_Procedural(ofstream& fout);

		void Sort_List(); // ����� ���������� ������
	private:
		Node* head;
		Node* tail;
		size_t size_list;

		void Swap(Node* first, Node* second); // ��������������� ����� ���������� ������
	};
}

#endif