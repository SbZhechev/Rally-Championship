#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Rally
{
private:
    char* name;
    char* description;
    char* surface;
    int numberOfSharpTurns, numberOfNormalTurns, numberOfShortStraights, numberOfMediumStraights, numberOfLongStraights;
    void copy(const Rally& other);
    void destroy();
public:
    void setName(const char* _name);
    void setDescription(const char* _description);
    void setSurface(const char* _surface);
    const char* getName() const;
    const char* getDescription() const;
    const char* getSurface() const;
    int getNumberOfSharpTurns() const;
    int getNumberOfNormalTurns() const;
    int getNumberOfShortStraights() const;
    int getNumberOfMediumStraights() const;
    int getNumberOfLongStraights() const;
    void print();
    Rally();
    Rally(const char* _name, const char* _description,const char* _surface,int _sharpTurns,int _normalTurns,int _shortStraights,int _mediumStraights, int _longStraights);
    Rally(const Rally& other);
    Rally& operator=(const Rally& other);
    ~Rally();
};
