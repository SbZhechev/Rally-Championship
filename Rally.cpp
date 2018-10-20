#include "Rally.h"

void Rally::setName(const char* _name)
{
    this->name = new char[strlen(_name)];
    strcpy(this->name,_name);
}
void Rally::setDescription(const char* _description)
{
    this->description = new char[strlen(_description)];
    strcpy(this->description,_description);
}
void Rally::setSurface(const char* _surface)
{
    this->surface=new char[strlen(_surface)];
    strcpy(this->surface,_surface);
}
const char* Rally::getName() const
{
    return this->name;
}
const char* Rally::getDescription() const
{
    return this->description;
}
const char* Rally::getSurface() const
{
    return this->surface;
}
int Rally::getNumberOfSharpTurns() const
{
    return this->numberOfSharpTurns;
}
int Rally::getNumberOfNormalTurns() const
{
    return this->numberOfNormalTurns;
}
int Rally::getNumberOfShortStraights() const
{
    return this->numberOfShortStraights;
}
int Rally::getNumberOfMediumStraights() const
{
    return this->numberOfMediumStraights;
}
int Rally::getNumberOfLongStraights() const
{
    return this->numberOfLongStraights;
}
void Rally::copy(const Rally& other)
{
    this->setName(other.getName());
    this->setDescription(other.getDescription());
    this->setSurface(other.getSurface());
    this->numberOfSharpTurns = other.getNumberOfSharpTurns();
    this->numberOfNormalTurns = other.getNumberOfNormalTurns();
    this->numberOfShortStraights = other.getNumberOfShortStraights();
    this->numberOfMediumStraights = other.getNumberOfMediumStraights();
    this->numberOfLongStraights = other.getNumberOfLongStraights();
}
void Rally::destroy()
{
    delete[] this->name;
    delete[] this->description;
    delete[] this->surface;
}
void Rally::print()
{
    cout<<"Information about the rally:"<<endl;
    cout<<"1) Name: "<<this->getName()<<endl;
    cout<<"2) Description: "<<this->getDescription()<<endl;
    cout<<"3) Surface: "<<this->getSurface()<<endl;
    cout<<"4) Number of sharp turns: "<<this->getNumberOfSharpTurns()<<endl;
    cout<<"5) Number of normal turns: "<<this->getNumberOfNormalTurns()<<endl;
    cout<<"6) Number of short straights: "<<this->getNumberOfShortStraights()<<endl;
    cout<<"7) Number of medium straights: "<<this->getNumberOfMediumStraights()<<endl;
    cout<<"8) Number of long straights: "<<this->getNumberOfLongStraights()<<endl;
}
Rally::Rally()
{
    this->setName("Default");
    this->setDescription("Description");
    this->setSurface("Description");
    this->numberOfSharpTurns = 0;
    this->numberOfNormalTurns = 0;
    this->numberOfShortStraights = 0;
    this->numberOfMediumStraights = 0;
    this->numberOfLongStraights = 0;
}
Rally::Rally(const char* _name, const char* _description,const char* _surface,int _sharpTurns,int _normalTurns,int _shortStraights,int _mediumStraights, int _longStraights)
{
    this->setName(_name);
    this->setDescription(_description);
    this->setSurface(_surface);
    this->numberOfSharpTurns = _sharpTurns;
    this->numberOfNormalTurns = _normalTurns;
    this->numberOfShortStraights = _shortStraights;
    this->numberOfMediumStraights = _mediumStraights;
    this->numberOfLongStraights = _longStraights;
}
Rally::Rally(const Rally& other)
{
    this->copy(other);
}
Rally& Rally::operator=(const Rally& other)
{
    if(this != &other)
    {
        this->destroy();
        this->copy(other);
    }
    return *this;
}
Rally::~Rally()
{
    this->destroy();
}
