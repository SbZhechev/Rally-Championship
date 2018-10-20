#pragma once
#include "Car.h"
#include <iostream>
#include <cstring>

using namespace std;

class Driver
{
private:
    char* name;
    char* characteristics;
    Car car;
    int pointsPerRace, overallPoints;
    void copy(const Driver& other);
    void destroy();
public:
    void setName(const char* _name);
    void setCharacteristics(const char* _characteristics);
    void setCar(const Car& _car);
    const char* getName() const;
    const char* getCharacteristics() const;
    int getOverallPoints() const;
    int getPointsPerRace() const;
    Car getCar() const;
    void addPoints(int _points);
    void print();
    Driver();
    Driver(const char* _name,const char* _characteristics,const Car& _car);
    Driver(const Driver& other);
    Driver& operator=(const Driver& other);
    ~Driver();
};
