// mainapplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "vehicles.h"
#include "parts.h"

// Feladat: keszitsen programot jarmu park nyilvantartasahoz! Ehhez ket header file kell: vehicles.h es parts.h.
// A vehicles.h fajlban:
// Keszitsen egy absztrakt Jarmu (Vehicle) ososztalyt! Minden jarmunak legyen neve, es kellekeket tarolo vektora: std::vector<Parts*> tipusu "parts" nevu vektor
// A nevhez tartozik getter: std::string getName()
// Kelleket az addPart(Part*) fuggvennyel lehet a Vehicle objektumhoz hozzadni.
// A Vehicle osztalyban pure virtual fuggveny a print(). Ezt a szarmaztatott osztalyoknak mindenkeppen meg kell valositaniuk.
// 
// Vehicle osztalybol szarmazik a Car es a MotorBike. Mindketto egyfajta jarmu. Mindegyik megvalositja a print() fuggvenyt, es kiirjak magukrol:
// - "Car named X", vagy "MotorBike named X", ahol X a jarmu neve.
// Amikor autot peldanyositunk, hozzon letre maganak 4 kereket, kulonbozo nevekkel (pl. "BalElso" + getName())
// Amikor motorbiciklit peldanyositunk, hozzon letre maganak 2 kereket, kulonbozo nevekkel. Ezeket az addPart() fuggvennyel adhatjuk hozza a jarmuhoz.

// Kulon header file-ban (parts.h) keszitsen egy absztrakt Part osztalyt - ebbol szarmaznak a Wheel (kerek) es AirConditioner osztalyok.
// Minden Part objektumnak van id-je, amit a getId()-val lehet lekerdezni. Tovabb van egy eletkora, ami egy int - "age" - es a getAge()-fuggvennyel kerdezheto le,
// setAge() fuggvennyel pedig allithato.
// Part osztaly pure virtualis fuggvenye az amortize() fuggveny, ami 1-el noveli a kellek korat, es ha egy kerek (Wheel) idosebb, mint 5 eves, akkor kiirja, hogy
// szervizelni kellene..
// ha pedig egy klimaberendezes (AirConditioner) idosebb, mint 8 eves, kiirja, hogy szervizelni kellene..


// Visszaterve a vehicles.h header file-ra:
// keszitsen egy VehiclePark nevu osztalyt. A jarmu parkhoz tartoznak jarmuvek (std::vector<Vehicle*> vehicles) es van egy eletkora (age).
// Kellenek bele az addVehicle(Vehicle*) valamint a printVehicles() fuggvenyek (ez utobbi vegig megy a vehicles vektoron es mindegyiknek meghivja a print() fuggvenyet.
// Ha a VehiclePark osztaly amortize() fuggvenyet meghivjuk, a jarmu park kora 1-el no, es minden jarmure, amely a vehicles vektorban van, meg kell hivni a
// amortizeParts() fuggvenyt. Ez az amortizieParts() fuggveny a Vehicle ososztaly tagfuggvenye, es vegigmegy a teljes "parts" nevu vektoron, mindegyikre meghivva a kellekhez
// tartozo amortize() fuggvenyt (ld. fentebb)

// Vegezetul: kell a VehiclePark meg a Vehicle osztalyba is egy replaceAllWheels() fuggveny. Ha a VehiclePark-nak ezt a fuggvenyet meghivjuk, meghivja a parkban levo
// osszes jarmu replaceAllWheels() fuggvenyet - az pedig vegig megy a "parts" nevu vektoron es csak akkor, ha az adott kellek egy kerek (Wheel), meghivja ra, hogy
// setAge(0);

// A feladat megoldasahoz erdemes a main() fuggveny szerint menni, ott mindig jelezve van, hogy minek kell a konzolon megjelennie.

// Jobb jegyert tegye a kellekek alapjan a jarmuveket kereshetove! Minden kellekben kell, hogy legyen egy hivatkozas egy jarmure, igy ha a kelleket szervizelik,
// utana pontosan nyomon lehet kovetni, hogy melyik jarmuhoz tartozik!


int main()
{
	// Vehicle v; absztrakt osztaly, nem megy!!
	Car c1("Olivers Ferrari");
	MotorBike mb1("Mates Harley");
	Car c2("Ernos Porsche");
	Car c3("Adams Mercedes");

	AirConditioner ac("AirTurbo");
	c2.addPart(&ac);

	VehiclePark vehiclepark;
	vehiclepark.addVehicle(&c1);
	vehiclepark.addVehicle(&c2);
	vehiclepark.addVehicle(&c3);
	vehiclepark.addVehicle(&mb1);
	vehiclepark.printVehicles();
	// Kiirja, hogy
	// Vehicles in park are :
	// Car named: Olivers Ferrari
	// Car named: Ernos Porsche
	// Car named: Adams Mercedes
	// Car named: Mates Harley
	char c;
	std::cin >> c;
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 1
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 2
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 3
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 4
	std::cin >> c;
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 5
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 6, es mivel kerekek tobb, mint 5 evesek, kiirja h cserelni kell a kerekeket
	vehiclepark.replaceAllWheels(); // csak a kerekek kora lesz megint 0, a klimae nem!
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 7
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 8
	std::cin >> c;
	vehiclepark.amortize(); // kiirja, hogy age of vehicles is now: 9, es mivel a klima tobb, mint 8 eves, kiirja, hogy cserelni kellene

	std::cin >> c;
    return 0;
}

