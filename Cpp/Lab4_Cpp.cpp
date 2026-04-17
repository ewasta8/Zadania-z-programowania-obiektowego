#include <iostream>
#include <string>

using namespace std;

class Osoba{
    string imie;
    string nazwisko;
    int wiek;
    string email;
    string telefon;

    public:
    //set
    void set_name(string n){
        imie=n;
    }
    void set_surname(string s){
        nazwisko=s;
    }
    void set_age(int a){
        wiek=a;
    }
    void set_email(string e){
        if(e.find('@') != string::npos)
            email=e;
        else
            cout<<"Bledny email";
    }
    void set_telephone(string t){
        if(t.size()==9)
            telefon=t;
        else
            cout<<"Bledny numer telefonu";
    }
    
    //get
    string get_name(){
        return imie;
    }
    string get_surname(){
        return nazwisko;
    }
    int get_age(){
        return wiek;
    }
    string get_email(){
        return email;
    }
    string get_telephone(){
        return telefon;
    }
};

class Pracownik{
    protected:
    string stanowisko;
    float wynagrodzenie;

    public:
    Pracownik(string st, float wyn):stanowisko(st), wynagrodzenie(wyn){}
};

class Nauczyciel: public Pracownik{
    public:
    Nauczyciel(string st, float wyn) : Pracownik(st, wyn) {}
    void pokaz_dane(){
        cout<<"stanowisko: "<<stanowisko<<'\n'<<"wynagrodzenie: "<<wynagrodzenie<<'\n';
    }
};

class Administracja: public Pracownik{
    public:
    Administracja(string st, float wyn) : Pracownik(st, wyn) {}
    void pokaz_dane(){
        cout<<"stanowisko: "<<stanowisko<<'\n'<<"wynagrodzenie: "<<wynagrodzenie<<'\n';
    }
};

int main()
{
    Osoba o;
    o.set_name("Kasia");
    //cout<<o.get_name();
    Nauczyciel n("nauczyciel matematyki",3500);
    n.pokaz_dane();
    return 0;
}