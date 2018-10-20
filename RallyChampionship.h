#pragma once
#include "Rally.h"
#include "MechanicsTeam.h"
// ----- finish off this class
class RallyChampionship
{
private:
    char* name;
    Rally ralies[3];
    //MechanicsTeam teams[3] ----- to make
    void copy(const RallyChampionship& other);
    void destroy();
public:
    RallyChampionship();
    RallyChampionship(const char* _name, const Rally& _rally1, const Rally& _rally2, const Rally& _rally3);
    RallyChampionship(const RallyChampionship& other);
    RallyChampionship& operator=(const RallyChampionship& other);
    void print();
    void setName(const char* _name);
    size_t getSize() const;
    const char* getName() const;
    //void play();  ----- to make
    //void calculateTime() ----- to make
    //void mechanicsTitle() ----- to make
    void givePoints();
    ~RallyChampionship();
};
