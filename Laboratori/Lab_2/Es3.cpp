#include <iostream>

using namespace std;

void print_reference(const int &a1, const double &b1){
    cout << "a: " << a1 << "\n";
    cout << "b: " << b1 << "\n";
}

void print_pointer(int *a1, double *b1){
    cout << "a: " << *a1 << "\n";
    cout << "b: " << *b1 << "\n";
}

int main(){
    int *pa, a = 12;
    double *pb, b = 7; 

    pa = &a;
    pb = &b;
    
    print_reference(a, b);
    print_pointer(pa, pb);

    return 0;
}