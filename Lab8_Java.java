//--------------------------------------------------
//SINGLETON
class DatabaseConnection{
    private static DatabaseConnection single_instance = null;
    private DatabaseConnection(){
        System.out.println("Utworzono połączenie z bazą danych.");
    }

    public static DatabaseConnection getInstance(){
        if(single_instance == null)
            single_instance = new DatabaseConnection();
        return single_instance;
    }

    public void executeQuery(String query){
        System.out.println("Wykonuję zapytanie: " + query + " używając jednej instancji.");
    }
}

//--------------------------------------------------
//FACTORY METHOD
abstract class Vehicle{
    public abstract void drive();
}

class Car extends Vehicle{
    @Override
    public void drive(){
        System.out.println("Auto rusza.");
    }
}

class Bike extends Vehicle{
    @Override
    public void drive(){
        System.out.println("Rower rusza.");
    }
}

class VehicleFactory{
    public Vehicle createVehicle(String type){
        if(type.equalsIgnoreCase("CAR"))
            return new Car();
        else if(type.equalsIgnoreCase("BIKE"))
            return new Bike();
        else
            throw new IllegalArgumentException("Nieznany typ pojazdu: " + type);
    }
}

//--------------------------------------------------
//BUILDER
class Pizza{
    private String name;
    private String dough;
    private boolean sauce;
    private String topping;
    private Pizza(PizzaBuilder builder){
        this.name = builder.name;
        this.dough = builder.dough;
        this.sauce = builder.sauce;
        this.topping = builder.topping;
    }

    public static class PizzaBuilder{
        private String name;
        private String dough;
        private boolean sauce;
        private String topping;

        public PizzaBuilder(String name){
            this.name = name;
        }
        public PizzaBuilder dough(String dough){
            this.dough = dough;
            return this;
        }
        public PizzaBuilder sauce(){
            this.sauce = true;
            return this;
        }
        public PizzaBuilder topping(String topping){
            this.topping = topping;
            return this;
        }

        public Pizza build(){
            return new Pizza(this);
        }
    }

    @Override
    public String toString(){
        return "Pizza{" +"name='" + name + '\'' +", ciasto='" + dough + '\'' +", sos=" + (sauce ? "tak" : "nie") +", dodatek='" + topping + '\''+'}';
    }
}

public class Lab8_Java{
    public static void main(String[] args){
        //-------------------------------------------------
        //SINGLETON
        System.out.println("--- SINGLETON ---");
        DatabaseConnection connection1 = DatabaseConnection.getInstance();
        DatabaseConnection connection2 = DatabaseConnection.getInstance();

        connection1.executeQuery("SELECT * FROM users");

        System.out.println("--- Weryfikacja ---");
        System.out.println("connection1 hash: " + connection1.hashCode());
        System.out.println("connection2 hash: " + connection2.hashCode());
        System.out.println("Czy obie instancje są takie same? " + (connection1 == connection2));

        //--------------------------------------------------
        //FACTORY METHOD
        System.out.println("\n--- FACTORY METHOD ---");
        VehicleFactory factory = new VehicleFactory();

        // Klient żąda obiektu, nie znając jego konkretnej klasy
        Vehicle car = factory.createVehicle("CAR");
        car.drive();

        Vehicle bike = factory.createVehicle("BIKE");
        bike.drive();

        //--------------------------------------------------
        //BUILDER
        System.out.println("\n--- BUILDER ---");
        Pizza margarita = new Pizza.PizzaBuilder("Margarita")
            .dough("klasyczne")
            .sauce()
            .build();

        Pizza pepperoni = new Pizza.PizzaBuilder("Pepperoni")
            .dough("grube")
            .sauce()
            .topping("pepperoni")
            .build();
        
        Pizza custom = new Pizza.PizzaBuilder("Custom wegetariańska")
            .topping("grzyby i szpinak")
            .build();

        System.out.println(margarita);
        System.out.println(pepperoni);
        System.out.println(custom);
    }
}