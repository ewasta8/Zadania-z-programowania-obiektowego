import java.util.ArrayList;

abstract class Pojazd{
    public abstract void przyspiesz();
    public abstract void zatrzymaj();
}

class Samochod extends Pojazd{
    @Override
    public void przyspiesz(){
        System.out.println("Samochod przyspiesza");
    }
    @Override
    public void zatrzymaj(){
        System.out.println("Samochod sie zatrzymuje");
    }
}

class Rower extends Pojazd{
    @Override
    public void przyspiesz(){
        System.out.println("Rower przyspiesza");
    }
    @Override
    public void zatrzymaj(){
        System.out.println("Rower sie zatrzymuje");
    }
}

class Motocykl extends Pojazd{
    @Override
    public void przyspiesz(){
        System.out.println("Motocykl przyspiesza");
    }
    @Override
    public void zatrzymaj(){
        System.out.println("Motocykl sie zatrzymuje");
    }
}

public class Lab6_Java {
    public static void main(String[] args){
        ArrayList<Pojazd> a = new ArrayList<Pojazd>();
        Samochod s1=new Samochod();
        Rower r=new Rower();
        Samochod s2=new Samochod();
        Motocykl m=new Motocykl();
        a.add(s1);
        a.add(r);
        a.add(s2);
        a.add(m);
        for(int i=0;i<a.size();i++){
            a.get(i).przyspiesz();
            a.get(i).zatrzymaj();
        }
    }
}