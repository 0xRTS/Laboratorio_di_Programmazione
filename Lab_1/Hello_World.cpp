#include <iostream>

int d = 1; //globale (=> statica) != 0
int e; //globale (=> statica)

int main() {
    std::cout<<"Hello World!!\n";
    
    int a; //locale automatica
    static int b = 1; //locale statica != 0
    static int c;
    
    return 0;
}
