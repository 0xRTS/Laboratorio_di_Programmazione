#include <iostream>

using namespace std;

void print_array_length(double v[]){
    cout << "Dimensione del puntatore: " << sizeof(v) << " byte\n";
    //decadimento (slide 5_3.16), viene passato il puntatore al primo elemento 
    //La funzione non conosce la dimensione dell'array, riesce ad accedere ai dati dell'array, l'accesso è lecitro finchè il puntatyore rimane entro i limiti dell'array

    cout << v[0]; //accesso consentito (v puntatore al primo elemento dell'array argomento) 
}


int main(){
    constexpr int size = 10;

    double arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Dimensione array: " << sizeof(arr) << " byte\n";
    cout << "Dimensione double: " << sizeof(double) << " byte\n";
    cout << "Numero elementi array: " << sizeof(arr)/sizeof(double) << "\n";

    print_array_length(arr);

    return 0;
}