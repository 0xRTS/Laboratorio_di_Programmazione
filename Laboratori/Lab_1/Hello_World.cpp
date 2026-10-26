#include <iostream>
#include <vector>
#include <string>

//using namespace std; //importa tutto il namespace std 

//oppure faccio
using std::cout;
//using std::vector;
//ecc...

void print(std::string message, std::vector<int> v){
    cout<<message;

    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<< " ";
    }
}

std::vector<int> fibonacci(int x, int y, std::vector<int> v, int n){
    v.clear();

    v.push_back(x);
    v.push_back(y);

    for(int i=2; i<n; i++){
        v.push_back(v[i-1] + v[i-2]);
    }

    return v;

}

int fibonacci_max(int x, int y, std::vector<int> v){
    v.clear();

    v.push_back(x);
    v.push_back(y);
    int next = 0;
    int i = 2;

    while(next>0){
        v.push_back(v[i-1] + v[i-2]);
        i++;
    }

    return v[i];
}

int main() {//dichiarare sempre le funzioni necessarie prima del main()
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    int x = 1;
    int y = 2;
    
    cout<<"Hello World!!\n";
    
    print("[Es3] I numeri sono: ", v);
    cout<<"\n[Es4] (x=" << x <<" y=" << y << ")";
    print(" Primi 6 numeri della serie di Fibonacci: ",  fibonacci(x, y, v, v.size()));
    cout<<"[Es5] Fibonacci max: " << fibonacci_max(1, 2, v);
    
    return 0;
}
