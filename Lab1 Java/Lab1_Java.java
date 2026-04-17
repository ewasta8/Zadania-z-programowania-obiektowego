import java.time.Year;

class Car{
    String make;
    String model;
    int year;

    int currentYear=Year.now().getValue();

    //constructor
    Car(String make, String model, int year){
        this.make=make;
        this.model=model;
        this.year=year;
    }

    void displayInfo(){
        System.out.println(make + ' ' + model + ' ' + year);
    }

    int getCarAge(){
        return currentYear-year;
    }

    boolean isSameCar(Car otherCar){
        if(make==otherCar.make && model==otherCar.model && year==otherCar.year)
            return true;
        return false;
    }
}

public class Lab1_Java{
    public static void main(String[] args) {
        Car myCar = new Car("Ford","Mustang",1970);
        Car myCar1 = new Car("Ford","Focus",2012);
        myCar.displayInfo();
        System.out.println("Age: " + myCar.getCarAge());
        if(myCar.isSameCar(myCar1))
            System.out.println("Samochody sa takie same");
        else
            System.out.println("Samochody sa rozne");
    }
}