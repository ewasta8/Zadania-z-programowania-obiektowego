abstract class Pojazd{
    protected String marka;
    protected String model;
    /*public void przyspiesz(){
        System.out.println("Pojazd przyspiesza");
    }*/
    abstract public void przyspiesz();
};

class Samochod extends Pojazd{
    @Override
    public void przyspiesz(){
        System.out.println("Samochod przyspiesza");
    }
};

class Rower extends Pojazd{
    @Override
    public void przyspiesz(){
        System.out.println("Rower przyspiesza");
    }
};

public class Lab5_Java {
    public static void main(String[] args){
        //Pojazd p = new Pojazd();
        Samochod s = new Samochod();
        Rower r = new Rower();
        //p.przyspiesz();
        s.przyspiesz();
        r.przyspiesz();
        s.marka="Ford";
        System.out.println(s.marka);
    }
    
}