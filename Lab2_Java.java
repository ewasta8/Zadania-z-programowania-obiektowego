import java.util.List;
import java.util.ArrayList;

class Samochod{
    String marka;
    String model;
    int rokProdukcji;

    Samochod()
    {
        this.marka="Ford";
        this.model="Mustang";
        this.rokProdukcji=1970;
    }

    Samochod(String marka, String model, int rokProdukcji){
        this.marka = marka;
        this.model = model;
        this.rokProdukcji = rokProdukcji;
    }
}

class Tablica{
    List<Integer> tab;

    Tablica(){
        tab = new ArrayList<>(10);
    }

    Tablica(int n){
        tab = new ArrayList<>(n);
    }
}

public class Lab2_Java {
    public static void main(String[] args){
        Samochod myCar = new Samochod("Ford","Focus",2012);
        Tablica myTab = new Tablica();
        Tablica myTab2 = new Tablica(3);
    }
}
