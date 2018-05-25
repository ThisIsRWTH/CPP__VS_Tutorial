//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einführung in die Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//
// Autor:  xxxxxx xxxxxx
// Matr.:  000000
// Datum:  21.04.2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Vektor.h"
#include <cmath>
#include<conio.h>

#define EARTH_RADIUS_KM 6370
const int EARTH_RADIUS_KM2 = 6370;

#define PLATFORM_HEIGHT_M 832
#define HUMAN_SIZE_M 1.8

#define ANGLE_INC 0.0000001
#define PI 3.14159265

int main()
{
	// Erdradius
	Vektor earth = Vektor(0, EARTH_RADIUS_KM, 0);

	// Sichthöhe Mensch
	Vektor human = earth.add(Vektor(0, (PLATFORM_HEIGHT_M + HUMAN_SIZE_M) / 1000, 0));

	// Sichtvektor soll Erde tangieren
	Vektor sight = earth.subtract(human);

	double rad = 0;
	long counter = 0;
	do
	{
		// Erhöhe Winkel langsam
		rad += ANGLE_INC;
		earth.rotate(ANGLE_INC);
		sight = earth.subtract(human);
		counter++;

	} while (!sight.isOrthogonal(earth)); // Prüfe orthogonalität

										  // Berechnen der Distanz als Zahlenwert
	double sight_dist = sight.getLength();
	double deg = rad * 180 / PI;

	std::cout << "Hoehe der Plattform: " << PLATFORM_HEIGHT_M + HUMAN_SIZE_M << "m" << std::endl;
	std::cout << "Sichtweite: " << sight_dist << "km" << std::endl;
	std::cout << "Winkel: " << deg << "°" << std::endl;
	std::cout << "Counter: " << counter << std::endl;
	



	_getch();
	return 0;
}

// E.O.F.
