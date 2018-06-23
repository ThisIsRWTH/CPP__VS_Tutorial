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
#include<algorithm>

#include <conio.h>
using namespace std;

std::ostream&  operator<<(std::ostream& output, Student& p)
{
	output << "Mat: " << p.getMatNr() << " "
		<< "Name: " << p.getName() << " "
		<< "Birth: " << p.getDateOfBirth() << " "
		<< "Address: " << p.getAddress() << std::endl;
	return output;
}

int main()
{


	////Begin : Mahdi section 01

	

		Student s1 = Student(1, "Nika", "1376", "ponttor");
		Student s2 = Student(2, "Mina", "1370", "Turmstasse 01");
		Student s3 = Student(3, "Mahdi", "1366", "Am Weissenberg");
		Student s4 = Student(4, "Emad", "1369", "Kawo 2");
		Student s5 = Student(5, "Danial", "1370", "Turm");

		//because this operator is defined in the Student Class
		s1.operator<<(cout);

		// because this operator is defined in the Student Class.
		// This is equal to the above line.
		// The left-hand-side operand is sustituted with "this".
		// "this" has the same type of the class (Student).
		s1 << cout;



		// Because this operator is defined outside of the class.
		cout << s2;
		// These is equal to the above line.
		operator<<(cout, s2);

		cout << "\n\n\n";
		if (s1 < s2)
		{
			cout << "Student s1 is greater than Student s2";
		}

		cout << "\n";
		if (s3 > s2)
		{
			cout << "Student s3 is greater than Student s2";
		}

		cout << "\n";
		if (s1 == s1)
		{
			cout << "Student s1 is equal Student s1";
		}

		cout << endl <<"\n\nTesting STL-Algorithms:\n";

		vector<Student> testVec;
		vector<Student>::iterator it;
		testVec.push_back(s3);
		testVec.push_back(s2);
		testVec.push_back(s4);
		testVec.push_back(s1);
		testVec.push_back(s5);

		sort(testVec.begin(), testVec.end());

		for (it = testVec.begin();it!= testVec.end(); it++)
		{
			//cout << (*it).getAddress();
			//cout << it->getAddress();
			
			// Since we have overloaded the operator<< for Student class,
			// it is sufficient to just dereference the itertor to get the student.
			// Each Student object knows how to print itself to the output.
			cout << *it;
		}


	////End: Mahdi section 01


	_getch();
	return 0;
}