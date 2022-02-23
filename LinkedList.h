#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	class Linked_List
	{
		struct Node
		{
			Language* language; // структура узла в связном списке
			Node* next;
			Node* prev;
		};
	public:
		Linked_List(); // конструктор
		~Linked_List(); // деструктор

		void Linked_List_Input(ifstream& fin);
		void Linked_List_Output(ofstream& fout);
		void Only_Procedural(ofstream& fout);

		void Sort_List(); // метод сортировки списка
	private:
		Node* head;
		Node* tail;
		size_t size_list;

		void Swap(Node* first, Node* second); // вспомогательный метод сортировки списка
	};
}

#endif