#include "MechanicsTeam.h"

void MechanisTeam::setName(const char* _name)
{
    this->name = new char[strlen(_name)];
    strcpy(this->name,_name);
}
const char* MechanisTeam::getName() const
{
    return this->name;
}
int MechanisTeam::getPoints() const
{
    return this->points;
}
void MechanisTeam::addPoints(int _points)
{
    this->points += _points;
}
Driver MechanisTeam::getDriver(int _position) const
{
    return this->drivers[_position];
}
void MechanisTeam::copy(const MechanisTeam& other)
{
    this->setName(other.getName());
    this->points = other.getPoints();
    for(int i=0; i<2; i++)
    {
        this->drivers[i] = other.getDriver(i);
    }
}
void MechanisTeam::desttoy()
{
    delete[] this->name;
}
void MechanisTeam::print()
{
    cout<<"1) Team`s name: "<<this->getName()<<endl;
    cout<<"2) Team`s points: "<<this->getPoints()<<endl;
    for(int i=0; i<2; i++)
    {
        cout<<i+3<<") Driver "<<i+1<<": "<<endl;
        this->drivers[i].print();
    }
}
MechanisTeam::MechanisTeam()
{
    this->setName("Default");
    this->points = 0;
}
MechanisTeam::MechanisTeam(const char* _name,const Driver& _driver1,const Driver& _driver2)
{
    this->points = 0;
    this->setName(_name);
    this->drivers[0] = _driver1;
    this->drivers[1] = _driver2;
}
MechanisTeam::MechanisTeam(const MechanisTeam& other)
{
    this->copy(other);
}
MechanisTeam& MechanisTeam::operator= (const MechanisTeam& other)
{
    if(this != &other)
    {
        this->desttoy();
        this->copy(other);
    }
    return *this;
}
MechanisTeam::~MechanisTeam()
{
    this->desttoy();
}
