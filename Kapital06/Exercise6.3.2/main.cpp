/** @mainpage
*
* Praktikum Informatik 1 MMXVIII
* Versuch 5: Dynamische Datenstrukturen
*
*
*/

/**
* @file main.cpp
*
* content: main routine
*/

#include <iostream>
#include <string>

#include "Student.h"
#include <vector>

#include <conio.h>
using namespace std;

int main()
{


	////Begin : Mahdi section 01

	//vector<Student> testVec;

	//	Student s = Student(1, "Nika", "1376", "ponttor");
	//	testVec.push_back(s);
	//	s = Student(2, "Mina", "1370", "Turmstasse 01");
	//	testVec.push_back(s);
	//	s = Student(3, "Mahdi", "1366", "Am Weissenberg");
	//	testVec.push_back(s);
	//	s = Student(4, "Emad", "1369", "Kawo 2");
	//	testVec.push_back(s);
	//	s = Student(5, "Danial", "1370", "Turm");
	//	testVec.push_back(s);

	//	testVec.pop_back();

	//	vector<Student>::reverse_iterator it;

	//	for (it = testVec.rbegin(); it != testVec.rend(); it++)
	//	{
	//		cout << it->getMatNr() << endl;
	//		//These two are equal:
	//		//cout << (*it).getMatNr() << endl;
	//	}

	////End: Mahdi section 01



	std::vector<Student> testList;
	Student student;

	char abfrage;
	std::cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
	std::cin >> abfrage;

	if (abfrage != 'j')
	{
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		testList.push_back(student);
		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
		testList.push_back(student);
		student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
		testList.push_back(student);
		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
		testList.push_back(student);
		student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wuellnerstr.9");
		testList.push_back(student);
		
	}

	do
	{
		cout << "\nMenue:" << endl
			<< "-----------------------------" << endl
			<< "(1): Datenelement hinzufuegen" << endl
			<< "(2): Datenelement abhaengen" << endl
			<< "(3): Datenbank ausgeben" << endl
			<< "(4): Print Backward" << endl
			<< "(5): Delete student by using matriculation number" << endl
			<< "(6): Add a student at the beginning" << endl
			<< "(7): Beenden" << endl;
		cout.flush();
		cin >> abfrage;

		switch (abfrage)
		{
		case '1':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string dateOfBirth = "";
			std::string address = "";

			std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
			std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
			getline(std::cin, name);    // get entire line, including whitespace
			std::cout << "Geburtsdatum: ";
			getline(std::cin, dateOfBirth);
			std::cout << "Adresse: ";
			getline(std::cin, address);
			std::cout << "Matrikelnummer: ";
			std::cin >> matNr;

			student = Student(matNr, name, dateOfBirth, address);

			testList.push_back(student);
		}
		break;
		case '2':
		{

			if (testList.size() != 0 )
			{
				vector<Student>::const_reverse_iterator it2 = testList.rbegin();
				Student delElem = Student(it2->getMatNr(), it2->getName(), it2->getDateOfBirth(), it2->getAddress());

				std::cout << "Das letzte Datenelemt wird entfernt\n";
				delElem.print();

				testList.pop_back();
			}
			else
			{
				std::cout << "Die Liste/Der Vektor ist leer!\n";
			}
		}
		break;

		case '3':
		{
			std::cout << "Inhalt der Liste:\n";

				vector<Student>::const_iterator it;

				for (it = testList.begin(); it != testList.end(); it++)
				{
					it->print();
				}
		}
			break;
		case '4':
		{
			cout << "Print Backward:\n";

			vector<Student>::const_reverse_iterator it2;

			for (it2 = testList.rbegin(); it2 != testList.rend(); it2++)
			{
				it2->print();
			}

		}
			break;
		case '5':
		{
			int desired_mat = -1;
			Student delStd = Student();
			bool success = false;
			cout << "Please input the matriculation number: ";
			cin >> desired_mat;

			vector<Student>::const_iterator it3;
			for (it3 = testList.begin(); it3!=testList.end();it3++)
			{
				if (it3->getMatNr() == desired_mat)
				{
					delStd = Student(it3->getMatNr(), it3->getName(), it3->getDateOfBirth(), it3->getAddress());
					success = true;
					testList.erase(it3);
					break;
				}
			}
			
			if (success == true)
			{
				cout << "The following user has been deleted: \n";
				delStd.print();
			}
			else
			{
				cout << "There is no student with this matriculation number \n";
			}
		}
		break;
		case '6':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string dateOfBirth = "";
			std::string address = "";

			std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
			std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
			getline(std::cin, name);    // get entire line, including whitespace
			std::cout << "Geburtsdatum: ";
			getline(std::cin, dateOfBirth);
			std::cout << "Adresse: ";
			getline(std::cin, address);
			std::cout << "Matrikelnummer: ";
			std::cin >> matNr;

			student = Student(matNr, name, dateOfBirth, address);

			vector<Student>::const_iterator it4 = testList.begin();

			testList.insert(it4, student);

		}
		break;

		case '7':
			std::cout << "Das Programm wird nun beendet";
			break;

		default:
			std::cout << "Falsche Eingabe, bitte nochmal";
			break;
		}
	} while (abfrage != '7');

	_getch();
	return 0;
}