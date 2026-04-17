#include <iostream>
#include <vector>

using namespace std;

//------------ADAPTER-----------------
// Istniejący system
class LegacyPaymentProcessor{
    public:
    void makePayment(int zlote, int grosze){
        cout<<"Legacy System: Przetworzono "<<zlote<<"."<<grosze<<" PLN.\n";
    }
};

// Interfejs płatności
class PaymentProcessor{
    public:
    void addPayment(double amount){
        cout<<"Adding: Przetworzono "<<amount<<" PLN.\n";
    }
};

// Adapter
class PaymentAdapter{
    private:
    LegacyPaymentProcessor legacyPaymentProcessor;
    public:
    void processPayment(double amount){
        int amount_z=amount/1;
        int amount_g=(amount-amount_z)*100;
        legacyPaymentProcessor.makePayment(amount_z, amount_g);
    }
};

//------------DECORATOR-----------------
// Interfejs okna
class Window{
    public:
    virtual void display_window()=0;
};

// Klasa bazowa
class SimpleWindow: public Window{
    public:
    void display_window() override{
        cout<<"Window";
    }
};

// Dekorator
class Window_decorator: public Window{
    protected:
    Window* decorated_window;
    public:
    Window_decorator(Window* window) : decorated_window(window) {}

    void display_window() override{
        decorated_window->display_window();
    }
};

// Konkretne dekoratory
class Frame_decorator: public Window_decorator{
    public:
    Frame_decorator(Window* window) : Window_decorator(window) {}
    void display_window() override{
        Window_decorator::display_window();
        cout<<" + frame";
    }
};

class Scrolling_decorator: public Window_decorator{
    public:
    Scrolling_decorator(Window* window) : Window_decorator(window) {}
    void display_window() override{
        Window_decorator::display_window();
        cout<<" + scrolling";
    }
};

//------------FACADE-----------------
class FlightSearch{
    public:
    void search(string flight){
        cout<<"Searching: "<<flight<<"\n";
    }
};

class BookingSystem{
    public:
    void book(){
        cout<<"Booking flight\n";
    }
};

class FlightPayment{
    public:
    void pay(){
       cout<<"Processing payment\n";
    }
};

class FlightFacade{
    private:
    FlightSearch flightSearch;
    BookingSystem bookingSystem;
    FlightPayment flightPayment;

    public:
    void bookFlight(string flight){
        flightSearch.search(flight);
        bookingSystem.book();
        flightPayment.pay();
    }
};

//------------COMPOSITE-----------------
class FileSystemComponent{
    public:
    virtual void display()=0;
    virtual ~FileSystemComponent() {}
};

class File: public FileSystemComponent{
    private:
    string name;
    public:
    File(string n):name(n){}
    void display() override{ 
        cout<<"Plik: "<<name<<"\n"; 
    }
};

class Directory: public FileSystemComponent{
    private:
    string name;
    vector<FileSystemComponent*> components;

    public:
    Directory(string n):name(n){} 
    void add(FileSystemComponent* component){
        components.push_back(component); 
    }

    void display() override{
        cout<<"Katalog: "<<name<<"\n";
        for(auto c : components){
            c->display();
        }
    }
};

//------------PROXY-----------------
// Interfejs dostępu do danych
class DataAccess{
    public:
    virtual void requestData()=0;
};

// Klasa rzeczywista (RealSubject)
class RealDataAccess: public DataAccess{
    public:
    void requestData() override{
        cout<<"Dostep do danych uzyskany.\n";
    }
};

// Klasa Proxy
class DataAccessProxy: public DataAccess{
    private:
    RealDataAccess* realDataAccess;
    string user_role;

    public:
    DataAccessProxy(string role): user_role(role), realDataAccess(nullptr){}

    void requestData() override{
        if("ADMIN"==user_role){
            if(realDataAccess == nullptr) 
                realDataAccess = new RealDataAccess();
            cout<<"[Log]: Autoryzacja pozytywna.\n";
            realDataAccess->requestData();
        } 
        else{
            cout<<"[Log]: Odmowa dostepu dla roli: "<<user_role<<"\n";
        }
    }

    ~DataAccessProxy(){
        if(realDataAccess != nullptr){
            delete realDataAccess;
        }
    }
};

// Klient
int main(){
    //------------ADAPTER-----------------
    PaymentProcessor paymentProcessor;
    PaymentAdapter paymentAdapter;

    paymentProcessor.addPayment(199.15);
    paymentAdapter.processPayment(199.15);

    //------------DECORATOR-----------------
    Window* window = new Scrolling_decorator(new Frame_decorator(new SimpleWindow()));
    window->display_window();
    cout<<'\n';

    delete window;

    //------------FACADE-----------------
    FlightFacade facade;
    facade.bookFlight("Monachium");

    //------------COMPOSITE-----------------
    Directory* root = new Directory("ROOT");
    root->add(new File("notatki.txt"));
        
    Directory* music = new Directory("Muzyka");
    music->add(new File("song1.mp3"));
        
    root->add(music);
    root->display();

    delete root;

    //------------PROXY-----------------
    // Dostęp dozwolony
    DataAccessProxy adminProxy("ADMIN");
    adminProxy.requestData();

    // Dostęp zabroniony
    DataAccessProxy guestProxy("GUEST");
    guestProxy.requestData();

    return 0;
}