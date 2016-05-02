// sort array in increasing order
void selectionSort(int array[], int first, int last){
	for(int i = first; i < last + 1; i++){
		int min = i;
		for(int j = i; j < last + 1; j++){
			if(array[j] < array[min])
				min = j;
		}
		swap(&array[i], &array[min]);
	}
}