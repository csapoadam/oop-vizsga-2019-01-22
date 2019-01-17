#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "parts.h"

class Vehicle {
private:
	std::string name;
	std::vector<Part*> parts;
public:
	Vehicle(const std::string& n) : name(n) {}
	virtual void print() = 0;
	void addPart(Part* p) {
		parts.push_back(p);
	}
	void amortizeParts() {
		for (std::vector<Part*>::iterator it = parts.begin(); it != parts.end(); it++) {
			(*it)->amortize();
		}
	}
	void replaceAllWheels() {
		for (std::vector<Part*>::iterator it = parts.begin(); it != parts.end(); it++) {
			Wheel* wh = dynamic_cast<Wheel*>(*it);
			if (wh) {
				wh->setAge(0);
			}
		}
	}
	std::string getName() {
		return name;
	}
};

class Car : public Vehicle {
public:
	Car(const std::string& n) : Vehicle(n) {
		Wheel* frontLeftWheel = new Wheel("FrontLeft-" + getName());
		Wheel* frontRightWheel = new Wheel("FrontRight-" + getName());
		Wheel* rearLeftWheel = new Wheel("RearLeft-" + getName());
		Wheel* rearRightWheel = new Wheel("RearRight-" + getName());
		addPart(frontLeftWheel);
		addPart(frontRightWheel);
		addPart(rearLeftWheel);
		addPart(rearRightWheel);
	}
	void print() {
		std::cout << "Car named: " << getName() << std::endl;
	}
};

class MotorBike : public Vehicle {
public:
	MotorBike(const std::string& n) : Vehicle(n) {
		Wheel* frontWheel = new Wheel("Front-" + getName());
		Wheel* rearWheel = new Wheel("Rear-" + getName());
		addPart(frontWheel);
		addPart(rearWheel);
	}
	void print() {
		std::cout << "MotorBike named: " << getName() << std::endl;
	}
};

class VehiclePark {
private:
	std::vector<Vehicle*> vehicles;
	int age;
public:
	VehiclePark() : age(0) {}
	void addVehicle(Vehicle* v) {
		vehicles.push_back(v);
	}

	void amortize() {
		std::cout << "age of vehicles is now: " << ++age << std::endl;
		for (std::vector<Vehicle*>::iterator it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->amortizeParts();
		}
	}

	void replaceAllWheels() {
		for (std::vector<Vehicle*>::iterator it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->replaceAllWheels();
		}
	}

	void printVehicles() {
		std::cout << "====" << std::endl << "Vehicles in park are:" << std::endl;
		for (std::vector<Vehicle*>::iterator it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->print();
		}
		std::cout << "====" << std::endl;
	}
};
