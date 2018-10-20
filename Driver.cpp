#include "Driver.h"


void Driver::setName(const char* _name)
{
    this->name = new char[strlen(_name)];
    strcpy(this->name,_name);
}

void Driver::setCharacteristics(const char* _characteristics)
{
    this->characteristics = new char[strlen(_characteristics)];
    strcpy(this->characteristics,_characteristics);
}
void Driver::setCar(const Car& _car)
{
    this->car = _car;
}
const char* Driver::getName() const
{
    return this->name;
}
const char* Driver::getCharacteristics() const
{
    return this->characteristics;
}
int Driver::getOverallPoints() const
{
    return this->overallPoints;
}
int Driver::getPointsPerRace() const
{
    return this->pointsPerRace;
}
Car Driver::getCar() const
{
    return this->car;
}
void Driver::addPoints(int _points)
{
    this->pointsPerRace += _points;
    this->overallPoints += _points;
}
void Driver::copy(const Driver& other)
{
    this->setName(other.getName());
    this->setCharacteristics(other.getCharacteristics());
    this->pointsPerRace = other.getPointsPerRace();
    this->overallPoints = other.getOverallPoints();
    this->setCar(other.getCar());
}
void Driver::destroy()
{
    delete[] this->name;
    delete[] this->characteristics;
}
void Driver::print()
{
    cout<<"    - Name: "<<this->getName()<<endl;
    cout<<"    - Characteristics: "<<this->getCharacteristics()<<endl;
    cout<<"    - Points: "<<this->getOverallPoints()<<endl;
    this->car.print();
}
Driver::Driver()
{
    this->setName("Default");
    this->setCharacteristics("Default");
    this->overallPoints = 0;
    this->pointsPerRace = 0;
}
Driver::Driver(const char* _name,const char* _characteristics, const Car& _car)
{
    this->setName(_name);
    this->setCharacteristics(_characteristics);
    this->setCar(_car);
    this->overallPoints = 0;
    this->pointsPerRace = 0;
}
Driver::Driver(const Driver& other)
{
    this->copy(other);
}
Driver& Driver::operator=(const Driver& other)
{
    if (this != &other)
    {
        this->destroy();
        this->copy(other);
    }
    return *this;
}
Driver::~Driver()
{
    this->destroy();
}
