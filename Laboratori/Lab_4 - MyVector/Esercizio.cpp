#include <iostream>

using namespace std;

class MyVector{
    private:
        int current;
        int max;
        double *elem;

    public:
        MyVector(int size = 0);
        MyVector(initializer_list<double> lst);
        ~MyVector(){delete[] elem;} //distruttore 

        double at(int pos);
        void push_back(double value);
        int pop_back();
        MyVector reserve();
    };

MyVector::MyVector(int size) //costruttore 
    : max {size}
{
    if(max!=0){
        elem = new double[max];
        for(int i = 0; i<max; i++){elem[i] = 0;} 
        current = 0;
    }
}

MyVector::MyVector(initializer_list<double> lst) //costruttore 
    : max {lst.size()}
{    
    if(max!=0){
        elem = new double[max];
        copy(lst.begin(), lst.end(), elem);
        current = lst.size();
    }
}


int main(){




    return 0;
}