abstract class Pojazd{
    private String marka;
    private String model;
    /*public void przyspiesz(){
        System.out.println("Pojazd przyspiesza");
    }*/
    public Pojazd(String marka, String model){
        this.marka=marka;
        this.model=model;
    }
    abstract public void przyspiesz();
};

class Samochod extends Pojazd{
    public Samochod(String ma,String mo){
        super(ma,mo);
    }
    @Override
    public void przyspiesz(){
        System.out.println("Samochod przyspiesza");
    }
};

class Rower extends Pojazd{
    public Rower(String ma,String mo){
        super(ma,mo);
    }
    @Override
    public void przyspiesz(){
        System.out.println("Rower przyspiesza");
    }
};

interface Silnikowy{
    void przyspiesz();
}

interface Elektryczny{
    void ladowanie();
}

class Hybrydowy implements Silnikowy, Elektryczny{
    @Override
    public void przyspiesz(){
        System.out.println("Pojazd hybrydowy przyspiesza");
    } 
    @Override
    public void ladowanie(){
        System.out.println("Pojazd sie laduje");
    } 
}

public class Lab5_6_Java {
    public static void main(String[] args){
        //Pojazd p = new Pojazd();
        /*Samochod s = new Samochod("Ford","Focus");
        Rower r = new Rower();
        //p.przyspiesz();
        s.przyspiesz();
        r.przyspiesz();*/
        Hybrydowy h = new Hybrydowy();
        h.przyspiesz();
        h.ladowanie();
    }
    
}