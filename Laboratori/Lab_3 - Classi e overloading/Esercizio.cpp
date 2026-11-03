#include <iostream>
#include <string>
#include <sstream>

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
        void operator=(const Rational& r);
        void operator=(const int r); 

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

/*definito nella classe 
Rational(int value) //B (costruttore come assegnamento)
{ //Prima dell'assegnamento esplicito avviene un assegnamento implicito che noi non vediamo
    numerator = value;
    denominator =  1;
}
*/

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

//-------------------------------------------------------------------------------------------------

void Rational::operator=(const Rational& r){
    numerator = r.numerator;
    denominator = r.denominator;
}

void Rational::operator=(const int r){
    numerator = r;
    denominator = 1;
}

//-------------------------------------------------------------------------------------------------

Rational Rational::operator+(const Rational& r) const{
    int num = numerator * r.denominator + denominator * r.numerator;
    int den = denominator * r.denominator;
    return Rational{num, den};
}

Rational Rational::operator+(const int r) const{
    int num = numerator + r*denominator;
    return Rational{num, denominator};
}

/*
Rational operator+(const Rational& r1, const Rational& r2){
    int num = r1.get_numerator() * r2.get_denominator() + r1.get_denominator() * r2.get_numerator();
    int den = r1.get_denominator() * r2.get_denominator(); 
    return Rational{num, den};
}
    
Rational operator+(const Rational& r1, const int r2){
    int num = r1.get_numerator() + r2 * r1.get_denominator();
    return Rational{num, r1.get_denominator()};
}

Rational operator+(const int r1, const Rational& r2){
    int num = r1 * r2.get_denominator() + r2.get_numerator();
    return Rational{num, r2.get_denominator()};
}*/

//-------------------------------------------------------------------------------------------------

Rational Rational::operator-(const Rational& r) const{
    int num = numerator * r.denominator - denominator * r.numerator;
    int den = denominator * r.denominator;
    return Rational{num, den};
}

Rational Rational::operator-(const int r) const{
    int num = numerator - r*denominator;
    return Rational{num, denominator};
}

/*
Rational operator-(const Rational& r1, const Rational& r2){
    int num = r1.get_numerator() * r2.get_denominator() - r1.get_denominator() * r2.get_numerator();
    int den = r1.get_denominator() * r2.get_denominator(); 
    return Rational{num, den};
}
    
Rational operator-(const Rational& r1, const int r2){
    int num = r1.get_numerator() - r2 * r1.get_denominator();
    return Rational{num, r1.get_denominator()};
}

Rational operator-(const int r1, const Rational& r2){
    int num = r1 * r2.get_denominator() - r2.get_numerator();
    return Rational{num, r2.get_denominator()};
}*/

//-------------------------------------------------------------------------------------------------

Rational Rational::operator*(const Rational& r) const{
    int num = numerator * r.numerator;
    int den = denominator * r.denominator;
    return Rational{num, den};
}

Rational Rational::operator*(const int r) const{
    int num = numerator * r;
    return Rational{num, denominator};
}

/*
Rational operator*(const Rational& r1, const Rational& r2){
    int num = r1.get_numerator() * r2.get_numerator();
    int den = r1.get_denominator() * r2.get_denominator(); 
    return Rational{num, den};
}
    
Rational operator*(const Rational& r1, const int r2){
    return Rational{r1.get_numerator() * r2, r1.get_denominator()};
}

Rational operator*(const int r1, const Rational& r2){
    return Rational{r1 * r2.get_numerator(), r2.get_denominator()};
}*/

//-------------------------------------------------------------------------------------------------

Rational Rational::operator/(const Rational& r) const{
    int num = numerator * r.denominator;
    int den = denominator * r.numerator;
    return Rational{num, den};
}

Rational Rational::operator/(const int r) const{
    int den = denominator * r;
    return Rational{numerator, den};
}

/*
Rational operator/(const Rational& r1, const Rational& r2){
    int num = r1.get_numerator() * r2.get_denominator();
    int den = r1.get_denominator() * r2.get_numerator(); 
    return Rational{num, den};
}
    
Rational operator/(const Rational& r1, const int r2){
    int den = r1.get_denominator() * r2;
    return Rational{r1.get_numerator(), den};
}

Rational operator/(const int r1, const Rational& r2){
    // r1 / (n/d) = (r1*d) / n
    int num = r1 * r2.get_denominator();
    return Rational{num, r2.get_numerator()};
}*/

