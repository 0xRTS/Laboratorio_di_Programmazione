#include <iostream>

using namespace std;

int main(){
    int i = 0;

    while(true){
        double *p = new double[100];
        i++;
    }

    cout << "Memoria allocata: " << i*sizeof(double) << "byte";
    
    return 0;
}
