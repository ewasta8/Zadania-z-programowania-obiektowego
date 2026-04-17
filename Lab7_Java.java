import java.util.ArrayList;

class User{
    String name;
    String email;

    public User(String name, String email){
        this.name = name;
        this.email = email;
    }

    public String getName(){
        return name;
    }

    public String getEmail(){
       return email;
    }
}

// Klasa odpowiedzialna za zapis użytkownika
class UserSaver{
    ArrayList<User> users = new ArrayList<>();
    public void saveUser(User user){
        users.add(user);
    }
}

interface Discount{
    double discount(double price);
}

class RegularDiscount implements Discount{       // 10% rabatu
    double m=0.1;
    public double discount(double price){
        return price*m;
    }           
}

class SeasonalDiscount implements Discount{     // 20% rabatu
    double m=0.2;
    public double discount(double price){
        return price*m;                       
    }
}

class Rectangle{
    double width;
    double height;
    public Rectangle(double width, double height){
        this.width = width;
        this.height = height;
    }

    public void setWidth(double w){
        width=w;
    }

    public void setHeight(double h){
       height=h;
    }

    public double getArea(){
        return width*height;
    }
}

class Square extends Rectangle{
    public Square(double size){
        super(size, size);
    }

    @Override
    public void setHeight(double h) {
        this.width = this.height = h;
    }
}

interface Printer{
    void print(String file);
}

interface DocumentScanner{
    String scan();
}

class MultiFunctionMachine implements Printer, DocumentScanner{
    @Override
    public void print(String file){
        System.out.println(file);
    }
    @Override
    public String scan(){
        java.util.Scanner sc = new java.util.Scanner(System.in);
        String file=sc.nextLine();
        return file;
    }
}

interface MessageService{
    void sendMessage(String message);
}

class EmailService implements MessageService{
    @Override
    public void sendMessage(String message){
        System.out.println("Wysłano email: "+message);
    }
}

class Notification{
    private MessageService messageService; 
    public Notification(MessageService messageService){
        this.messageService = messageService;
    }

    public void notify(String  message){
       messageService.sendMessage(message);
    }
}

public class Lab7_Java{
    public static void main(String[] args){
        User user=new User("julia","julia@poczta.com");
        User user1=new User("andrzej","andrzej@poczta.com");
        User user2=new User("kasia","kasia@poczta.com");

        UserSaver saver=new UserSaver();

        saver.saveUser(user);
        saver.saveUser(user1);
        saver.saveUser(user2);  

        EmailService e=new EmailService();
        Notification notification=new Notification(e);
        notification.notify("Witaj w SOLID!");
    }
}