//-------------------------------------------------------------------------------------------------

bool Rational::operator==(const Rational& r) const{
    return numerator*r.denominator == denominator * r.numerator;
}

bool Rational::operator==(const int r) const{
    return numerator == denominator * r;
}

/*
bool operator==(const Rational& r1, const Rational& r2){
    return r1.get_numerator()*r2.get_denominator() == r1.get_denominator() * r2.get_numerator();
}

bool operator==(const Rational& r1, const int r){
    return r1.get_numerator() == r1.get_denominator() * r;
}*/

//-------------------------------------------------------------------------------------------------

bool Rational::operator>(const Rational& r) const{
    return numerator*r.denominator > denominator * r.numerator;
}

bool Rational::operator>(const int r) const{
    return numerator > denominator * r;
}

/*
bool operator>(const Rational& r1, const Rational& r2){
    return r1.get_numerator()*r2.get_denominator() > r1.get_denominator() * r2.get_numerator();
}

bool operator>(const Rational& r1, const int r){
    return r1.get_numerator() > r1.get_denominator() * r;
}*/

//-------------------------------------------------------------------------------------------------

bool Rational::operator<(const Rational& r) const{
    return numerator*r.denominator < denominator * r.numerator;
}

bool Rational::operator<(const int r) const{
    return numerator < denominator * r;
}

/*
bool operator<(const Rational& r1, const Rational& r2){
    return r1.get_numerator()*r2.get_denominator() < r1.get_denominator() * r2.get_numerator();
}

bool operator<(const Rational& r1, const int r){
    return r1.get_numerator() < r1.get_denominator() * r;
}*/

//-------------------------------------------------------------------------------------------------
//Per queste invece (>> e <<) che sono helper functions che vanno a modificare gli oggetti, non metto const dopo la funzione

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

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

