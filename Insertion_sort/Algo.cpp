#include <iostream>
#include <random>
#include <chrono>

void sort(int input_array[], int size)
{

    for (int i = 0; i <= size - 1; i++)
    { // 0,1,2,3,4

        int temp = input_array[i]; // 2,1,4,5,3

        for (int j = i - 1; j > -1; j--)
        { //_//0//1,0//2,1//3,2,1,0
            if (temp < input_array[j])
            { // 1<2//4<2,4<1//5<4,5<2,5<1//3<5,3<4,3<2,3>1

                input_array[j + 1] = input_array[j];
                input_array[j] = temp;
            }
        }
    }
};

void print(int input_array[], int size)
{

    for (int i = 0; i < size; i++)
    {

        std::cout << input_array[i] << ",";
    }
    std::cout << "\n";
};

int main()
{

    ///////////Random Number Generator//////////////

    int _array[50];
    std::random_device rd;
    std::mt19937 e{rd()};
    std::uniform_int_distribution<int> dist{0, 999};

    ////////////////Array//////////////////////////
    int size = sizeof(_array) / sizeof(_array[0]);
    std::cout << "Length: " << size << "\n";

    for (int i = 0; i <= size; i++)
    {
        int random_number = dist(e);
        _array[i] = random_number;
    };

    std::cout << "\nBefore Sort : ";
    print(_array, size);

    auto Init = std::chrono::high_resolution_clock::now(); // Initial Time

    /////////////calling sort fn/////////////////
    sort(_array, size);

    auto Final = std::chrono::high_resolution_clock::now();                             // Final Time
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(Final - Init); // Time Elapsed in microseconds
    std::cout << "Time elapsed: " << elapsed.count() << "\n";

    std::cout << "After Sort : ";
    print(_array, size);
}