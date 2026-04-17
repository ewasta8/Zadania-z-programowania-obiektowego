#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

class Parrot{
    string text;
    vector <string> phrases;

    public:
    Parrot(string text_){
        text=text_;
        phrases.push_back(text);
    }
    void say()
    {
        char b='Y';
        while(b=='Y'||b=='y'){
            cout<<"Czy chcesz dodac fraze? (Y/N) ";
            char a;
            cin>>a;
            if(a=='Y'||a=='y'){
                cout<<"Podaj fraze: ";
                cin.ignore();
                getline(cin,text);
                phrases.push_back(text);
            }

            int n;
            cout<<"Ile razy powtorzyc? ";
            cin>>n;

            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            default_random_engine engine(seed);
            uniform_int_distribution<int> numbers(0, phrases.size() - 1);

            for(int i=0;i<n;i++){
                int idx = numbers(engine);
                cout<<phrases[idx]<<'\n';
            }

            cout<<"Czy chcesz kontynuowac? (Y/N) ";
            cin>>b;
        }
    }
};

int main()
{
    Parrot myParrot("Orzeszek!");
    myParrot.say();
    return 0;
}