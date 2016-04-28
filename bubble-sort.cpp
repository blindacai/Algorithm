#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int size = 0;

// fill array with user inputs
void creatElement(int array[]){
	for(int i = 0; i < size; i++){
		cin >> array[i];
	}
}

// swap array elements
void swap(int* big, int* small){
	int temp = *big;
	*big = *small;
	*small = temp;
}

// sort array in increasing order
void sort(int array[]){
	bool swapped = false;
	do{
		swapped = false;
		for(int i = 0; i < size - 1; i++){
			if(array[i] > array[i+1]){
				swap(&array[i], &array[i+1]);
				swapped = true;
			}
		}	
	}while(swapped);

}

// print out sorted array
void print(int array[]){
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
}

int main(){
	int numOfele;
	printf("Enter number of elements: ");
	cin >> numOfele;
	int array[numOfele];
	size = numOfele;

	printf("Enter %d integers:\n", numOfele);
	creatElement(array);

	printf("Start:\n");
	sort(array);
	print(array);
	printf("\nDone");
}
