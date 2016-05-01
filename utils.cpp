// swap array elements
void swap(int* big, int* small){
	int temp = *big;
	*big = *small;
	*small = temp;
}