#include <iostream>
#include<random>
#include<ctime>


int partition(int arr[], int low, int high)
{

	int pivot = arr[low];

	int count = 0;
	for (int i = low + 1; i <= high; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = low + count;
	std::swap(arr[pivotIndex], arr[low]);

	// Sorting left and right parts of the pivot element
	int i = low, j = high;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			std::swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}






 /*----------------------------------------------------------------------------------------------------------------------------*/
void quickSort(int arr[], int low, int high)
{

	// base case
	if (low >= high)
		return;

	// partitioning the array
	int p = partition(arr, low, high);

	// Sorting the left part
	quickSort(arr, low, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, high);
}















int main()
{
    int n;
    std::cout << "Enter the size of array"<<std::endl;
    std::cin >> n;
    int arr[n];

    std::uniform_int_distribution<> range(0,1000); //to get random numbers from 0 to 1000 as array elements

    std::cout << "The unsorted array is"<<std::endl;
    srand(time(NULL));
    for(int i = 0;i < n; i++)
    {
        std::mt19937 a(rand()%100); //random number is given as a seed to pseudorandom num generator
        arr[i] = range(a); // that pseudo random number is used to select a number from range(0,1000)
        std::cout << arr[i] <<"\t";
    }
    std::cout << "\n";

    auto start = std::chrono::high_resolution_clock::now(); ///time before function call

	quickSort(arr, 0, n - 1);

    auto stop = std::chrono::high_resolution_clock::now(); //time after function call

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    std::cout <<"\n"<<"the sorted array is "<<std::endl;
	for (int i = 0; i < n; i++) { //displaying the list
		std::cout << arr[i] << "\t";
	}
    std::cout << std::endl;

    std::cout << "The time interval for the sorting is "<<duration.count()<<std::endl;

	return 0;
}
