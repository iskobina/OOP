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
	list.LinkedList_Input(fin); //создание связного списка и его заполнение
	fout << "Filled container." << endl;
	list.LinkedList_Output(fout); //вывод в файл

	fout << endl << "Sorted Linked List." << endl;
	list.Sort_List(); //сортируем список
	list.LinkedList_Output(fout); //выводим в файл сортированный список

	list.Only_Procedural(fout); //вызов метод фильтрованного вывода

	list.~LinkedList(); //вызвали деструктор
	fout << "Empty container." << endl;
	list.LinkedList_Output(fout); //вывод

	cout << "Stop" << endl;
	return 0;
}