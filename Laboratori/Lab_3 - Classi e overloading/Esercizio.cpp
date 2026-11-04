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
//Per queste invece << che è helper function va a modificare gli oggetti, non metto const dopo la funzione

ostream& operator<<(ostream& os, const Rational& r){
    return os << r.get_numerator() << "/" << r.get_denominator();
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

int main(){
    Rational a;              // A
    Rational b{5};           // B
    Rational c{3, 4};        // C

    try{
        Rational x{1, 0}; 
    }catch(Rational::Invalid){
        cout << "\nError (test)\n";
    }

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator = \n";
    Rational d;

    d = c;
    cout << "Numerator (d): " << d.get_numerator() << "\n";
    cout << "Denominator (d): " << d.get_denominator() << "\n";

    d = 7;
    cout << "Numerator (d): " << d.get_numerator() << "\n";
    cout << "Denominator (d): " << d.get_denominator() << "\n";

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator + \n";
    Rational e = Rational{1,2} + Rational{1,3};   // 5/6
    cout << "Numerator (e): " << e.get_numerator() << "\n";
    cout << "Denominator (e): " << e.get_denominator() << "\n";

    Rational f = Rational{1,2} + 2;               // 5/2
    cout << "Numerator (f): " << f.get_numerator() << "\n";
    cout << "Denominator (f): " << f.get_denominator() << "\n";

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator - \n";
    Rational g = Rational{1,2} - Rational{1,3};   // 1/6
    cout << "Numerator (g): " << g.get_numerator() << "\n";
    cout << "Denominator (g): " << g.get_denominator() << "\n";

    Rational h = Rational{1,2} - 1;               // -1/2
    cout << "Numerator (h): " << h.get_numerator() << "\n";
    cout << "Denominator (h): " << h.get_denominator() << "\n";

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator * \n";
    Rational i = Rational{2,3} * Rational{3,4};   // 6/12
    cout << "Numerator (i): " << i.get_numerator() << "\n";
    cout << "Denominator (i): " << i.get_denominator() << "\n";

    Rational j = Rational{2,3} * 3;               // 6/3
    cout << "Numerator (j): " << j.get_numerator() << "\n";
    cout << "Denominator (j): " << j.get_denominator() << "\n";

    Rational j2 = Rational{2,3} * 0;              // 0/3
    cout << "Numerator (j2): " << j2.get_numerator() << "\n";
    cout << "Denominator (j2): " << j2.get_denominator() << "\n";

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator / \n";
    Rational k = Rational{1,2} / Rational{3,4};   // 4/6
    cout << "Numerator (k): " << k.get_numerator() << "\n";
    cout << "Denominator (k): " << k.get_denominator() << "\n";

    Rational l = Rational{1,2} / 3;               // 1/6
    cout << "Numerator (l): " << l.get_numerator() << "\n";
    cout << "Denominator (l): " << l.get_denominator() << "\n";

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator == \n";
    Rational m = Rational{1,2};
    cout << "Result (1/2 == 2/4): " << (m == Rational{2,4}) << "\n";   // 1
    cout << "Result (1/2 == 1/3): " << (m == Rational{1,3}) << "\n";   // 0
    cout << "Result (1/2 == 1): " << (m == 1) << "\n";                 // 0
    cout << "Result (2 == 2): " << (Rational{2} == 2) << "\n";         // 1

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator < \n";
    Rational n = Rational{1,3};
    cout << "Result (1/3 < 1/2): " << (n < Rational{1,2}) << "\n";     // 1
    cout << "Result (1/3 < 1/4): " << (n < Rational{1,4}) << "\n";     // 0
    cout << "Result (1/3 < 1): " << (n < 1) << "\n";                   // 1
    cout << "Result (1/3 < 0): " << (n < 0) << "\n";                   // 0

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator > \n";
    Rational o = Rational{3,4};
    cout << "Result (3/4 > 1/2): " << (o > Rational{1,2}) << "\n";     // 1
    cout << "Result (3/4 > 5/6): " << (o > Rational{5,6}) << "\n";     // 0
    cout << "Result (3/4 > 0): " << (o > 0) << "\n";                   // 1
    cout << "Result (3/4 > 1): " << (o > 1) << "\n";                   // 0

//-------------------------------------------------------------------------------------------------

    cout << "\n=> to_double \n";
    Rational p = Rational{5,6};
    cout << "to_double (5/6): " << p.to_double() << "\n";               // 0.833333
    Rational q = Rational{1,2};
    cout << "to_double (1/2): " << q.to_double() << "\n";              // 0.5
    Rational s = Rational{3};
    cout << "to_double (3): " << s.to_double() << "\n";                // 3

//-------------------------------------------------------------------------------------------------

    cout << "\n=> operator << \n";
    Rational t = Rational{3,4};
    cout << "Output (t): " << t << "\n";                               // 3/4
    Rational u = Rational{5,6};
    cout << "Output (u): " << u << "\n";                               // 5/6

//-------------------------------------------------------------------------------------------------

    return 0;
}