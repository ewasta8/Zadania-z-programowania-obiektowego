#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Pojazd{
    public:
    virtual void przyspiesz()=0;
    virtual void zatrzymaj()=0;
    virtual ~Pojazd()=default;
};

class Samochod: public Pojazd{
    public:
    void przyspiesz() override{
        cout<<"Samochod przyspiesza\n";
    }
    void zatrzymaj() override{
        cout<<"Samochod sie zatrzymuje\n";
    }
};

class Rower: public Pojazd{
    public:
    void przyspiesz() override{
        cout<<"Rower przyspiesza\n";
    }
    void zatrzymaj() override{
        cout<<"Rower sie zatrzymuje\n";
    }
};

class Motocykl: public Pojazd{
    public:
    void przyspiesz() override{
        cout<<"Motocykl przyspiesza\n";
    }
    void zatrzymaj() override{
        cout<<"Motocykl sie zatrzymuje\n";
    }
};

class Skuter: public Pojazd{
    public:
    void przyspiesz() override{
        cout<<"Skuter przyspiesza\n";
    }
    void zatrzymaj() override{
        cout<<"Skuter sie zatrzymuje\n";
    }
};

int main()
{
    Samochod s;
    Rower r;
    Motocykl m;
    vector<unique_ptr<Pojazd>> v;
    v.push_back(make_unique<Samochod>());
    v.push_back(make_unique<Rower>());
    v.push_back(make_unique<Rower>());
    v.push_back(make_unique<Motocykl>());
    v.push_back(make_unique<Skuter>());
    for(int i=0;i<v.size();i++){
        v[i]->przyspiesz();
        v[i]->zatrzymaj();
    }
    return 0;
}