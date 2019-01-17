#pragma once

#include<string>
#include<iostream>
#include<vector>

class Part {
protected:
	std::string name;
	int age = 0;
    const int lifetime;
public:
	Part(const std::string& name, int lifetime) : name(name), lifetime(lifetime) {}
    virtual ~Part() {}
    virtual void amortize() {
        ++age;
    }
	virtual int getAge() const {
		return age;
	}
	std::string getName() {
		return name;
	}
    virtual bool isHealthy() const {
        return age <= lifetime;
    }
    virtual void repair() {
        age = 0;
    }
};

class MultiPart : public Part {
protected:
    std::vector<Part*> parts;
public:
    MultiPart(const std::string& name, int lifetime) : Part(name, lifetime) {}
    ~MultiPart() {
        for (auto p : parts) {
            delete p;
        }
    }
    void addPart(Part* p) {
        parts.push_back(p);
    }
    virtual void amortize() override {
        for (auto p : parts) {
            p->amortize();
        }
    }
    virtual int getAge() const override {
        if (parts.empty()) {
            return 0;
        }
        int maxAge = parts[0]->getAge();
        for (int i = 1; i < parts.size(); ++i) {
            if (parts[i]->getAge() > maxAge)
                maxAge = parts[i]->getAge();
        }
        return maxAge;
    }
    virtual bool isHealthy() const override {
        bool healthy = true;
        for (auto it = parts.cbegin(); it != parts.cend() && healthy; ++it) {
            healthy &= (*it)->isHealthy();
        }
        return healthy && getAge() <= lifetime;
    }
    virtual void repair() override {
        for (auto p : parts) {
            if (!p->isHealthy())
                p->repair();
        }
    }
};

