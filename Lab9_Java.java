import java.util.ArrayList;
import java.util.List;
//------------ADAPTER-----------------
// Istniejący system
class LegacyPaymentProcessor{
    public void makePayment(int zlote, int grosze){
        System.out.println("Legacy System: Przetworzono "+zlote+"."+grosze+" PLN.");
    }
}

// Interfejs płatności
interface PaymentProcessor{
    void processPayment(double amount);
}

// Adapter
class PaymentAdapter implements PaymentProcessor{
    private LegacyPaymentProcessor legacyPaymentProcessor;

    public PaymentAdapter(){
        this.legacyPaymentProcessor = new LegacyPaymentProcessor();
    }

    @Override
    public void processPayment(double amount){
        int amount_z=(int)amount;
        int amount_g=(int)((amount-amount_z)*100);
        legacyPaymentProcessor.makePayment(amount_z, amount_g);
    }
}

//------------DECORATOR-----------------
// Interfejs okna
interface Window{
    void display_window();
}

// Klasa bazowa
class SimpleWindow implements Window{
    @Override
    public void display_window() {
        System.out.print("Window");
    }
}

// Dekorator
abstract class Window_decorator implements Window{
    protected Window decorated_window;
    public Window_decorator(Window window) {
        this.decorated_window = window;
    }

    @Override
    public void display_window(){
        decorated_window.display_window();
    }
}
   
// Konkretne dekoratory
class Frame_decorator extends Window_decorator{
    public Frame_decorator(Window decorated_window){
        super(decorated_window);
    }
    @Override
    public void display_window(){
        super.display_window();
        System.out.print(" + frame");
    }
}

class Scrolling_decorator extends Window_decorator{
    public Scrolling_decorator(Window decorated_window){
        super(decorated_window);
    }
    @Override
    public void display_window(){
        super.display_window();
        System.out.print(" + scrolling");
    }
}

//------------FACADE-----------------
class FlightSearch{
    public void search(String flight){
        System.out.println("Searching: "+flight);
    }
}

class BookingSystem{
    public void book(){
        System.out.println("Booking flight");
    }
}

class FlightPayment{
    public void pay(){
        System.out.println("Processing payment");
    }
}

class FlightFacade{
    private FlightSearch flightSearch;
    private BookingSystem bookingSystem;
    private FlightPayment flightPayment;

    public FlightFacade(){
        this.flightSearch = new FlightSearch();
        this.bookingSystem = new BookingSystem();
        this.flightPayment = new FlightPayment();
    }
    public void bookFlight(String flight){
        flightSearch.search(flight);
        bookingSystem.book();
        flightPayment.pay();
    }
}

//------------COMPOSITE-----------------
interface FileSystemComponent{
    void display();
}

class File implements FileSystemComponent{
    private String name;
    public File(String name){
        this.name = name; 
    }
    @Override
    public void display(){ 
        System.out.println("Plik: " + name); 
    }
}

class Directory implements FileSystemComponent{
    private String name;
    private List<FileSystemComponent> components = new ArrayList<>();

    public Directory(String name){ 
        this.name = name; 
    }
    public void add(FileSystemComponent component){
        components.add(component); 
    }

    @Override
    public void display(){
        System.out.println("Katalog: " + name);
        for(FileSystemComponent c : components){
            c.display();
        }
    }
}

//------------PROXY-----------------
// Interfejs dostępu do danych
interface DataAccess{
    void requestData();
}

// Klasa rzeczywista (RealSubject)
class RealDataAccess implements DataAccess{
    @Override
    public void requestData(){
        System.out.println("Dostęp do danych uzyskany.");
    }
}

// Klasa Proxy
class DataAccessProxy implements DataAccess{
    private RealDataAccess realDataAccess;
    private String user_role;

    public DataAccessProxy(String role) { this.user_role = role; }

    @Override
    public void requestData(){
        if("ADMIN".equals(user_role)){
            if(realDataAccess == null) 
                realDataAccess = new RealDataAccess();
            System.out.println("[Log]: Autoryzacja pozytywna.");
            realDataAccess.requestData();
        } 
        else{
            System.out.println("[Log]: Odmowa dostępu dla roli: " + user_role);
        }
    }
}

// Klient
public class Lab9_Java {
    public static void clientCode(PaymentProcessor paymentProcessor){
        paymentProcessor.processPayment(199.15);
    }

    public static void main(String[] args) {
        // Using the Adapter
        PaymentAdapter adapter = new PaymentAdapter();
        clientCode(adapter);

        //Decorator
        Window window = new SimpleWindow();
        window.display_window();
        System.out.println();
        window = new Frame_decorator(window);
        window.display_window();
        System.out.println();
        window = new Scrolling_decorator(window);
        window.display_window();
        System.out.println();

        //Facade
        FlightFacade facade = new FlightFacade();
        facade.bookFlight("Monachium");

        //Composite
        Directory root = new Directory("ROOT");
        root.add(new File("notatki.txt"));
        
        Directory music = new Directory("Muzyka");
        music.add(new File("song1.mp3"));
        
        root.add(music);
        root.display();

        //Proxy
        // Dostęp dozwolony
        DataAccess adminAccess = new DataAccessProxy("ADMIN");
        adminAccess.requestData();

        // Dostęp zabroniony
        DataAccess userAccess = new DataAccessProxy("GUEST");
        userAccess.requestData();
    }
}
