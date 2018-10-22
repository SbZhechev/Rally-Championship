#pragma once
#include "Rally.h"
#include "MechanicsTeam.h"
// ----- finish off this class
class RallyChampionship
{
private:
    char* name;
    Rally* ralies;
    size_t size;
    size_t capacity;
    MechanicsTeam* teams;
    size_t teamSize;
    size_t teamCapacity;
    void copy(const RallyChampionship& other);
    void destroy();
    void resize();
    void resizeTeam();
public:
    RallyChampionship();
    RallyChampionship(const RallyChampionship& other);
    RallyChampionship& operator=(const RallyChampionship& other);
    void print();
    void setName(const char* _name);
    size_t getSize() const;
    size_t getCapacity() const;
    size_t getTeamSize() const;
    size_t getTeamCapacity() const;
    const char* getName() const;
    //void play();  ----- to make
    double calculateTime(const Rally& _rally,const Driver& _driver);
    //void mechanicsTitle() ----- to make
    int givePoints(int _rank);
    void setTimings();
    void addTeams(const MechanicsTeam& _team);
    void addRally(const Rally& _rally);
    Rally& getRally(size_t position) const;
    ~RallyChampionship();
};
