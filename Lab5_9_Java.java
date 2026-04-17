abstract class Pojazd{
    protected String marka;
    protected String model;

    abstract public void przyspiesz();
}

class Samochod extends Pojazd{
    @Override
    public void przyspiesz(){
        System.out.println("Samochod przyspiesza");
    }
}

class ElektrycznySamochod extends Samochod{
    @Override
    public void przyspiesz(){
        System.out.println("Samochod elektryczny przyspiesza");
    }
}

public class Lab5_9_Java {
    public static void main(String[] args){
        Samochod s=new Samochod();
        ElektrycznySamochod e=new ElektrycznySamochod();
        e.przyspiesz();
    }
}