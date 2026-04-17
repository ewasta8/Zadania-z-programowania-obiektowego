#include <iostream>
#include <vector>

using namespace std;

// Klasa użytkownika
class User{
    private:
    string name;
    string email;
   
    public:
    User(string n,string e): name(n),email(e){}

};

// Klasa odpowiedzialna za zapis użytkownika
class UserSaver{
    public:
    void saveUser(const User& user){
        users.push_back(user);
    }
    vector<User> users = {};
};

// Interfejs rabatu
class Discount{
    public:
    virtual double discount(double price)=0;
};

// Regularny rabat
class RegularDiscount : public Discount{    // 10% rabatu
    private:
    double m=0.1;
    public:
    double discount(double price){
        return price*m;
    }                   
};

// Sezonowy rabat
class SeasonalDiscount : public Discount{       // 20% rabatu
    private:
    double m=0.2;
    public:
    double discount(double price){
        return price*m;
    }               
};

class Rectangle{
    public:
    double width;
    double height;
    Rectangle(double w, double h): width(w), height(h){}

    void setWidth(double w){
        width=w;
    }
    void setHeight(double h){
       height=h;
    }
    double getArea(){
        return width*height;
    }
};

class Square:public Rectangle{
    public:
    Square(double size): Rectangle(size,size){}

    void setHeight(double h){
        width=height=h;
    }
};

class Printer{
    public:
    void print(string file);
};

class DocumentScanner{
    public:
    string scan();
};

class MultiFunctionMachine: public Printer, public DocumentScanner{
    public:
    void print(string file){
        cout<<file;
    }
    string scan(){
        string file;
        cin>>file;
        return file;
    }
};

class MessageService{
    public:
    virtual void sendMessage(string message)=0;
};

class EmailService: public MessageService{
    public:
    void sendMessage(string message){
        cout<<"Wyslano email: "<<message;
    }
};

class Notification{
    private:
    MessageService& messageService; 
    public:
    Notification(MessageService& m): messageService(m){}
    void notify(string  message){
       messageService.sendMessage(message);
    }
};

int main(){
    User user("julia","julia@poczta.com");
    User user1("andrzej","andrzej@poczta.com");
    User user2("kasia","kasia@poczta.com");

    UserSaver saver;

    saver.saveUser(user);
    saver.saveUser(user1);
    saver.saveUser(user2);  

    EmailService e;
    Notification notification(e);
    notification.notify("Witaj w SOLID!");
    return 0;
}