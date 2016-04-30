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


/*
lchild, rchild: index of the left and right child
return the index of the smaller child
*/
int min(int array[], int lchild, int rchild){
	if(array[lchild] < array[rchild]) return lchild;
	else return rchild;
}


/*
compare current element with its children
return the index of the smaller child
if not exist, return negtive
*/
int compare(int array[], int index, int lchild, int rchild){
	if(rchild >= 0){
		if(array[index] > array[lchild] && array[rchild]) return min(array, lchild, rchild);
		if(array[index] > array[rchild]) return rchild;
	}
	if(array[index] > array[lchild]) return lchild;
	else return -1;
}

// swap down elements to maintain min heap feature
void sinkDown(int array[], int index, int offset){
	if(index > ((size - offset)/2 - 1)) return;
	else{
		int lchild = 2*index + 1;
		int rchild = (2*index + 2 > (size - offset) - 1)? -1 : 2*index + 2;   // when size is even -> out of boundary
		int child_index = compare(array, index, lchild, rchild);
		if(child_index >= 0){
			swap(&array[index], &array[child_index]);
			sinkDown(array, child_index, offset);
		}
		else return;
	}
}

// build heap starting from the second last level
void buildHeap(int array[], int offset){
	for(int i = ((size - offset)/2 - 1); i >= 0; i--){
		sinkDown(array, i, offset);
	}
}

// sort array in increasing order
void sort(int array[]){
	for(int i = 1; i < size - 1; i++)
		buildHeap(array + i, i);
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

	printf("Build heap:\n");
	buildHeap(array, 0);
	print(array);

	printf("\nStart:\n");
	sort(array);
	print(array);
	printf("\nDone");
}
