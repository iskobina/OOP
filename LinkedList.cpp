#include "LinkedList.h"

Skobina::LinkedList::LinkedList() //����������� �� ���������
{
	First = NULL;
	Last = NULL;
	SizeList = 0;
}

Skobina::LinkedList::~LinkedList() //����������
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

		Temp->language = Language::Language_Input(fin); //��������� ������

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
	Node* Temp = First; //������� ��������� �� ������ �������
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

void Skobina::LinkedList::Sort_List() //����� �����������
{
	if (SizeList < 2) //����������� ������ �� 1 �������� ��� ������
		return;

	Node* current = First;

	bool flag = false;

	do
	{
		current = First;
		flag = false;
		for (size_t i = 0; i < (SizeList - 1); ++i)
		{
			if (current->language->Compare(*current->Next->language)) //���� ������� compare ���������� true (���� ���������� �������� �������)
			{
				Swap(current, current->Next); //�������� ������� � ��������� �������
				flag = true;
			}
			else
			{
				current = current->Next; //������� �� ��������� �������
			}
		}
	} while (flag);
}

void Skobina::LinkedList::Swap(Node* first, Node* second)
{
	if ((first->Prev == NULL) && (second->Next == NULL)) //���� ����� 2 �������� � ������
	{
		First = second;
		Last = first;
		first->Prev = second;
		second->Next = first;
		first->Next = NULL;
		second->Prev = NULL;
		return;
	}
	if ((first->Prev == NULL) && (second->Next != NULL)) //���� � ������ ����� 2-�� ���������, � �� ������������� 1 � 2 ��������
	{
		first->Next = second->Next;
		first->Prev = second;
		second->Next->Prev = first;
		second->Next = first;
		second->Prev = NULL;
		First = second;
		return;
	}
	if ((first->Prev != NULL) && (second->Next == NULL)) //���� � ������ ����� 2-�� ���������, � �� ������������� ������������� � ���������
	{
		second->Prev = first->Prev;
		first->Prev = second;
		first->Next = NULL;
		second->Next = first;
		second->Prev->Next = second;
		Last = first;
		return;
	}
	if ((first->Prev != NULL) && (second->Next != NULL)) //���� � ������ ����� 2-�� ��������� � �� ���-�� ��-��������
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