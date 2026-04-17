#include <iostream>

using namespace std;

class Pojazd{
    private: 
    string marka;
    string model;

    public:
    Pojazd(string ma, string mo):marka(ma), model(mo){}
    virtual void przyspiesz() = 0;
};

class Samochod: public Pojazd{
    public:
    Samochod(string ma, string mo) : Pojazd(ma, mo) {}
};

class ElektrycznySamochod: public Samochod{
    public:
    ElektrycznySamochod(string ma, string mo) : Samochod(ma, mo) {}
    void przyspiesz() override{
        cout<<"Samochod elektryczny przyspiesza\n";
    }
};

int main()
{
    ElektrycznySamochod e("Tesla","Model 3");
    e.przyspiesz();
    return 0;
}