#include <iostream>
#include <vector>
#include <string>

using namespace std; //importa tutto il namespace std 

//oppure faccio
//using std:cout
//using std:vector
//using std::int 
//ecc...

void print(string message, vector<int> v){
    cout<<message;

    for(int i = 0; i<v.size(); i++){
        cout<<v[i] << " ";
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4};

    cout<<"Hello World!!\n";
    
    print("I numeri sono: ", v);
    return 0;
}

