#include <iostream>

using namespace std;

class MyVector{
    private:
        int current_elements; //elements saved
        int max_elements; //buffer dim
        double *elem; //buffer

    public:
        MyVector(int size = 0);
        MyVector(initializer_list<double> lst);
        ~MyVector(){delete[] elem;} //distruttore 

        class Invalid{};
        int size() const{ return current_elements;}
        int capacity() const{ return max_elements;}
        double& at(int pos);
        void push_back(double value);
        double pop_back();
        void reserve(int dim);
    };

MyVector::MyVector(int size) //costruttore 
    : current_elements {size}, max_elements {size*2}, elem {new double[max_elements]}
{
    if(size!=0){
        for(int i = 0; i<size; i++){elem[i] = 0;} 
    }else{
        elem = nullptr;
    }
}

MyVector::MyVector(initializer_list<double> lst) //costruttore 
    : current_elements {lst.size()}, max_elements {lst.size()*2}, elem {new double[lst.size()*2]}
{    
    if(lst.size()!=0){
        copy(lst.begin(), lst.end(), elem);
    }else{
        elem = nullptr;
    }
}

/*
delete[] elem;	memoria liberata - puntatore conserva l’indirizzo vecchio, ma invalido (dangling)
elem = nullptr;	memoria resta occupata - puntatore non punta più a nulla
*/

double& MyVector::at(int n){
    if(n<0 || n>current_elements-1){
        throw Invalid{};
    }else{
        return elem[n];
    }
}

void MyVector::push_back(double value){
    if(current_elements == max_elements){
        reserve((max_elements+1)*2);
    }

    elem[current_elements] = value;
    current_elements++;
}

double MyVector::pop_back(){
    if(current_elements != 0){
        current_elements--;
        return elem[current_elements];    
    }else{
        throw Invalid{};
    }
}

void MyVector::reserve(int dim){
    if(max_elements < dim){
        double* new_arr = new double[dim];

        for(int i = 0; i<current_elements; i++){
            new_arr[i] = elem[i];
        }

        delete[] elem;
        elem = new_arr;
        max_elements = dim;
    }
}

int main(){
    
    return 0;
}