#include <iostream>

using namespace std;

int* write_circular_buffer(unsigned int buffer_dim, unsigned int value_count){
    int *buffer = new int[buffer_dim];

    if(value_count > buffer_dim){
        int index = 0;

        for(int i = 0; i<value_count; i++){
            if(index==buffer_dim){
                index = 0;
            }

            buffer[index] = i;
            index++;
        }
    }else{
        for(int i = 0; i<value_count; i++){
            buffer[i] = i;
        }
    }

    return buffer;
}

int main(){

    unsigned int buffer_dim = 3;
    unsigned int value_count = 6;

    int * p = write_circular_buffer(buffer_dim, value_count);

    for(int i = 0; i<buffer_dim; i++){ //se buffer_dim > value_count il resto dei valori resta a 0
        cout << p[i] << "   "; 
    }

    delete[] p;
    p = nullptr;

    return 0; 
}
