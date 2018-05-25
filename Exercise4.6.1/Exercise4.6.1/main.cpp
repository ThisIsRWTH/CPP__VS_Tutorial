//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 04: Einf�hrung in die Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/**
* @file main.cpp
*
* Uses the Vector class to calculate the optical range to the horizon of earth
*/

/**
* @mainpage
*
* Praktikum Informatik 1@n
* Versuch 4: Einf�hrung in Klassen
*
*/
#include <iostream>
#include <conio.h>
#include "Vector.h"
#include <cmath>
#include <iomanip>
using namespace std;

//! A preprocessor definition of pi
#define PI 3.1415927

/*!
* @brief The main routine function
*/
int main()
{
	//Vector* earth = new Vector(0, 6371, 0);
	//Vector* person = Vector::add(earth, new Vector(0, 0.0018, 0));
	//Vector* sight = earth->substract(person);
	//double rad = 0, grd = 0, sightlength = 0;
	//while (!Vector::isOrthogonal(sight, earth))
	//{
	//	earth->rotateOnZAxis(rad); //Die iteration um diesen kleinen Winkel ist n�tig, da die Orthogonalit�t nicht pr�zise genug erreicht wird.
	//	rad += 0.0000001;
	//	sight = earth->substract(person);
	//	sightlength = sight->getLength();
	//}
	//grd = rad * 180 / PI;
	//std::cout << "Winkel: " << grd << "[grd] Sichtweite: " << sightlength << "km" << std::endl;

	vector v1 = vector(1,0,0);
	vector v2 = vector(0, -1, 0);
	cout << v1.anglebetweenvector(&v2);
	float f = 0.123456789;

	cout << "\nset precision: ";
	cout << fixed << setprecision(6) << f;
	_getch();
	return 0;

}
