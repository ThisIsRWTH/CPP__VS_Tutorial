//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
// Versuch 04: Einführung in die Klasse
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
* Versuch 4: Einführung in Klassen
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
	//	earth->rotateOnZAxis(0.0000001); //Die iteration um diesen kleinen Winkel ist nötig, da die Orthogonalität nicht präzise genug erreicht wird.
	//	rad += 0.0000001;
	//	sight = earth->substract(person);
	//	sightlength = sight->getLength();
	//}
	//grd = rad * 180 / PI;
	//std::cout << "Winkel: " << grd << "[grd] Sichtweite: " << sightlength << "km" << std::endl;

	Vector v1 = Vector(1,0,0);
	Vector v2 = Vector(0, -1, 0);
	cout << v1.angleBetweenVector(&v2);
	float f = 0.123456789;

	cout << "\nSet Precision: ";
	cout << fixed << setprecision(6) << f;
	_getch();
	return 0;

}
