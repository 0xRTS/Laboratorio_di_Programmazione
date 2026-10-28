#include <iostream>

using namespace std;

int main(){
    int i = 0;

    while(true){
        double *p = new (nothrow) double[100];
        
        if(p == nullptr){
            break;
        }
        
        i++;
    }

    cout << "Memoria allocata: " << i*sizeof(double)*100 << "byte";

    return 0;
}
