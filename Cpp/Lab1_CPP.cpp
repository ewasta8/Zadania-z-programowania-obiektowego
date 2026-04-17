#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Car{
string make; //Marka samochodu
string model; //Model samochodu
int year; //Rok produkcji

time_t t = time(nullptr); //current time
tm *const pTime = localtime(&t); //declaring a pointer and converting t to human-readable format
int currentYear = 1900 + pTime->tm_year;

public:
//constructor
Car(string make_, string model_, int year_)
{
    make=make_;
    model=model_;
    year=year_;
}

void displayInfo(){
    cout<<make<<' '<<model<<' '<<year<<'\n';
}

int getCarAge() {return currentYear-year;}

bool isSameCar(Car otherCar)
{
    if(make==otherCar.make && model==otherCar.model && year==otherCar.year)
        return true;
    return false;
}
};

int main()
{
    Car myCar("Ford","Mustang",1970);
    Car myCar1("Ford","Focus",2012);
    myCar.displayInfo();
    cout<<"Age: "<<myCar.getCarAge()<<'\n';
    if(myCar.isSameCar(myCar1))
        cout<<"Samochody sa takie same";
    else
        cout<<"Samochody sa rozne";
    return 0;
}
