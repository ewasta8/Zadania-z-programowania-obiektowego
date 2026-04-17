interface Pojazd{
    void przyspiesz();
}

interface Silnikowy extends Pojazd{
    void przyspiesz();
}

interface Elektryczny extends Pojazd{
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

public class Lab5_10_Java {
    public static void main(String[] args){
        Hybrydowy h=new Hybrydowy();
        h.przyspiesz();
    }
}