#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "parts.h"

class Vehicle {
protected:
	std::string name;
	std::vector<Part*> parts;
    int countHealthy() const {
        int h = 0;
        for (auto p : parts) {
            if (p->isHealthy())
                ++h;
        }
        return h;
    }
public:
	Vehicle(const std::string& n) : name(n) {}
    virtual ~Vehicle() {
        for (auto p : parts) {
            delete p;
        }
    }
	virtual void print() const = 0;
	void addPart(Part* p) {
		parts.push_back(p);
	}
	void amortizeParts() {
		for (auto p : parts) {
			p->amortize();
		}
	}
	std::string getName() const {
		return name;
	}
    void repair() {
        for (auto p : parts) {
            p->repair();
        }
    }
};

class Car : public Vehicle {
public:
	Car(const std::string& n) : Vehicle(n) {
        parts.push_back(new Part("Front left wheel of " + n, 5));
        parts.push_back(new Part("Front right wheel of " + n, 5));
        parts.push_back(new Part("Rear left wheel of " + n, 5));
        parts.push_back(new Part("Rear right wheel of " + n, 5));
	}
    virtual void print() const override {
		std::cout << "Car named " << getName() << " with " << countHealthy() << "/" << parts.size() << " healthy parts\n";
	}
};

class MotorBike : public Vehicle {
public:
	MotorBike(const std::string& n) : Vehicle(n) {
        parts.push_back(new Part("Front wheel of " + n, 4));
        parts.push_back(new Part("Rear wheel of " + n, 4));
	}
    virtual void print() const override {
		std::cout << "MotorBike named " << getName() << " with " << countHealthy() << "/" << parts.size() << " healthy parts\n";
	}
};

class VehiclePark {
private:
	std::vector<Vehicle*> vehicles;
public:
    ~VehiclePark() {
        for (auto v : vehicles) {
            delete v;
        }
    }
	void addVehicle(Vehicle* v) {
		vehicles.push_back(v);
	}

	void amortize() {
		for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->amortizeParts();
		}
	}

	void repair() {
		for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->repair();
		}
	}

	void printVehicles() {
		std::cout << "====" << std::endl << "Vehicles in park are:" << std::endl;
		for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->print();
		}
		std::cout << "====" << std::endl;
	}
};
