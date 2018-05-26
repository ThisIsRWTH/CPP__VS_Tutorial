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
#include "List.h"
#include <conio.h>
using namespace std;

int main()
{
	////Begin : Mahdi section 01
	//	Student s1 = Student(1, "Nika", "1376", "ponttor");
	//	Student s2 = Student(2, "Mina", "1370", "Turmstasse 01");
	//	Student s3 = Student(3, "Mahdi", "1366", "Am Weissenberg");
	//	Student s4 = Student(4, "Emad", "1369", "Kawo 2");
	//	Student s5 = Student(5, "Danial", "1370", "Turm");

	//	//s1.print();
	//	//s2.print();


	//	List mylist = List();

	//	cout << "Print Empty List:"<<endl;
	//	mylist.print_forwards();

	//	mylist.enqueue_head(s1);
	//	cout << "Print The List with One Element:" << endl;
	//	mylist.print_forwards();
	//
	//	mylist.enqueue_head(s2);
	//	cout << "Print The List with Two Elements:" << endl;
	//	mylist.print_forwards();

	//	cout << "Print The List with Three Elements:" << endl;
	//	mylist.enqueue_head(s3);
	//	mylist.print_forwards();

	//	cout << "Print The List with Three Elements (Backward):" << endl;
	//	mylist.print_backward();

	//	//Adding 4th and 5th elements to the list.
	//	mylist.enqueue_head(s4);
	//	mylist.enqueue_head(s5);

	//	cout << "Print The List After Deleting Element with Mat. 2:\n\n" << endl;
	//	cout<< mylist.deleteElement(10);
	//	cout << "\n\n";
	//	cout << "Print The List in forward:" << endl;
	//	mylist.print_forwards();
	//	cout << "Print The List in backward:" << endl;
	//	mylist.print_backward();
	////End: Mahdi section 01

    List testList;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    if (abfrage != 'j')
    {
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		testList.enqueue_head(student);
		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
		testList.enqueue_head(student);
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	testList.enqueue_head(student);
		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
		testList.enqueue_head(student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
    	testList.enqueue_head(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinzufügen" << std::endl
                  << "(2): Datenelement abhängen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
			      << "(4): Print Backward" << std::endl
			      << "(5): Delete student by using matriculation number" << std::endl
			      << "(6): Add a student at the beginning" << std::endl
                  << "(7): Beenden" << std::endl;
        std::cin >> abfrage;

        switch (abfrage)
        {
            case '1':
				{
					unsigned int matNr = 0;
					std::string name = "";
					std::string dateOfBirth = "";
					std::string address = "";

					std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
					std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
					getline(std::cin, name);    // get entire line, including whitespace
					std::cout << "Geburtsdatum: ";
					getline(std::cin, dateOfBirth);
					std::cout << "Adresse: ";
					getline(std::cin, address);
					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;

					student = Student(matNr, name, dateOfBirth, address);

					testList.enqueue_tail(student);
				}
				break;
            case '2':
            	{
					Student delElem = Student();
					bool success = false;
					success = testList.dequeue(delElem);

					if(success)
					{
						std::cout << "Das letzte Datenelemt wird entfernt\n";
						delElem.print();
					}
					else
					{
						std::cout << "Die Liste ist leer!\n";
					}
            	}
                break;

            case '3':
                std::cout << "Inhalt der Liste:\n";
                testList.print_forwards();
                break;
			case '4':
				cout << "Print Backward:\n";
				testList.print_backward();
				break;
			case '5':
			{
				int desired_mat = -1;
				Student output = Student();
				bool success = false;
				cout << "Please input the matriculation number: ";
				cin >> desired_mat;

				success = testList.deleteElement(desired_mat, output);
				if (success == true)
				{
					cout << "The following user has been deleted: \n";
					output.print();
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

				std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
				std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
				getline(std::cin, name);    // get entire line, including whitespace
				std::cout << "Geburtsdatum: ";
				getline(std::cin, dateOfBirth);
				std::cout << "Adresse: ";
				getline(std::cin, address);
				std::cout << "Matrikelnummer: ";
				std::cin >> matNr;

				student = Student(matNr, name, dateOfBirth, address);

				testList.enqueue_head(student);
			}
			break;

            case '7':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '7');

	_getch();
    return 0;
}
