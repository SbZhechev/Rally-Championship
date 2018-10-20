#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Car
{
private:
    char* model;
    char* description;
    double sharpTurnsRating;
    double normalTurnsRating;
    double shortStraightsRating;
    double mediumStraightsRating;
    double longStraightsRating;
    double snowRating;
    double gravelRating;
    double asphaltRating;
    void copy(const Car& other);
    void destroy();
public:
    const char* getModel() const;
    const char* getDescription() const;
    double getSharpTurnsRating() const;
    double getNormalTurnsRating() const;
    double getShortStraightsRating() const;
    double getMeduimStraightsRating() const;
    double getLongStraightsRating() const;
    double getSnowRating() const;
    double getGravelRating() const;
    double getAsphaltRating() const;
    void setModel (const char* _model);
    void setDescription (const char* _description);
    void print();
    Car();
    Car(const char* _model, const char* _description, double _sharpTurnsRating,
        double _normalTurnsRating, double _shortStraightsRating,
        double _mediumStraightsRating, double _longStraightsRating,
        double _snowRating, double _gravelRating, double _asphaltRating);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();
};
