#include <iostream>
#include <vector>
#include <string>

//La durata in memorizzazione di una variabile statica locale è TUTTA LA DURATA DEL PROGRAMMA 
//il suo scope invece è SOLAMENTE LA FUNZIONE 
//(a differenza di una globale che dura anch'essa tutto il programma ma è visibile ovunque)


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

int fibonacci_max(int x, int y, std::vector<int>& v, int n){
    v.clear();

    v.push_back(x);
    v.push_back(y);
    int next=0;

    for(int i=2; i<n; i++){
        next = v[i-1] + v[i-2];
        
        if(next<0){
            return v[i-1];
        }else{
            v.push_back(next);
        }
    }

    return 0;
}

void call_counter(void){
    static int count = 0;
    count++;    
    cout << "Numero chiamate: " << count << "\n";
}

int main() {//dichiarare sempre le funzioni necessarie prima del main()
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    int x = 1;
    int y = 2;
    
    cout<<"Hello World!!\n";
    
    print("[Es3] I numeri sono: ", v);
    
    cout<<"\n[Es4] (x=" << x <<" y=" << y << ")";

    fibonacci(x, y, v, v.size());
    print(" Primi 6 numeri della serie di Fibonacci: ", v);

    int next = fibonacci_max(x, y, v, v.size());

    while(next==0){
        next = fibonacci_max(v[v.size()-2], v[v.size()-1], v, v.size());
    }

    cout<<"\n[Es5] Fibonacci max: " << next;
    
    cout<<"\n[Es6] ";
    call_counter();
    call_counter();
    call_counter();
    call_counter();

    return 0;
}
