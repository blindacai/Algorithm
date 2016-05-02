#include <iostream>
#include <string>
#include <cstdio>
#include <map>

#include "utils.cpp"  // for the following sort to use functions in utils, why is it enough to just include it here once?

#include "bubble-sort.cpp"
#include "insertion-sort.cpp"
#include "heap-sort.cpp"
#include "merge-sort.cpp"
#include "quick-sort.cpp"
#include "selection-sort.cpp"


using namespace std;

int size = 0;

typedef void (*sortFun)(int array[], int, int);

// fill array with user inputs
void creatElement(int array[]){
	for(int i = 0; i < size; i++){
		cin >> array[i];
	}
}

// print out sorted array
void print(int array[]){
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
}

void sort(void (*sortFun)(int*, int, int), int array[]){
	(*sortFun)(array, 0 , size - 1);
}

int main(int argc, char* argv[]){
	map<string, sortFun> sortMap;
	sortMap["bubble"] = bubbleSort;
	sortMap["insertion"] = insertionSort;
	sortMap["heap"] = heapSort;
	sortMap["merge"] = mergeSort;
	sortMap["quick"] = quickSort;
	sortMap["selection"] = selectionSort;

	printf("Enter number of elements: ");
	cin >> size;
	int array[size];

	printf("Enter %d integers:\n", size);
	creatElement(array);

	printf("Start:\n");
	sort(sortMap[string(argv[1])], array);
	print(array);
	printf("\nDone");
}