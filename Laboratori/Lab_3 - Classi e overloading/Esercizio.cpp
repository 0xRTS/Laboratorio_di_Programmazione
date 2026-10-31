#include <iostream>

using namespace std;

class Rational{
    private:
        int numerator;
        int denominator;
        bool is_valid();

    public:
        Rational(); //A
        Rational(int value); //B
        Rational(int num, int den); //C

        int get_numerator() const{
            return numerator;
        }

        int get_denominator() const{
            return denominator;
        }

        class Invalid{}; //Per riportare gli errori

        //Member functions
        Rational operator=(const Rational& r);
        Rational operator=(const int r); 

        //Mettere const dopo la funzione garantisce che l'oggetto chiamante non venga modificato
        Rational operator+(const Rational& r) const;
        Rational operator+(const int r) const; 

        Rational operator-(const Rational& r) const;
        Rational operator-(const int r) const; 

        Rational operator*(const Rational& r) const;
        Rational operator*(const int r) const; 

        Rational operator/(const Rational& r) const;
        Rational operator/(const int r) const; 

        bool operator==(const Rational& r) const;
        bool operator==(const int r) const;

        bool operator<(const Rational& r) const;
        bool operator<(const int r) const;

        bool operator>(const Rational& r) const;
        bool operator>(const int r) const;

        double to_double(){
            return static_cast<double>(numerator) / denominator;
        }
};

//Funzioni definite fuori dalla classe ==> Le funzioni NON sono inline 
//Buona pratica definire le funzioni membro (private e public) fuori dalla classe (se richiedono più di 1 o 2 righe di codice)
//Helper function interagiscono con la classe ma non sono ne dichiarate ne definite in essa

Rational::Rational()
    : numerator{0}, denominator{1} 
{
}

Rational::Rational(int value) //B (costruttore come init list)
    : numerator{value}, denominator{1} 
{
    if(!is_valid()) throw Invalid();
}

Rational::Rational(int num, int den) //C (costruttore come init list)
    : numerator{num}, denominator{den} 
{
   if(!is_valid()) throw Invalid{};
}

bool Rational::is_valid(){ //Controlo validità denominatore
    if(denominator<=0){
        return false;
    }else{
        return true;
    }
}

Rational Rational::operator=(const Rational& r){
    numerator = r.numerator;
    denominator = r.denominator;
    return Rational{numerator, denominator};
}

Rational Rational::operator=(const int r){
    numerator = r;
    denominator = 1;
    return Rational{numerator, denominator};
}

Rational Rational::operator+(const Rational& r) const{
    int num = numerator * r.get_denominator() + denominator * r.get_numerator();
    int den = denominator * r.get_denominator();
    return Rational{num, den};
}

Rational Rational::operator+(const int r) const{
    int num = numerator + r*denominator;
    return Rational{num, denominator};
}

/*
Rational operator+(const Rational r1, const Rational r2){
    int num = r1.get_numerator() * r2.get_denominator() + r1.get_denominator() * r2.get_numerator();
    int den = r1.get_denominator() * r2.get_denominator(); 
    return Rational{num, den};
}*/

Rational Rational::operator-(const Rational& r) const{
    int num = numerator * r.get_denominator() - denominator * r.get_numerator();
    int den = denominator * r.get_denominator();
    return Rational{num, den};
}

Rational Rational::operator-(const int r) const{
    int num = numerator - r*denominator;
    return Rational{num, denominator};
}

/*
Rational operator-(const Rational r1, const Rational r2){
    int num = r1.get_numerator() * r2.get_denominator() - r1.get_denominator() * r2.get_numerator();
    int den = r1.get_denominator() * r2.get_denominator(); 
    return Rational{num, den};
}*/

Rational Rational::operator*(const Rational& r) const{
    int num = numerator * r.get_numerator();
    int den = denominator * r.get_denominator();
    return Rational{num, den};
}

Rational Rational::operator*(const int r) const{
    int num = numerator * r;
    return Rational{num, denominator};
}

/*
Rational operator*(const Rational r1, const Rational r2){
    int num = r1.get_numerator() * r2.get_numerator();
    int den = r1.get_denominator() * r2.get_denominator(); 
    return Rational{num, den};
}*/

Rational Rational::operator/(const Rational& r) const{
    int num = numerator * r.get_denominator();
    int den = denominator * r.get_numerator();
    return Rational{num, den};
}

Rational Rational::operator/(const int r) const{
    int den = denominator * r;
    return Rational{numerator, den};
}

/*
Rational operator/(const Rational r1, const Rational r2){
    int num = r1.get_numerator() * r2.get_denominator();
    int den = r1.get_denominator() * r2.get_numerator(); 
    return Rational{num, den};
}*/

