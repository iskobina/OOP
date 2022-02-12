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
		fout << "The number of years that have passed since the year the language was created = "
			<< Temp->language->Past_Years() << endl << endl;
		Temp = Temp->Next;
	}
}