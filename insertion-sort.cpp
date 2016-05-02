
// sort array in increasing order
void insertionSort(int array[], int first, int last){
	int next = 0;
	for(int i = first; i < last + 1; i++){
		next = i;
		while(next > 0 && array[next] < array[next - 1]){
			swap(&array[next], &array[next - 1]);
			next--;
		}
	}
}
