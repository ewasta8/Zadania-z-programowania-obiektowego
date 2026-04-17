#include <iostream>

using namespace std;

class Pojazd{
    private: 
    string marka;
    string model;

    public:
    /*void przyspiesz(){
        cout<<"Pojazd przyspiesza\n";
    }*/
    Pojazd(string ma, string mo):marka(ma), model(mo){}
    virtual void przyspiesz() = 0;
};

class Samochod: public Pojazd{
    public:
    void przyspiesz(){
        cout<<"Samochod przyspiesza\n";
    }
};

class Rower: public Pojazd{
    public:
    void przyspiesz() override{
        cout<<"Rower przyspiesza\n";
    }
};

int main()
{
    //Pojazd p;
    Samochod s;
    Rower r;
    s.marka="Ford";
    //p.przyspiesz();
    s.przyspiesz();
    r.przyspiesz();
    return 0;
}