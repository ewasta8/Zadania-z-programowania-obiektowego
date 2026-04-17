#include <iostream>
#include <memory>

using namespace std;

//--------------------------------------------------
//SINGLETON
class DatabaseConnection{
private:
    static DatabaseConnection* instance;
    DatabaseConnection(){
        cout<<"Utworzono polaczenie z baza danych.\n";
    }

    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

public:
    static DatabaseConnection* getInstance(){
        if(instance == nullptr)
            instance = new DatabaseConnection();
        return instance;
    }

    void executeQuery(const string& query){
        cout<<"Wykonuje zapytanie: "<<query<<" uzywajac jednej instancji.\n";
    }
      
};

DatabaseConnection* DatabaseConnection::instance = nullptr;

//--------------------------------------------------
//FACTORY METHOD
class Vehicle{
    public:
    virtual void drive()=0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle{
    public:
    void drive() override{
        cout<<"Auto rusza.\n";
    }
};

class Bike : public Vehicle{
    public:
    void drive() override{
        cout<<"Rower rusza.\n";
    }
};

class VehicleFactory{
    public:
    unique_ptr<Vehicle> createVehicle(const string& type){
        if(type == "CAR")
            return make_unique<Car>();
        else if (type == "BIKE")
            return make_unique<Bike>();
        return nullptr;
    }
};

//--------------------------------------------------
//BUILDER
class Pizza{
    private:
    string dough_;
    bool sauce_;
    string topping_;

    Pizza(const string& d, bool s, const string& t): dough_(d), sauce_(s), topping_(t) {}

    public:
    class Builder{
        private:
        string dough_;
        bool sauce_;
        string topping_;

        public:
        Builder& setDough(const string& dough){
            dough_=dough;
            return *this;
        }

        Builder& setSauce(){
           sauce_=true;
           return *this;
        }

        Builder& setTopping(const string& topping){
           topping_=topping;
           return *this;
        }

        Pizza build(){
            return Pizza(dough_, sauce_, topping_);
        }
    };

    void display() const{
        cout<<"Pizza{ciasto=\'"<<dough_<<"\', sos=\'"<<(sauce_ ? "tak" : "nie")<<"\', dodatek=\'"<<topping_<<"\'}\n";
    }
};

int main(){
    //--------------------------------------------------
    //SINGLETON
    cout<<"--- SINGLETON ---\n";
    DatabaseConnection* connection1 = DatabaseConnection::getInstance();
    DatabaseConnection* connection2 = DatabaseConnection::getInstance();

    connection1->executeQuery("SELECT * FROM users");

    cout<<"--- Weryfikacja ---\n";
    cout<<"connection1 hash: "<<connection1<<'\n';
    cout<<"connection2 hash: "<<connection2<<'\n';
    cout<<"Czy obie instancje sa takie same? "<<(connection1 == connection2)<<'\n';

    //--------------------------------------------------
    //FACTORY METHOD
    cout<<"\n--- FACTORY METHOD ---\n";
    VehicleFactory factory;

    // Klient używa metody fabrycznej, aby uzyskać obiekty
    unique_ptr<Vehicle> car = factory.createVehicle("CAR");
    if(car)
        car->drive();

    unique_ptr<Vehicle> bike = factory.createVehicle("BIKE");
    if(bike)
        bike->drive();

    //--------------------------------------------------
    //BUILDER
    cout<<"\n--- BUILDER ---\n";
    Pizza margarita = Pizza::Builder()
        .setDough("klasyczne")
        .setSauce()
        .build();
    
    Pizza pepperoni = Pizza::Builder()
        .setDough("grube")
        .setSauce()
        .setTopping("pepperoni")
        .build();

    Pizza simple = Pizza::Builder()
        .setTopping("grzyby i szpinak")
        .build();

    margarita.display();
    pepperoni.display();
    simple.display();
    return 0;
}