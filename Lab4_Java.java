class Osoba{
    private String imie;
    private String nazwisko;
    private int wiek;
    private String email;
    private String telefon;

    //set
    public void set_name(String imie){
        this.imie=imie;
    }
    public void set_surname(String nazwisko){
        this.nazwisko=nazwisko;
    }
    public void set_age(int wiek){
        this.wiek=wiek;
    }
    public void set_email(String e){
        if(e.contains("@"))
            email=e;
        else
            System.out.println("Bledny email");
    }
    public void set_telephone(String t){
        if(t.length()==9)
            telefon=t;
        else
            System.out.println("Bledny numer telefonu");
    }

    //get
    public String get_name(){
        return imie;
    }
    public String get_surname(){
        return nazwisko;
    }
    public int get_age(){
        return wiek;
    }
    public String get_email(){
        return email;
    }
    public String get_telephone(){
        return telefon;
    }
}

class Pracownik{
    protected String stanowisko;
    protected float wynagrodzenie;

    public Pracownik(String stanowisko, float wynagrodzenie){
        this.stanowisko=stanowisko;
        this.wynagrodzenie=wynagrodzenie;
    }
}

class Nauczyciel extends Pracownik{
    public Nauczyciel(String st, float wyn){
        super(st, wyn);
    }

    public void pokaz_dane(){
        System.out.println("stanowisko: "+stanowisko+'\n'+"wynagrodzenie: "+wynagrodzenie);
    }
}

class Administracja extends Pracownik{
    public Administracja(String st, float wyn){
        super(st, wyn);
    }
    public void pokaz_dane(){
        System.out.println("stanowisko: "+stanowisko+'\n'+"wynagrodzenie: "+wynagrodzenie);
    }
}

public class Lab4_Java {
    public static void main(String[] args){
        Osoba o = new Osoba();
        o.set_name("Kasia");
        //System.out.println(o.get_name());
        Nauczyciel n=new Nauczyciel("nauczyciel matematyki",3500);
        n.pokaz_dane();
    }
}