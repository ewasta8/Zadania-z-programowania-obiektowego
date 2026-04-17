#include <iostream>

using namespace std;

class Samochod{
    string marka;
    string model;
    int rokProdukcji;

    public:
    Samochod():marka("Ford"), model("Mustang"), rokProdukcji(1970){}

    Samochod(string marka_, string model_, int rokProdukcji_){
        marka = marka_;
        model = model_;
        rokProdukcji = rokProdukcji_;
    }

    ~Samochod(){
        cout<<"Destruktor wywolany dla: "<<marka<<" "<<model<<"\n";
    }
};

class Tablica{
    int * tab;

    public:
    Tablica():tab(new int[10]){}

    Tablica(int n){
        tab = new int[n];
    }

    ~Tablica(){
        delete [] tab;
    }
};

int main()
{
    Samochod myCar("Ford","Focus",2012);
    Tablica myTab();
    Tablica myTab2(3);
    return 0;
}