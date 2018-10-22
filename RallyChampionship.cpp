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
size_t RallyChampionship::getSize() const
{
    return this->size;
}
size_t RallyChampionship::getCapacity() const
{
    return this->capacity;
}
size_t RallyChampionship::getTeamSize() const
{
    return this->teamSize;
}
size_t RallyChampionship::getTeamCapacity() const
{
    return this->teamCapacity;
}
void RallyChampionship::copy(const RallyChampionship& other)
{
    this->size = other.getSize();
    this->capacity = other.getCapacity();
    this->ralies = new Rally[other.getCapacity()];
    for(size_t i=0; i<other.getSize(); i++)
    {
        this->ralies[i] = other.ralies[i];
    }
    this->teamSize = other.getTeamSize();
    this->teamCapacity = other.getTeamCapacity();
    this->teams = new MechanicsTeam[other.capacity];
    for(size_t i=0; i<other.getSize(); i++)
    {
        this->teams[i] = other.teams[i];
    }
    strcpy(this->name,other.getName());
}
void RallyChampionship::destroy()
{
    delete[] this->name;
    delete[] this->ralies;
}
void RallyChampionship::resize()
{
    this->capacity = this->capacity*2 + 1;
    Rally* temp = new Rally[this->capacity];
    for(size_t i=0 ;i<this->size; i++)
    {
        temp[i] = this->ralies[i];
    }
    delete[] this->ralies;
    this->ralies = temp;
}
void RallyChampionship::resizeTeam()
{
    this->teamCapacity = this->teamCapacity * 2 + 1;
    MechanicsTeam* temp = new MechanicsTeam[this->teamCapacity];
    for(size_t i=0; i<this->teamSize; i++)
    {
        temp[i] = this->teams[i];
    }
    delete[] this->teams;
    this->teams = temp;
}
RallyChampionship::RallyChampionship()
{
    this->size = 0;
    this->capacity = 5;
    this->teamSize = 0;
    this->teamCapacity = 5;
    this->teams = new MechanicsTeam[this->capacity];
    this->ralies = new Rally[this->capacity];
    this->setName("Default");
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
    this->setTimings();
    cout<<"Information about the "<<this->getName()<<" Rally Championship:"<<endl;
    for(size_t i=0; i<this->size; i++)
    {
        cout<<"Rally "<<i+1<<" name: "<<this->ralies[i].getName()<<endl;
    }
    for(size_t i=0; i<this->teamSize; i++)
    {
        cout<<"Mechanic team "<<i+1<<" name: "<<this->teams[i].getName()<<endl;
        cout<<"Driver 1: ";
        this->teams[i].getDriver(0).print();
        cout<<"Driver 1: ";
        this->teams[i].getDriver(1).print();
    }
    cout<<"Number of rallies in this championship: "<<this->size<<endl;
    cout<<"Number of mechanic teams: "<<this->teamSize<<endl;
}
void RallyChampionship::addRally(const Rally& _rally)
{
    if(this->size >= this->capacity)
    {
        this->resize();
    }
    this->ralies[size++] = _rally;
}
void RallyChampionship::addTeams(const MechanicsTeam& _team)
{
    if(this->teamSize >= this->teamCapacity)
    {
        this->resizeTeam();
    }
    this->teams[teamSize++] = _team;
}
double RallyChampionship::calculateTime(const Rally& _rally,const Driver& _driver)
{
    if(strcmp(_rally.getSurface(),"Asphalt") == 0)
    {
        return _driver.getCar().getLongStraightsRating()*_rally.getNumberOfLongStraights() +
               _driver.getCar().getMeduimStraightsRating()*_rally.getNumberOfMediumStraights() +
               _driver.getCar().getShortStraightsRating()*_rally.getNumberOfShortStraights() +
               _driver.getCar().getSharpTurnsRating()*_rally.getNumberOfSharpTurns() +
               _driver.getCar().getNormalTurnsRating()*_rally.getNumberOfNormalTurns() +
               _driver.getCar().getAsphaltRating();
    }
    else if(strcmp(_rally.getSurface(),"Gravel") == 0)
    {
        return  _driver.getCar().getLongStraightsRating()*_rally.getNumberOfLongStraights() +
               _driver.getCar().getMeduimStraightsRating()*_rally.getNumberOfMediumStraights() +
               _driver.getCar().getShortStraightsRating()*_rally.getNumberOfShortStraights() +
               _driver.getCar().getSharpTurnsRating()*_rally.getNumberOfSharpTurns() +
               _driver.getCar().getNormalTurnsRating()*_rally.getNumberOfNormalTurns() +
               _driver.getCar().getGravelRating();
    }
    else
    {
        return  _driver.getCar().getLongStraightsRating()*_rally.getNumberOfLongStraights() +
               _driver.getCar().getMeduimStraightsRating()*_rally.getNumberOfMediumStraights() +
               _driver.getCar().getShortStraightsRating()*_rally.getNumberOfShortStraights() +
               _driver.getCar().getSharpTurnsRating()*_rally.getNumberOfSharpTurns() +
               _driver.getCar().getNormalTurnsRating()*_rally.getNumberOfNormalTurns() +
               _driver.getCar().getSnowRating();
    }
}
int RallyChampionship::givePoints(int _rank)
{
    switch(_rank)
    {
        case 1: return 20; break;
        case 2: return 18; break;
        case 3: return 16; break;
        case 4: return 14; break;
        case 5: return 12; break;
        case 6: return 10; break;
        case 7: return 9; break;
        case 8: return 8; break;
        case 9: return 7; break;
        case 10: return 6; break;
        default : return 0; break;
    }
}
void RallyChampionship::setTimings()
{
    for(size_t i=0 ;i<this->teamSize; i++)
    {
        for(size_t j=0; j<this->size ;j++)
        {
            this->teams[i].getDriver(0).setTiming(this->calculateTime(this->getRally(j),this->teams[i].getDriver(0)));
            this->teams[i].getDriver(1).setTiming(this->calculateTime(this->getRally(j),this->teams[i].getDriver(1)));
        }
    }
}
Rally& RallyChampionship::getRally(size_t position) const
{
    return this->ralies[position];
}
RallyChampionship::~RallyChampionship()
{
    this->destroy();
}
