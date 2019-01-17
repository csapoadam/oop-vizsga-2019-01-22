// mainapplication.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "vehicles.h"
#include "parts.h"

// Feladat: keszitsen programot jarmupark nyilvantartasahoz! Ehhez ket header file kell: vehicles.h es parts.h.
// A vehicles.h fajlban:
// Keszitsen egy absztrakt Vehicle (Jarmu) osztalyt! Minden jarmunak legyen neve, es tetszoleges szamu es tipusu alkatresze.
// A nevet lehessen lekerni egy getName() tagfuggvennyel, de kivulrol ne lehessen modositani, a letrehozaskor kelljen megadni.
// Alkatreszt az addPart(Part*) fuggvennyel lehessen a Vehicle objektumhoz hozzadni. (A Part osztalyrol kesobb lesz szo.)
// Mas modon ne lehessen kivulrol elerni az alkatresz objektumokat, es ha a jarmu objektum megsemmisul, szabaditsa fel az alkatreszeit is.
// A Vehicle osztalyban legyen egy implementacio nelkuli print() fuggveny, amit a szarmaztatott osztalyoknak kell majd megvalositaniuk.
//
// Vehicle osztalybol szarmazik a Car es a MotorBike. Mindegyik megvalositja a print() fuggvenyt, es kiirjak magukrol:
// - "Car named X with M/N healthy parts", illetve "MotorBike named X with M/N healthy parts", ahol X a jarmu neve, M az ep, N az osszes alkatresz szama.
// Amikor Car-t peldanyositunk, hozzon letre maganak 4 kereket a Part osztalybol, kulonbozo nevekkel (pl. getName() + " BalElso kereke") es 5 eves elettartammal.
// Amikor motorbiciklit peldanyositunk, hozzon letre maganak 2 kereket, kulonbozo nevekkel es 4 eves elettartammal.

// Kulon header file-ban (parts.h) keszitsen egy Part osztalyt.
// Minden Part objektumnak van egy eletkora (int), ami a getAge() fuggvennyel kerdezheto le, es kezdetben 0,
// valamint egy elettartama (int), amit letrehozaskor kell megadni, es kesobb mar nem modosithato (osztalyon belulrol sem).
// Part osztalynak legyen egy amortize() fuggvenye, ami 1-gyel noveli az alkatresz eletkorat, valamint egy isHealthy(), ami true-t ad vissza, ha az eletkor <= elettartam, kulonben false.
// Tovabba, egy repair() fuggveny, ami 0-ra allitja az eletkort.
//
// A Part osztalybol szarmazzon egy MultiPart, ami tobb Part objektumot tud tarolni, amiket az addPart(Part*) fuggvennyel lehet hozzaadni.
// Megszunesekor szabaditsa fel a benne tarolt alkatreszeket.
// A Multipart getAge() fuggvenye a benne levo legidosebb alkatresz korat adja vissza, az amortize() pedig minden tarolt alkatreszre meghivja az amortize()-t.
// Az isHealthy() akkor adjon vissza true-t, ha minden reszere igaz, hogy isHealthy(), es a legidosebb alkatreszenek kora sem haladja meg a MultiPart objektumnak megadott elettartamot.
// A repair() minden !isHealthy() alkatreszre hivja meg a repair()-t.
// A jarmu print()-jenel a MultiPart is egy Part-nak szamit.

// Visszaterve a vehicles.h header file-ra:
// A Vehicle-nek legyen egy amortizeParts() fuggvenye, ami minden alkatreszere meghivja az amortize()-t.
// Keszitsen egy VehiclePark nevu osztalyt, ami tetszoleges szamu es tipusu jarmuvet tudjon tarolni, es ha megsemmisul, szabaditsa is fel oket.
// Kellenek bele az addVehicle(Vehicle*) valamint a printVehicles() fuggvenyek (ez utobbi vegig megy a jarmuveken es mindegyiknek meghivja a print() fuggvenyet.
// A VehiclePark osztaly amortize() fuggvenye minden benne levo jarmure meghivja az amortizeParts() fuggvenyt.

// Vegezetul: kell a VehiclePark meg a Vehicle osztalyba is egy repair() fuggveny. Ha a VehiclePark-nak ezt a fuggvenyet meghivjuk, meghivja a parkban levo
// osszes jarmu repair() fuggvenyet - az pedig az osszes javitando (!isHealthy()) alkatreszre meghivja a repair()-t.

// A feladat megoldasahoz erdemes a main() fuggveny szerint menni, ott mindig jelezve van, hogy minek kell a konzolon megjelennie.


int main()
{
    // Vehicle v;
	// absztrakt osztaly, nem megy!!
	Vehicle* c1 = new Car("Olivers Ferrari");
    Vehicle* mb1 = new MotorBike("Mates Harley");
    Vehicle* c2 = new Car("Ernos Porsche");
    Vehicle* c3 = new Car("Adams Mercedes");

	c2->addPart(new Part("Air conditioner", 3));

    MultiPart* mp = new MultiPart("Engine", 6);
    mp->addPart(new Part("Piston", 7));
    mp->addPart(new Part("Spark plug", 4));
    c3->addPart(mp);

	VehiclePark vehiclepark;
	vehiclepark.addVehicle(c1);
	vehiclepark.addVehicle(c2);
    vehiclepark.amortize();
    std::cout << "After 1 year:\n";
    vehiclepark.printVehicles();

	vehiclepark.addVehicle(c3);
	vehiclepark.addVehicle(mb1);
    vehiclepark.amortize();
    vehiclepark.amortize();
    std::cout << "After 3 years:\n";
	vehiclepark.printVehicles();

	vehiclepark.amortize();
    std::cout << "After 4 years:\n";
    vehiclepark.printVehicles();

	vehiclepark.amortize();
    std::cout << "After 5 years:\n";
    vehiclepark.printVehicles();

	vehiclepark.amortize();
    std::cout << "After 6 years:\n";
    vehiclepark.printVehicles();

    vehiclepark.repair();
    std::cout << "After repair:\n";
    vehiclepark.printVehicles();

	vehiclepark.amortize();
    std::cout << "After 7 years:\n";
    vehiclepark.printVehicles();

    vehiclepark.amortize();
    std::cout << "After 8 years:\n";
    vehiclepark.printVehicles();

    vehiclepark.repair();
    std::cout << "After repair:\n";
    vehiclepark.printVehicles();

    std::cout << "Press Enter to exit...\n";
    std::cin.get();
    return 0;
}

