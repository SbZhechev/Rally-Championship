#pragma once
#include <iostream>
#include <cstring>
#include "Driver.h"

class MechanisTeam
{
private:
    char* name;
    Driver drivers[2];
    int points;
    void copy(const MechanisTeam& other);
    void desttoy();
public:
    void setName(const char* _name);
    void addPoints(int _points);
    const char* getName() const;
    int getPoints() const;
    void print();
    Driver getDriver(int _position) const;
    MechanisTeam();
    MechanisTeam(const char* _name,const Driver& _driver1,const Driver& _driver2);
    MechanisTeam(const MechanisTeam& other);
    MechanisTeam& operator= (const MechanisTeam& other);
    ~MechanisTeam();
};
