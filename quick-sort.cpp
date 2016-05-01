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

int partition(int array[], int p_index, int first){
	int pivot = array[p_index];
	int wall = first;
	for(int i = first; i < p_index; i++){
		if(array[i] < pivot){
			swap(&array[i], &array[wall]);
			wall++;
		}
	}
	swap(&array[p_index], &array[wall]);
	return wall;
}

// sort array in increasing order
void sort(int array[], int first, int last){
	if(first >= last) return;
	else{
		int wall = partition(array, last, first);
		sort(array, first, wall - 1);
		sort(array, wall + 1, last);
	}
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
	sort(array, 0, size - 1);
	print(array);
	printf("\nDone");
}
