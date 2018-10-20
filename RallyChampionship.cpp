#include "RallyChampionship.h"

void RallyChampionship::setName(const char* _name)
{
    this->name = new char[strlen(_name)];
    strcpy(this->name,_name);
}
const char* RallyChampionship::getName() const
{
    return this->name;
}
void RallyChampionship::copy(const RallyChampionship& other)
{
    for(size_t i = 0; i<3; i++)
    {
        this->ralies[i] = other.ralies[i];
    }
    this->setName(other.getName());
}
void RallyChampionship::destroy()
{
    delete[] this->name;
}
RallyChampionship::RallyChampionship()
{
    this->ralies[0] = Rally();
    this->ralies[1] = Rally();
    this->ralies[2] = Rally();
    this->setName("Default");
}
RallyChampionship::RallyChampionship(const char* _name, const Rally& _rally1 = Rally(), const Rally& _rally2 = Rally(), const Rally& _rally3 = Rally())
{
    this->setName(_name);
    this->ralies[0] = _rally1;
    this->ralies[1] = _rally2;
    this->ralies[2] = _rally3;
}
RallyChampionship::RallyChampionship(const RallyChampionship& other)
{
    this->copy(other);
}
RallyChampionship& RallyChampionship::operator=(const RallyChampionship& other)
{
    if(this != &other)
    {
        this->destroy();
        this->copy(other);
    }
    return *this;
}
void RallyChampionship::print()
{
    cout<<"Information about the "<<this->getName()<<" Rally Championship:"<<endl;
    for(size_t i=0; i<3; i++)
    {
        cout<<"Rally "<<i+1<<" name: "<<this->ralies[i].getName()<<endl;
    }
}
RallyChampionship::~RallyChampionship()
{
    this->destroy();
}
