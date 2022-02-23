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
	if (!fin.is_open())
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	ofstream fout(argv[2]);
	if (!fin.is_open())
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	LinkedList list;
	list.LinkedList_Input(fin); //�������� �������� ������ � ��� ����������
	fout << "Filled container." << endl;
	list.LinkedList_Output(fout); //����� � ����

	fout << endl << "Sorted Linked List." << endl;
	list.Sort_List(); //��������� ������
	list.LinkedList_Output(fout); //������� � ���� ������������� ������

	list.Only_Procedural(fout); //����� ����� �������������� ������

	list.~LinkedList(); //������� ����������
	fout << "Empty container." << endl;
	list.LinkedList_Output(fout); //�����

	cout << "Stop" << endl;
	return 0;
}