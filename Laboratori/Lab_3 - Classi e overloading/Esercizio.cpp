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
        
        Rational operator+(const Rational& r);
        Rational operator+(const int r); 

        Rational operator-(const Rational& r);
        Rational operator-(const int r); 

        Rational operator*(const Rational& r);
        Rational operator*(const int r); 

        Rational operator/(const Rational& r);
        Rational operator/(const int r); 

        bool operator==(const Rational& r);
        bool operator==(const int r);

        bool operator<(const Rational& r);
        bool operator<(const int r);

        bool operator>(const Rational& r);
        bool operator>(const int r);

        double to_double();
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
}

Rational::Rational(int num, int den) //C (costruttore come init list)
    : numerator{num}, denominator{den} 
{
}

bool Rational::is_valid(){ //Controlo validità denominatore
    if(denominator<=0){
        return false;
    }else{
        return true;
    }
}

Rational Rational::operator=(const Rational& r){
    numerator = r.get_numerator();
    denominator = r.get_denominator();
    return Rational{numerator, denominator};
}

Rational Rational::operator=(const int r){
    numerator = r;
    denominator = 1;
    return Rational{numerator, denominator};
}

Rational Rational::operator+(const Rational& r){
    int num = numerator * r.get_denominator() + denominator * r.get_numerator();
    int den = denominator * r.get_denominator();
    return Rational{num, den};
}

Rational Rational::operator+(const int r){
    int num = numerator + r*denominator;
    return Rational{num, denominator};
}

Rational Rational::operator-(const Rational& r){
    int num = numerator * r.get_denominator() - denominator * r.get_numerator();
    int den = denominator * r.get_denominator();
    return Rational{num, den};
}

Rational Rational::operator-(const int r){
    int num = numerator - r*denominator;
    return Rational{num, denominator};
}

Rational Rational::operator*(const Rational& r){
    int num = numerator * r.get_numerator();
    int den = denominator * r.get_denominator();
    return Rational{num, den};
}

Rational Rational::operator*(const int r){
    int num = numerator * r;
    return Rational{num, denominator};
}

Rational Rational::operator/(const Rational& r){
    int num = numerator * r.get_denominator();
    int den = denominator * r.get_numerator();
    return Rational{num, den};
}

Rational Rational::operator/(const int r){
    int den = denominator * r;
    return Rational{numerator, den};
}

bool Rational::operator==(const Rational& r){
    if(numerator*r.get_denominator() == denominator * r.get_numerator()){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator==(const int r){
    if(numerator == denominator * r){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator>(const Rational& r){
    if(numerator*r.get_denominator() > denominator * r.get_numerator()){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator>(const int r){
    if(numerator > denominator * r){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator<(const Rational& r){
    if(numerator*r.get_denominator() < denominator * r.get_numerator()){
        return true;
    }else{
        return false;
    }
}

bool Rational::operator<(const int r){
    if(numerator < denominator * r){
        return true;
    }else{
        return false;
    }
}

int main(){




    return 0;
}


/*Ovviamente definito nella classe 
Rational(int value) //B (costruttore come assegnamento)
{ //Prima dell'assegnamento esplicito avviene un assegnamento implicito che noi non vediamo
    numerator = value;
    denominator =  1;
}
*/