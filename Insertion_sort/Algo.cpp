#include <iostream>

void sort(int input_array[],int size){

    for(int i = 0 ; i <= size-1; i++){//0,1,2,3,4

        int temp = input_array[i];//2,1,4,5,3

        for(int j =i-1; j >-1; j--){//_//0//1,0//2,1//3,2,1,0

            if(temp < input_array[j]){//1<2//4<2,4<1//5<4,5<2,5<1//3<5,3<4,3<2,3>1

                input_array[j+1] = input_array[j]; 
                input_array[j] = temp;
                
            }
        }
    }
};

void print(int input_array[],int size){

    for(int i = 0; i < size ; i++){

        std:: cout << input_array[i];

    }
    std::cout << "\n";
}


int main(){

    int _array[5] = {2,1,4,5,3};//2//1,2//1,2,4//1,2,4,5//
    int size = sizeof(_array) / sizeof(_array[0]);

    std::cout << "Before Sort : ";
     print(_array, size);

    sort(_array,size);

    std::cout << "After Sort : ";
     print(_array, size);
}