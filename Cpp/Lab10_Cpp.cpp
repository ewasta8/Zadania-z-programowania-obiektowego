#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// Interfejs obserwatora
class Observer{
    public:
    virtual void update(string notification)=0;
};

// Konkretna klasa obserwatora
class User : public Observer{
    private:
    string notification;

    public:
    void update(string notification) override{
        this->notification = notification;
        display();
    }

    private:
    void display(){
        cout<<"New notification: "<<notification<<"\n";
    }
};

// Klasa podmiotu
class NotificationService{
    private:
    vector<Observer*> observers;
    string notification;

    public:
    void addObserver(Observer* observer){
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer){
        observers.erase(find(observers.begin(), observers.end(), observer));
    }

    void setNotification(string notification){
        this->notification = notification;
        notifyObservers();
    }

    private:
    void notifyObservers(){
        for(Observer* observer : observers){
            observer->update(notification);
        }
    }
};

//---------------STRATEGY-------------------
class SortingStrategy{
    public:
    virtual void sort(vector<int>& array)=0;
};

class SortingContext{
    private:
    unique_ptr<SortingStrategy> sortingStrategy;

    public:
    SortingContext(unique_ptr<SortingStrategy> s): sortingStrategy(move(s)){}

    void setSortingStrategy(unique_ptr<SortingStrategy> s){
        sortingStrategy = move(s);
    }

    void performSort(vector<int>& array){
        sortingStrategy->sort(array);
    }
};

class AscendingSortStrategy: public SortingStrategy{
    public:
    void sort(vector<int>& array) override{
        std::sort(array.begin(), array.end());
        cout<<"Sorting ascending: ";
        for(int x : array) cout<<x<<" ";
        cout<<"\n";
    }
};

class DescendingSortStrategy: public SortingStrategy{
    public:
    void sort(vector<int>& array) override{
        std::sort(array.begin(), array.end(), greater<int>());
        cout<<"Sorting descending: ";
        for(int x : array) cout<<x<<" ";
        cout<<"\n";
    }
};

//---------------COMMAND-------------------
class Application{
    public:
    virtual void undo()=0;
    virtual void redo()=0;
};


class Paint: public Application{
    public:
    void undo() override{
        cout<<"Using undo in Paint\n";
    }

    void redo() override{
        cout<<"Using redo in Paint\n";
    }

};

class Command{
    public:
    virtual void execute()=0;
};

class UndoCommand: public Command{
    private:
    Application* application;

    public:
    UndoCommand(Application* a): application(a){}

    void execute() override{
        application->undo();
    }
};

class RedoCommand: public Command{
    private:
    Application* application;

    public:
    RedoCommand(Application* a): application(a){}

    void execute() override{
        application->redo();
    }
};

class RemoteControl{
    private:
    Command* command;

    public:
    void setCommand(Command* c){ command = c; }
    
    void pressButton(){
        command->execute();
    }
};

//---------------STATE-------------------
class ATM_state{
    public:
    virtual void handleRequest()=0;
};

class AwaitingCardState: public ATM_state{
    public:
    void handleRequest() override{
        cout<<"Awaiting card state: Please insert card.\n";
    }
};

class VerificationState: public ATM_state{
    public:
    void handleRequest() override{
        cout<<"Verificating PIN state: Please wait.\n";
    }
};

class CashWithdrawalState: public ATM_state{
    public:
    void handleRequest() override{
        cout<<"Cash withdrawal state: Please collect you money.\n";
    }
};

class ATM_context{
    private:
    unique_ptr<ATM_state> state;

    public:
    void setState(unique_ptr<ATM_state> s){
        state = move(s);
    }

    void request(){
        state->handleRequest();
    }
};

//---------------CHAIN OF RESPONSIBILITY-------------------
enum Priority{
    BASIC, INTERMEDIATE, CRITICAL
};

class Request{
    private:
    Priority priority;

    public:
    Request(Priority priority){
        this->priority = priority;
    }

    Priority getPriority(){
        return priority;
    }
};

class SupportHandler{
    public:
    virtual void handleRequest(Request& request)=0;
    virtual void setNextHandler(SupportHandler* nextHandler)=0;
    virtual ~SupportHandler() = default;
};

class Consultant: public SupportHandler{
    private:
    SupportHandler* nextHandler=nullptr;

    public:
    void setNextHandler(SupportHandler* nextHandler) override{
        this->nextHandler = nextHandler;
    }

    void handleRequest(Request& request){
        if(request.getPriority() == Priority::BASIC){
            cout<<"Consultant handled the request.\n";
        } 
        else if(nextHandler != nullptr){
            nextHandler->handleRequest(request);
        }
    }
};

class Manager: public SupportHandler{
    private:
    SupportHandler* nextHandler=nullptr;

    public:
    void setNextHandler(SupportHandler* nextHandler) override{
        this->nextHandler = nextHandler;
    }

    void handleRequest(Request& request){
        if(request.getPriority() == Priority::INTERMEDIATE){
            cout<<"Manager handled the request.\n";
        } 
        else if(nextHandler != nullptr){
            nextHandler->handleRequest(request);
        }
    }
};

class TechnicalDepartment: public SupportHandler{
    public:
    void handleRequest(Request& request){
        if(request.getPriority() == Priority::CRITICAL){
            cout<<"Technical Department handled the request.\n";
        } 
        else{
           cout<<"Request cannot be handled.\n";
        }
    }

    void setNextHandler(SupportHandler* nextHandler) override{
        // No next handler for Technical Department
    }
};

int main(){
    //---------------OBSERVER-------------------
    NotificationService notificationService;
    User user;
    notificationService.addObserver(&user);
    notificationService.setNotification("Nowa wiadomosc");
    notificationService.setNotification("Niski poziom baterii");
    notificationService.removeObserver(&user);
    notificationService.setNotification("Dostepna aktualizacja oprogramowania");

    //---------------STRATEGY-------------------
    SortingContext sortingContext(make_unique<AscendingSortStrategy>());

    vector<int> array1 = {5, 2, 9, 1, 5};
    sortingContext.performSort(array1);


    sortingContext.setSortingStrategy(make_unique<DescendingSortStrategy>());
    vector<int> array2 = {8, 3, 7, 4, 2};
    sortingContext.performSort(array2);

    //---------------COMMAND-------------------
    Paint paint; 

    UndoCommand undo(&paint);
    RedoCommand redo(&paint);
        
    RemoteControl remote;
    remote.setCommand(&undo);
    remote.pressButton();

    remote.setCommand(&redo);
    remote.pressButton();

    //---------------STATE-------------------
    ATM_context atm;
    atm.setState(make_unique<AwaitingCardState>());
    atm.request();
    atm.setState(make_unique<VerificationState>());
    atm.request();
    atm.setState(make_unique<CashWithdrawalState>());
    atm.request();

    //---------------CHAIN OF RESPONSIBILITY-------------------
    SupportHandler* consultant = new Consultant();
    SupportHandler* manager = new Manager();
    SupportHandler* technicalDepartment = new TechnicalDepartment();

    consultant->setNextHandler(manager);
    manager->setNextHandler(technicalDepartment);

    Request request1(Priority::BASIC);
    Request request2(Priority::INTERMEDIATE);
    Request request3(Priority::CRITICAL);

    consultant->handleRequest(request1);
    consultant->handleRequest(request2);
    consultant->handleRequest(request3);

    delete consultant;
    delete manager;
    delete technicalDepartment;
    return 0;
}