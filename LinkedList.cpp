#include "LinkedList.h"

Skobina::LinkedList::LinkedList() //конструктор по умолчанию
{
	First = NULL;
	Last = NULL;
	SizeList = 0;
}

Skobina::LinkedList::~LinkedList() //деструктор
{
	Node* Temp = NULL;
	while (Last != NULL)
	{
		Temp = Last->Prev;
		delete Last;
		Last = Temp;
		--SizeList;
	}
	First = Temp;
}

void Skobina::LinkedList::LinkedList_Input(ifstream& fin)
{
	Node* Temp;
	while (!fin.eof())
	{
		Temp = new Node;

		Temp->Next = NULL;

		Temp->language = Language::Language_Input(fin); //заполняем данные

		++SizeList;

		if (First == NULL)
		{
			Temp->Prev = NULL;
			First = Last = Temp;
		}
		else
		{
			Temp->Prev = Last;
			Last->Next = Temp;
			Last = Temp;
		}
	}
}

void Skobina::LinkedList::LinkedList_Output(ofstream& fout)
{
	Node* Temp = First; //создаем указатель на первый элемент
	fout << "Container contains " << SizeList << " elements." << endl;

	for (size_t i = 0; i < SizeList; i++)
	{
		fout << i + 1 << ": ";
		Temp->language->Output(fout);
		Temp = Temp->Next;
	}
}

void Skobina::LinkedList::Multi_Method(ofstream& fout)
{
	Node* current_first = First;
	Node* current_second = current_first->Next;

	fout << "Multimethod." << endl;
	for (size_t i = 0; i < SizeList - 1; i++)
	{
		for (size_t j = i + 1; j < SizeList; j++)
		{
			current_first->language->Multi_Method(current_second->language, fout);
			current_first->language->Output(fout);
			current_second->language->Output(fout);
			current_second = current_second->Next;
		}
		current_first = current_first->Next;
		current_second = current_first->Next;
	}
}