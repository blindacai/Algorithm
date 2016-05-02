#include "utils.cpp"

// sort array in increasing order
void bubbleSort(int array[], int first, int last){
	bool swapped = false;
	do{
		swapped = false;
		for(int i = 0; i < last - first; i++){
			if(array[i] > array[i+1]){
				swap(&array[i], &array[i+1]);
				swapped = true;
			}
		}	
	}while(swapped);
}