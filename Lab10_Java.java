import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

//---------------OBSERVER-------------------
interface Observer{
    void update(String notification);
}

class User implements Observer{
    private String notification;

    @Override
    public void update(String notification){
        this.notification = notification;
        display();
    }

    private void display(){
        System.out.println("New notification: " + notification);
    }
}

class NotificationService{
    private List<Observer> observers = new ArrayList<>();
    private String notification;

    public void addObserver(Observer observer){
        observers.add(observer);
    }

    public void removeObserver(Observer observer){
        observers.remove(observer);
    }

    public void setNotification(String notification){
        this.notification = notification;
        notifyObservers();
    }

    private void notifyObservers(){
        for(Observer observer : observers){
            observer.update(notification);
        }
    }
}

//---------------STRATEGY-------------------
interface SortingStrategy{
    void sort(int[] array);
}

class SortingContext{
    private SortingStrategy sortingStrategy;

    public SortingContext(SortingStrategy sortingStrategy){
        this.sortingStrategy = sortingStrategy;
    }

    public void setSortingStrategy(SortingStrategy sortingStrategy){
        this.sortingStrategy = sortingStrategy;
    }

    public void performSort(int[] array){
        sortingStrategy.sort(array);
    }
}

class AscendingSortStrategy implements SortingStrategy{
    @Override
    public void sort(int[] array){
        Arrays.sort(array);
        System.out.println("Sorting ascending: "+Arrays.toString(array));
    }
}

class DescendingSortStrategy implements SortingStrategy{
    @Override
    public void sort(int[] array){
        Arrays.sort(array);
        for(int i=0;i<array.length/2;i++){
            int temp=array[i];
            array[i] = array[array.length-1-i];
            array[array.length-1-i] = temp;
        }
        System.out.println("Sorting descending: "+Arrays.toString(array));
    }
}

//---------------COMMAND-------------------
interface Command{
    void execute();
}

class UndoCommand implements Command{
    private Application application;

    public UndoCommand(Application application){
        this.application = application;
    }

    @Override
    public void execute(){
        application.undo();
    }
}

class RedoCommand implements Command{
    private Application application;

    public RedoCommand(Application application){
        this.application = application;
    }

    @Override
    public void execute(){
        application.redo();
    }
}

interface Application{
    void undo();
    void redo();
}


class Paint implements Application{
    @Override
    public void undo(){
        System.out.println("Using undo in Paint");
    }

    @Override
    public void redo(){
        System.out.println("Using redo in paint");
    }

}

class RemoteControl{
    private Command command;

    public void setCommand(Command command){
        this.command = command;
    }

    public void pressButton(){
        command.execute();
    }
}

//---------------STATE-------------------
interface ATM_state{
    void handleRequest();
}

class AwaitingCardState implements ATM_state{
    @Override
    public void handleRequest(){
        System.out.println("Awaiting card state: Please insert card.");
    }
}

class VerificationState implements ATM_state{
    @Override
    public void handleRequest(){
        System.out.println("Verificating PIN state: Please wait.");
    }
}

class CashWithdrawalState implements ATM_state{
    @Override
    public void handleRequest(){
        System.out.println("Cash withdrawal state: Please collect you money.");
    }
}

class ATM_context{
    private ATM_state state;

    public void setState(ATM_state state){
        this.state = state;
    }

    public void request(){
        state.handleRequest();
    }
}

//---------------CHAIN OF RESPONSIBILITY-------------------
interface SupportHandler{
    void handleRequest(Request request);
    void setNextHandler(SupportHandler nextHandler);
}

class Consultant implements SupportHandler{
    private SupportHandler nextHandler;

    public void setNextHandler(SupportHandler nextHandler){
        this.nextHandler = nextHandler;
    }

    public void handleRequest(Request request){
        if(request.getPriority() == Priority.BASIC){
            System.out.println("Consultant handled the request.");
        } 
        else if(nextHandler != null){
            nextHandler.handleRequest(request);
        }
    }
}

class Manager implements SupportHandler{
    private SupportHandler nextHandler;

    public void setNextHandler(SupportHandler nextHandler){
        this.nextHandler = nextHandler;
    }

    public void handleRequest(Request request){
        if(request.getPriority() == Priority.INTERMEDIATE){
            System.out.println("Manager handled the request.");
        } 
        else if(nextHandler != null){
            nextHandler.handleRequest(request);
        }
    }
}

class TechnicalDepartment implements SupportHandler{
    public void handleRequest(Request request){
        if(request.getPriority() == Priority.CRITICAL){
            System.out.println("Technical Department handled the request.");
        } 
        else{
            System.out.println("Request cannot be handled.");
        }
    }

    public void setNextHandler(SupportHandler nextHandler){
        // No next handler for Technical Department
    }
}

class Request{
    private Priority priority;

    public Request(Priority priority){
        this.priority = priority;
    }

    public Priority getPriority(){
        return priority;
    }
}

enum Priority{
    BASIC, INTERMEDIATE, CRITICAL
}

public class Lab10_Java{
    public static void main(String[] args) {
        //---------------OBSERVER-------------------
        NotificationService notificationService = new NotificationService();
        User user = new User();
        notificationService.addObserver(user);
        notificationService.setNotification("Nowa wiadomość");
        notificationService.setNotification("Niski poziom baterii");
        notificationService.removeObserver(user);
        notificationService.setNotification("Dostępna aktualizacja oprogramowania");

        //---------------STRATEGY-------------------
        SortingContext sortingContext = new SortingContext(new AscendingSortStrategy());
        int[] array1 = {5, 2, 9, 1, 5};
        sortingContext.performSort(array1);

        sortingContext.setSortingStrategy(new DescendingSortStrategy());
        int[] array2 = {8, 3, 7, 4, 2};
        sortingContext.performSort(array2);

        //---------------COMMAND-------------------
        Paint paint = new Paint();

        Command undoPaintCommand = new UndoCommand(paint);
        Command redoPaintCommand = new RedoCommand(paint);
        
        RemoteControl remote = new RemoteControl();

        remote.setCommand(undoPaintCommand);
        remote.pressButton();

        remote.setCommand(redoPaintCommand);
        remote.pressButton();

        //---------------STATE-------------------
        ATM_context atm = new ATM_context();
        atm.setState(new AwaitingCardState());
        atm.request();
        atm.setState(new VerificationState());
        atm.request();
        atm.setState(new CashWithdrawalState());
        atm.request();

        //---------------CHAIN OF RESPONSIBILITY-------------------
        SupportHandler consultant = new Consultant();
        SupportHandler manager = new Manager();
        SupportHandler technicalDepartment = new TechnicalDepartment();

        consultant.setNextHandler(manager);
        manager.setNextHandler(technicalDepartment);

        Request request1 = new Request(Priority.BASIC);
        Request request2 = new Request(Priority.INTERMEDIATE);
        Request request3 = new Request(Priority.CRITICAL);

        consultant.handleRequest(request1);
        consultant.handleRequest(request2);
        consultant.handleRequest(request3);
    }
}