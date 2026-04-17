#include <iostream>

using namespace std;

class Pojazd{
    public:
    virtual void przyspiesz() = 0;
};

class Silnikowy: public Pojazd{
    public:
    void przyspiesz(){
        cout<<"Pojazd silnikowy przyspiesza\n";
    }
};

class Elektryczny: public Pojazd{
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
    Hybrydowy h;
    h.przyspiesz();
    return 0;
}