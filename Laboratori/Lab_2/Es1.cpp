#include <iostream>
#include <vector>

using namespace std;

void f(){
    int arr[10];
    int *p = &arr[3];

    //(Occhio alla posizione del puntatore rispetto all'array, vedi slide 5_3.9)
    for(int i = 0-3; i<10-3; i++){
        p[i] = i*10;
        cout << "p[" << i << "]: " << p[i] << "   ";
    }
}

void f_illegal(){
    int arr[10];
    int *p = &arr[3];

    //(Occhio alla posizione del puntatore rispetto all'array, vedi slide 5_3.9)
    for(int i = 0-3; i<10-3; i++){
        p[i] = i*10;
        cout << "p[" << i << "]: " << p[i] << "   ";
    }

    p[1000000] = 12; 
    cout << "\n" << p[1000000];
    //causa un errore in esecuzione o meno in funzione di quanto dista 
    //la memoria a cui si accede illegalmente dall’array definito 
}



int main(){
    //f();
    f_illegal();


    return 0;
}