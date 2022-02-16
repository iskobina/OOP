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

void Skobina::LinkedList::Sort_List() //метод ссортировки
{
	if (SizeList < 2) //сортировать список из 1 элемента нет смысла
		return;

	Node* current = First;

	bool flag = false;

	do
	{
		current = First;
		flag = false;
		for (size_t i = 0; i < (SizeList - 1); ++i)
		{
			if (current->language->Compare(*current->Next->language)) //если функция compare возвращает true (если необходимо поменять местами)
			{
				Swap(current, current->Next); //передаем текущий и следующий элемент
				flag = true;
			}
			else
			{
				current = current->Next; //переход на следующий элемент
			}
		}
	} while (flag);
}

void Skobina::LinkedList::Swap(Node* first, Node* second)
{
	if ((first->Prev == NULL) && (second->Next == NULL)) //если всего 2 элемента в списке
	{
		First = second;
		Last = first;
		first->Prev = second;
		second->Next = first;
		first->Next = NULL;
		second->Prev = NULL;
		return;
	}
	if ((first->Prev == NULL) && (second->Next != NULL)) //если в списке более 2-ух элементов, и мы рассматриваем 1 и 2 элементы
	{
		first->Next = second->Next;
		first->Prev = second;
		second->Next->Prev = first;
		second->Next = first;
		second->Prev = NULL;
		First = second;
		return;
	}
	if ((first->Prev != NULL) && (second->Next == NULL)) //если в списке более 2-ух элементов, и мы рассматриваем предпоследний и последний
	{
		second->Prev = first->Prev;
		first->Prev = second;
		first->Next = NULL;
		second->Next = first;
		second->Prev->Next = second;
		Last = first;
		return;
	}
	if ((first->Prev != NULL) && (second->Next != NULL)) //если в списке более 2-ух элементов и мы где-то по-середине
	{
		first->Next = second->Next;
		second->Prev = first->Prev;
		second->Next = first;
		first->Prev = second;
		second->Prev->Next = second;
		first->Next->Prev = first;
		return;
	}
}

void Skobina::LinkedList::Only_Procedural(ofstream& fout)
{
	Node* current = First;
	fout << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < SizeList; i++)
	{
		fout << i + 1 << ": ";
		current->language->Only_Procedural(fout);
		current = current->Next;
	}

	fout << endl;
}