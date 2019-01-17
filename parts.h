#pragma once

#include<string>
#include<iostream>

class Part {
private:
	std::string id;
	int age = 0;
public:
	Part(std::string id) : id(id) {}
	virtual void amortize() = 0;
	void setAge(int age) {
		this->age = age;
	}
	int getAge() {
		return age;
	}
	std::string getId() {
		return id;
	}
};

class Wheel : public Part {
public:
	Wheel(std::string id) : Part(id) {}
	virtual void amortize() {
		setAge(getAge() + 1);
		if (getAge() > 5) {
			std::cout << "Warning: wheel " << getId() << " is old, needs to be serviced!" << std::endl;
		}
	}
};

class AirConditioner : public Part {
public:
	AirConditioner(std::string id) : Part(id) {}
	virtual void amortize() {
		setAge(getAge() + 1);
		if (getAge() > 8) {
			std::cout << "Warning: AC " << getId() << " is old, needs to be serviced!" << std::endl;
		}
	}
};

