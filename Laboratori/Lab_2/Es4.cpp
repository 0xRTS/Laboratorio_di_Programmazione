#include <iostream>

using namespace std;

void to_lower(char *s){
    for(int i = 0; s[i]!='\0'; i++){
        if(s[i]>='A' && s[i] <= 'Z'){
            s[i] = s[i] + 32; //differenza di 32 nella tabella ascii
        }
    }
}

int main(){
    char arr[] = "Hello World";
    char *p = &arr[0];
    
    to_lower(p);

    cout << "Stringa: " << arr;

    return 0;
}
