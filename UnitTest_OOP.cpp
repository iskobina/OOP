#include "pch.h"
#include "CppUnitTest.h"
#include "Proc.h"
#include "OOP.h"
#include "Functional.h"
#include "Language.h"
#include "LinkedList.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Skobina;

namespace UnitTestOOP
{
	TEST_CLASS(UnitTestOOP)
	{
	public:
		
		/*TEST_METHOD(TestMethod1)
		{
		}*/
		TEST_METHOD(ProceduralInput1) //1
		{
			ifstream fin("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inp1.txt");
			Proc actual;
			actual.Input(fin);
			Proc expected;
			expected.year_of_development = 1998;
			expected.reference = 123;
			expected.abstract_type = false;
			Assert::AreEqual(expected.year_of_development, actual.year_of_development);
			Assert::AreEqual(expected.reference, actual.reference);
			Assert::AreEqual(expected.abstract_type, actual.abstract_type);
		}
		TEST_METHOD(ProceduralOutput) //2
		{
			ofstream fout("outp.txt");
			Proc proc;
			proc.year_of_development = 1998;
			proc.reference = 123;
			proc.abstract_type = true;
			proc.Output(fout);
			fout.close();
			ifstream fin1("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inexp.txt");
			ifstream fin2("outp.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OOPInput) //3
		{
			ifstream fin("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\ino1.txt");
			Object_oriented actual;
			actual.Input(fin);
			Object_oriented expected;
			expected.year_of_development = 2000;
			expected.reference = 987;
			expected.number = Object_oriented::inheritance::MULTIPLE;
			Assert::AreEqual(expected.year_of_development, actual.year_of_development);
			Assert::AreEqual(expected.reference, actual.reference);
			Assert::AreEqual(int(expected.number), int(actual.number));
		}
		TEST_METHOD(OOPOutput) //4
		{
			ofstream fout("outo.txt");
			Object_oriented oop;
			oop.year_of_development = 2000;
			oop.reference = 987;
			oop.number = Object_oriented::inheritance::MULTIPLE;
			oop.Output(fout);
			fout.close();
			ifstream fin1("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inexo.txt");
			ifstream fin2("outo.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(FunctionalInput) //5
		{
			ifstream fin("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inf1.txt");
			Functional actual;
			actual.Input(fin);
			Functional expected;
			expected.year_of_development = 2000;
			expected.reference = 987;
			expected.lazy_calculations = true;
			expected.type = Functional::typification::DYNAMIC;
			Assert::AreEqual(expected.year_of_development, actual.year_of_development);
			Assert::AreEqual(expected.reference, actual.reference);
			Assert::AreEqual(expected.lazy_calculations, actual.lazy_calculations);
			Assert::AreEqual(int(expected.type), int(actual.type));
		}
		TEST_METHOD(FunctionalOutput) //6
		{
			ofstream fout("outf.txt");
			Functional func;
			func.year_of_development = 2000;
			func.reference = 987;
			func.lazy_calculations = false;
			func.type = Functional::typification::STRICT;
			func.Output(fout);
			fout.close();
			ifstream fin1("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inexf.txt");
			ifstream fin2("outf.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(PastYear) //7
		{
			Language lang;
			lang.year_of_development = 2017;
			int actual = lang.Past_Years();
			int expected = 2022 - lang.year_of_development;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompare) //8
		{
			Language first;
			Language second;
			first.year_of_development = 2000;
			second.year_of_development = 1000;
			bool actual = first.Compare(second);
			bool expected = true;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(ListOutput) //9
		{
			ifstream fin("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inlist1.txt");
			ofstream fout("outlist1.txt");
			LinkedList list;
			list.LinkedList_Input(fin);
			list.LinkedList_Output(fout);
			fout.close();
			fin.close();
			ifstream fin1("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inexlist1.txt");
			ifstream fin2("outlist1.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(ProceduralOnlyOutput) //10
		{
			ifstream fin("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inlist1.txt");
			ofstream fout("outlist2.txt");
			LinkedList list;
			list.LinkedList_Input(fin);
			list.Only_Procedural(fout);
			fout.close();
			fin.close();
			ifstream fin1("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inexlist2.txt");
			ifstream fin2("outlist2.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestSort) //11
		{
			ifstream fin("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inlist1.txt");
			ofstream fout("outlist3.txt");
			LinkedList list;
			list.LinkedList_Input(fin);
			list.Sort_List();
			list.LinkedList_Output(fout);
			fout.close();
			fin.close();
			ifstream fin1("C:\\Users\\iskob\\Desktop\\тех.прога\\UnitTest_OOP\\inexlist3.txt");
			ifstream fin2("outlist3.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
	};
}
