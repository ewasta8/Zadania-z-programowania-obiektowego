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
    Samochod(string ma,string mo):Pojazd(ma,mo){}
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

class Silnikowy{
    public:
    void przyspiesz(){
        cout<<"Pojazd silnikowy przyspiesza\n";
    }
};

class Elektryczny{
    public:
    void ladowanie(){
        cout<<"Pojazd sie laduje\n";
    }
};

class Hybrydowy: public Silnikowy, public Elektryczny{
    public:
    void przyspiesz(){
        cout<<"Pojazd hybrydowy przyspiesza\n";
    }
};

int main()
{
    //Pojazd p;
    /*Samochod s("Ford","Focus");
    Rower r;
    //p.przyspiesz();
    s.przyspiesz();
    r.przyspiesz();*/
    Hybrydowy h;
    h.przyspiesz();
    h.ladowanie();
    return 0;
}