/*
Differenza int + Rational vs Rational + int

- Funzione membro
    Rational + int funziona: r + 2 diventa r.operator+(2), e il 2 è un argomento.
    int + Rational non compila: 2 + r diventerebbe 2.operator+(r), ma int non ha membri e il compilatore non converte mai l’oggetto che chiama il membro (il this).

- Funzione helper
    Entrambe funzionano: a + b diventa operator+(a, b), quindi entrambi gli operandi sono argomenti e possono subire la conversione implicita int → Rational (costruttore Rational(int) non explicit).
    Basterebbe anche solo operator+(const Rational&, const Rational&).

Conclusione: con la membro l’addizione non è simmetrica; con l’helper sì. Per operatori che devono essere simmetrici conviene l’helper.
*/

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

    cout << "\n=== ECCEZIONI COSTRUTTORI ===" << endl;
    bool lanciata = false;
    try{ Rational x{1, 0}; }catch(Rational::Invalid&){ lanciata = true; }
    check("den = 0 lancia Invalid", lanciata);

    lanciata = false;
    try{ Rational x{1, -2}; }catch(Rational::Invalid&){ lanciata = true; }
    check("den < 0 lancia Invalid", lanciata);

    lanciata = false;
    try{ Rational x{1, 2}; }catch(Rational::Invalid&){ lanciata = true; }
    check("den > 0 non lancia", !lanciata);

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
    Rational j2 = Rational{2,3} * 0;              // 0/3
    check("* 0 (2/3*0 = 0)", j2 == 0);

    cout << "\n=== OPERATOR/ ===" << endl;
    Rational k = Rational{1,2} / Rational{3,4};   // 4/6
    check("/ Rational (1/2 / 3/4 = 4/6)", k.get_numerator()==4 && k.get_denominator()==6);
    Rational l = Rational{1,2} / 3;               // 1/6
    check("/ int (1/2 / 3 = 1/6)", l.get_numerator()==1 && l.get_denominator()==6);

    lanciata = false;
    try{ Rational x = Rational{1,2} / Rational{0,1}; }catch(Rational::Invalid&){ lanciata = true; }
    check("/ Rational zero lancia Invalid", lanciata);

    lanciata = false;
    try{ Rational x = Rational{1,2} / 0; }catch(Rational::Invalid&){ lanciata = true; }
    check("/ int zero lancia Invalid", lanciata);

    cout << "\n=== OPERATOR== ===" << endl;
    check("== Rational vero (1/2 == 2/4)",  Rational{1,2} == Rational{2,4});
    check("== Rational falso (1/2 != 1/3)", !(Rational{1,2} == Rational{1,3}));
    check("== int vero (4/2 == 2)",         Rational{4,2} == 2);
    check("== int falso (1/2 != 1)",        !(Rational{1,2} == 1));

    cout << "\n=== OPERATOR< ===" << endl;
    check("< Rational (1/3 < 1/2)",  Rational{1,3} < Rational{1,2});
    check("< Rational falso",        !(Rational{1,2} < Rational{1,3}));
    check("< Rational uguali",       !(Rational{1,2} < Rational{2,4}));
    check("< int (1/2 < 1)",         Rational{1,2} < 1);
    check("< int falso (3/2 < 1)",   !(Rational{3,2} < 1));

    cout << "\n=== OPERATOR> ===" << endl;
    check("> Rational (1/2 > 1/3)",  Rational{1,2} > Rational{1,3});
    check("> Rational falso",        !(Rational{1,3} > Rational{1,2}));
    check("> Rational uguali",       !(Rational{1,2} > Rational{2,4}));
    check("> int (3/2 > 1)",         Rational{3,2} > 1);
    check("> int falso (1/2 > 1)",   !(Rational{1,2} > 1));

    cout << "\n=== NUMERATORI NEGATIVI ===" << endl;
    check("-1/2 < 0",            Rational{-1,2} < 0);
    check("-1/2 < 1/3",          Rational{-1,2} < Rational{1,3});
    check("-1/2 == -2/4",        Rational{-1,2} == Rational{-2,4});
    check("-1/2 + 1/2 == 0",     (Rational{-1,2} + Rational{1,2}) == 0);
    check("-1/2 * 2 == -1",      (Rational{-1,2} * 2) == -1);

    cout << "\n=== to_double ===" << endl;
    double x1 = Rational{5,6}.to_double();
    check("to_double 5/6 ~ 0.8333", x1 > 0.8333 && x1 < 0.8334);
    check("to_double 1/2 == 0.5",   Rational{1,2}.to_double() == 0.5);
    check("to_double 3 == 3.0",     Rational{3}.to_double() == 3.0);

    cout << "\n=== OPERATOR<< ===" << endl;
    ostringstream out;
    out << Rational{3,4};
    check("<< stampa 3/4", out.str() == "3/4");
    cout << "Output a schermo: " << Rational{5,6} << endl;

    cout << "\n=== OPERATOR>> ===" << endl;
    istringstream in1("5/8");
    Rational r1;
    in1 >> r1;
    check(">> legge 5/8", r1.get_numerator()==5 && r1.get_denominator()==8);

    istringstream in2("5-8");
    Rational r2{1,2};
    in2 >> r2;
    check(">> formato errato lascia r invariato", r2.get_numerator()==1 && r2.get_denominator()==2);

    istringstream in3("5/0");
    Rational r3{1,2};
    in3 >> r3;
    check(">> den = 0 lascia r invariato", r3.get_numerator()==1 && r3.get_denominator()==2);

    /* Interattivo (facoltativo)
    Rational input;
    cout << "Inserisci un razionale nel formato n/d (es. 5/8): ";
    cin >> input;
    cout << "Hai inserito: " << input << endl;
    */

    /* DA ATTIVARE SOLO con le helper function (commentando le versioni membro):
       con le membro queste righe NON compilano
    cout << "\n=== HELPER: int op Rational ===" << endl;
    check("int + Rational (2 + 1/2 = 5/2)", (2 + Rational{1,2}) == Rational{5,2});
    check("int - Rational (2 - 1/2 = 3/2)", (2 - Rational{1,2}) == Rational{3,2});
    check("int * Rational (3 * 2/3 = 2)",   (3 * Rational{2,3}) == 2);
    check("int / Rational (2 / 1/2 = 4)",   (2 / Rational{1,2}) == 4);
    check("int == Rational (2 == 4/2)",     2 == Rational{4,2});
    check("int < Rational (0 < 1/2)",       0 < Rational{1,2});
    check("int > Rational (1 > 1/2)",       1 > Rational{1,2});
    */

    /* DA ATTIVARE SOLO se operator= restituisce Rational& (con void non compila)
    cout << "\n=== ASSEGNAMENTO A CATENA ===" << endl;
    Rational p, q;
    p = q = Rational{2,3};
    check("a = b = c", p == Rational{2,3} && q == Rational{2,3});
    */

    cout << "\n=== RIEPILOGO ===" << endl;
    cout << "Passati: " << passed << "  Falliti: " << failed << endl;

    return 0;
}