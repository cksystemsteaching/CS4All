int size;
int* array;
int main(int argc, int *argv){
	int a;
	int b;
	
	a=11+42;
	size=6*4;
	array = malloc(size);
	*(array+2)=12345;
	b=10;
	a=*(array+2);

	return 0;
}
