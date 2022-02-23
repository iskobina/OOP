#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Skobina;

int main(int argc, char* argv[])
{
	if (argc != 3) // проверка на передачу в программу корректных параметров
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream fin(argv[1]);
	if (!fin.is_open()) // проверка на доступ к файлу
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	ofstream fout(argv[2]);
	if (!fout.is_open()) // проверка на доступ к файлу
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	Linked_List list;
	list.Linked_List_Input(fin); // создание связного списка и его заполнение
	fout << "Filled container." << endl;
	list.Linked_List_Output(fout); // вывод в файл

	fout << endl << "Sorted Linked List." << endl;
	list.Sort_List(); // сортировка списка
	list.Linked_List_Output(fout); // вывод в файл отсортированного списка

	list.Only_Procedural(fout); // фильтрованный вывод в файл

	list.~Linked_List(); // вызов деструктора
	fout << "Empty container." << endl;
	list.Linked_List_Output(fout);

	cout << "Stop" << endl;
	return 0;
}