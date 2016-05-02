#include <iostream>
#include <string>
#include <cstdio>

#include "bubble-sort.cpp"

using namespace std;

int size = 0;

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
	printf("Enter number of elements: ");
	cin >> size;
	int array[size];

	//cout << argv[1] << endl;

	printf("Enter %d integers:\n", size);
	creatElement(array);

	printf("Start:\n");
	sort(&bubbleSort, array);
	print(array);
	printf("\nDone");
}