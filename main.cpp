#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Skobina;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	cout << "Start" << endl;

	LinkedList list;
	list.LinkedList_Input(fin); //�������� �������� ������ � ��� ����������
	fout << "Filled container." << endl;
	list.LinkedList_Output(fout); //����� � ����

<<<<<<< HEAD
	fout << endl << "Sorted Linked List." << endl;
	list.Sort_List(); //��������� ������
	list.LinkedList_Output(fout); //������� � ���� ������������� �������
=======
	list.Only_Procedural(fout); //����� ����� �������������� ������
>>>>>>> lab2.5

	list.~LinkedList(); //������� ����������
	fout << "Empty container." << endl;
	list.LinkedList_Output(fout); //�����

	cout << "Stop" << endl;
	return 0;
}