#include "Car.h"
const char* Car::getModel() const
{
    return this->model;
}
const char* Car::getDescription() const
{
    return this->description;
}
double Car::getSharpTurnsRating() const
{
    return this->sharpTurnsRating;
}
double Car::getNormalTurnsRating() const
{
    return this->normalTurnsRating;
}
double Car::getShortStraightsRating() const
{
    return this->shortStraightsRating;
}
double Car::getMeduimStraightsRating() const
{
    return this->mediumStraightsRating;
}
double Car::getLongStraightsRating() const
{
    return this->longStraightsRating;
}
double Car::getSnowRating() const
{
    return this->snowRating;
}
double Car::getGravelRating() const
{
    return this->gravelRating;
}
double Car::getAsphaltRating() const
{
    return this->asphaltRating;
}
void Car::setDescription(const char* _description)
{
    this->description = new char[strlen(_description)];
    strcpy(this->description,_description);
}
void Car::setModel(const char* _model)
{
    this->model = new char[strlen(_model)];
    strcpy(this->model,_model);
}
void Car::print()
{
    cout<<"Car`s information:"<<endl;
    cout<<"     * Model: "<<this->getModel()<<endl;
    cout<<"     * Description: "<<this->getDescription()<<endl;
    cout<<"     * Sharp turns rating: "<<this->getSharpTurnsRating()<<endl;
    cout<<"     * Normal turns rating: "<<this->getNormalTurnsRating()<<endl;
    cout<<"     * Short straights rating: "<<this->getShortStraightsRating()<<endl;
    cout<<"     * Medium straights rating: "<<this->getMeduimStraightsRating()<<endl;
    cout<<"     * Long straights rating: "<<this->getLongStraightsRating()<<endl;
    cout<<"     * Snow rating: "<<this->getSnowRating()<<endl;
    cout<<"     * Gravel rating: "<<this->getGravelRating()<<endl;
    cout<<"     * Asphalt rating: "<<this->getAsphaltRating()<<endl;
}
void Car::copy(const Car& other)
{
    this->setModel(other.getModel());
    this->setDescription(other.getDescription());
    this->sharpTurnsRating = other.getSharpTurnsRating();
    this->normalTurnsRating = other.getNormalTurnsRating();
    this->shortStraightsRating = other.getShortStraightsRating();
    this->mediumStraightsRating = other.getMeduimStraightsRating();
    this->longStraightsRating = other.getLongStraightsRating();
    this->snowRating = other.getSnowRating();
    this->gravelRating = other.getGravelRating();
    this->asphaltRating = other.getAsphaltRating();
}
void Car::destroy()
{
    delete[] this->model;
    delete[] this->description;
}
Car::Car()
{
    this->setModel("Default");
    this->setDescription("Default");
    this->sharpTurnsRating = 0;
    this->normalTurnsRating = 0;
    this->shortStraightsRating = 0;
    this->mediumStraightsRating = 0;
    this->longStraightsRating = 0;
    this->snowRating = 0;
    this->gravelRating = 0;
    this->asphaltRating = 0;

}
Car::Car(const char* _model, const char* _description, double _sharpTurnsRating,
        double _normalTurnsRating, double _shortStraightsRating,
        double _mediumStraightsRating, double _longStraightsRating,
        double _snowRating, double _gravelRating, double _asphaltRating)
{
    this->setModel(_model);
    this->setDescription(_description);
    this->sharpTurnsRating = _sharpTurnsRating;
    this->normalTurnsRating = _normalTurnsRating;
    this->shortStraightsRating = _shortStraightsRating;
    this->mediumStraightsRating = _mediumStraightsRating;
    this->longStraightsRating = _longStraightsRating;
    this->snowRating = _snowRating;
    this->gravelRating = _gravelRating;
    this->asphaltRating = _asphaltRating;
}
Car::Car(const Car& other)
{
    this->copy(other);
}
Car& Car::operator=(const Car& other)
{
    if(this != &other)
    {
        this->destroy();
        this->copy(other);
    }
    return *this;
}
Car::~Car()
{
    this->destroy();
}