bool Rational::operator==(const Rational& r) const{
    if(numerator*r.get_denominator() == denominator * r.get_numerator()){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator==(const int r) const{
    if(numerator == denominator * r){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator>(const Rational& r) const{
    if(numerator*r.get_denominator() > denominator * r.get_numerator()){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator>(const int r) const{
    if(numerator > denominator * r){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator<(const Rational& r) const{
    if(numerator*r.get_denominator() < denominator * r.get_numerator()){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator<(const int r) const{
    if(numerator < denominator * r){
        return true;
    }else{
        return false;
    }
}

//Per queste invece (>> e <<) che sono helper functions che vanno a modificare gli oggetti no metto const dopo la funzione
ostream& operator<<(ostream& os, const Rational& r){
    return os << r.get_numerator() << "/" << r.get_denominator();
}

istream& operator>>(istream& os, Rational& r){
    int num = 0;
    int den = 0;
    char ch = '.';

    os >> num >> ch >> den;

    if(ch!='/' || den <= 0){
        return os;
    }

    r = Rational{num, den};

    return os;
}

// Helper di test
int passed = 0, failed = 0;

void check(const string& nome, bool condizione){
    if(condizione){
        cout << "[OK]   " << nome << endl;
        passed++;
    }else{
        cout << "[FAIL] " << nome << endl;
        failed++;
    }
}

int main(){
    cout << "=== COSTRUTTORI ===" << endl;
    Rational a;              // A
    Rational b{5};           // B
    Rational c{3, 4};        // C
    check("A: default = 0/1", a.get_numerator()==0 && a.get_denominator()==1);
    check("B: int 5 = 5/1",   b.get_numerator()==5 && b.get_denominator()==1);
    check("C: 3/4",           c.get_numerator()==3 && c.get_denominator()==4);

    cout << "\n=== GETTER ===" << endl;
    check("get_numerator",   c.get_numerator()==3);
    check("get_denominator", c.get_denominator()==4);

    cout << "\n=== OPERATOR= ===" << endl;
    Rational d;
    d = c;
    check("= Rational", d.get_numerator()==3 && d.get_denominator()==4);
    d = 7;
    check("= int", d.get_numerator()==7 && d.get_denominator()==1);

    cout << "\n=== OPERATOR+ ===" << endl;
    Rational e = Rational{1,2} + Rational{1,3};   // 5/6
    check("+ Rational (1/2+1/3=5/6)", e.get_numerator()==5 && e.get_denominator()==6);
    Rational f = Rational{1,2} + 2;               // 5/2
    check("+ int (1/2+2=5/2)", f.get_numerator()==5 && f.get_denominator()==2);

    cout << "\n=== OPERATOR- ===" << endl;
    Rational g = Rational{1,2} - Rational{1,3};   // 1/6
    check("- Rational (1/2-1/3=1/6)", g.get_numerator()==1 && g.get_denominator()==6);
    Rational h = Rational{1,2} - 1;               // -1/2
    check("- int (1/2-1=-1/2)", h.get_numerator()==-1 && h.get_denominator()==2);

    cout << "\n=== OPERATOR* ===" << endl;
    Rational i = Rational{2,3} * Rational{3,4};   // 6/12
    check("* Rational (2/3*3/4=6/12)", i.get_numerator()==6 && i.get_denominator()==12);
    Rational j = Rational{2,3} * 3;               // 6/3
    check("* int (2/3*3=6/3)", j.get_numerator()==6 && j.get_denominator()==3);

    cout << "\n=== OPERATOR/ ===" << endl;
    Rational k = Rational{1,2} / Rational{3,4};   // 4/6
    check("/ Rational (1/2 / 3/4 = 4/6)", k.get_numerator()==4 && k.get_denominator()==6);
    Rational l = Rational{1,2} / 3;               // 1/6
    check("/ int (1/2 / 3 = 1/6)", l.get_numerator()==1 && l.get_denominator()==6);

    cout << "\n=== OPERATOR== ===" << endl;
    check("== Rational vero (1/2 == 2/4)",  Rational{1,2} == Rational{2,4});
    check("== Rational falso (1/2 != 1/3)", !(Rational{1,2} == Rational{1,3}));
    check("== int vero (4/2 == 2)",         Rational{4,2} == 2);
    check("== int falso (1/2 != 1)",        !(Rational{1,2} == 1));

    cout << "\n=== OPERATOR< ===" << endl;
    check("< Rational (1/3 < 1/2)",  Rational{1,3} < Rational{1,2});
    check("< Rational falso",        !(Rational{1,2} < Rational{1,3}));
    check("< int (1/2 < 1)",         Rational{1,2} < 1);
    check("< int falso (3/2 < 1)",   !(Rational{3,2} < 1));

    cout << "\n=== OPERATOR> ===" << endl;
    check("> Rational (1/2 > 1/3)",  Rational{1,2} > Rational{1,3});
    check("> Rational falso",        !(Rational{1,3} > Rational{1,2}));
    check("> int (3/2 > 1)",         Rational{3,2} > 1);
    check("> int falso (1/2 > 1)",   !(Rational{1,2} > 1));

    cout << "\n=== OPERATOR<< ===" << endl;
    cout << "Output atteso: 3/4 -> ";
    cout << Rational{3,4} << endl;

    cout << "\n=== OPERATOR>> ===" << endl;
    Rational input;
    cout << "Inserisci un razionale nel formato n/d (es. 5/8): ";
    cin >> input;
    cout << "Hai inserito: " << input << endl;

    cout << "\n=== RIEPILOGO ===" << endl;
    cout << "Passati: " << passed << "  Falliti: " << failed << endl;

    return 0;
}


/*Ovviamente definito nella classe 
Rational(int value) //B (costruttore come assegnamento)
{ //Prima dell'assegnamento esplicito avviene un assegnamento implicito che noi non vediamo
    numerator = value;
    denominator =  1;
}
*/