#include <iostream>

using namespace std;

char *strdup(const char* source){
    int length = 0;
    
    while(source[length] != '\0'){
        length++;
    }

    char *f = new char[length+1]; //+1 per \0 finale 

    for(int i = 0; i<length+1; i++){
        f[i] = source[i];
    }

    return f;
}

int main(){
    char arr[] = "Ciao mondo";

    char *p = strdup(arr);

    cout << "Stringa copiata: " << p;
    
    delete[] p;
    p = nullptr;

    return 0;
}
