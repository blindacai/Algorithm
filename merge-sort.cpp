/*
Divide and Conquer Merge Sort
*/

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


/*
first: index of the first element from left half of the array
last: index of the last element from right half of the array
mid: (first + last) / 2

Note: it isn't in place; extra space temp is used to store sorted array
*/
void merge(int array[], int first, int mid, int last){
	int temp[last - first + 1];
	int left = first; int right = mid + 1;
	int index = 0;

	while(left <= mid || right <= last){
		if(left > mid){
			for(int i = 0; i < (last - mid); i++, index++)
				temp[index] = array[right + i];

			break;
		}

		if(right > last){
			for(int i = 0; i < (mid + 1 - first); i++, index++)
				temp[index] = array[left + i];

			break;
		}

		else{
			if(array[left] <= array[right]){
				temp[index] = array[left];
				left++;
			}
			else{
				temp[index] = array[right];
				right++;
			}

			index++;
		}		
	}

	for(int i = 0; i < (last - first + 1); i++){
		array[first + i] = temp[i];
	}				
}

void sort(int array[], int first, int last){
	if(first == last)
		return;
	else{
		int mid = (first + last)/2;
		sort(array, first, mid);
		sort(array, mid+1, last);
		merge(array, first, mid, last);
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
	sort(array, 0, size-1);
	print(array);
	printf("\nDone");
}
