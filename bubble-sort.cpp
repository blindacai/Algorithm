#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void creatElement(int array[], int size){
	for(int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void sort(int array[]){
	for(int i = 0; i < 3; i++){
		cout << array[i] << endl;
	}
}

int main(){
	int numOfele;
	printf("Enter number of elements: ");
	cin >> numOfele;
	int array[numOfele];

	printf("Enter %d integers:\n", numOfele);
	creatElement(array, numOfele);

	printf("Start:\n");
	sort(array);
	printf("Done\n");
}
