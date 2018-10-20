#include "RallyChampionship.h"

int main()
{
    Car Kia("Kia Stinger","Aggressive looking sports car that has a perfect stability on snow terrain and performs incredibly on medium straights",0.34,0.29,0.26,0.28,0.54,1.1,1.22,1.1);
    Car Toyota("Toyota Corola","Very good durable car that has the ability to elegantly take sharp turns and it also has good acceleration.",0.23,0.32,0.20,0.24,0.56,1.2,1.4,1);
    Driver Michael("Michael Schummaher","Not that bad of a driver with a short temper",Kia);
    Driver Sebastian("Sebastian Fetel","Very skilled driver that has numerous titles under his belt.",Toyota);
    Rally Sweden("Rally Sweden","A rally with snowy surface that is well know for it`s sharp turns and medium straights.","Snow",20,15,10,30,12);
    //Sweden.print();
    MechanisTeam Bulldogs("Bulldogs",Sebastian,Michael);
    Bulldogs.print();
    RallyChampionship winter("Winter",Sweden,Sweden,Sweden);
    //winter.print();
    return 0;
}
