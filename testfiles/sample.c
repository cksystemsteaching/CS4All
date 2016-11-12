int main(int argc, int *argv){
	int a;
	int b;
	int c;
	int* array1;
	int* array2;
	int* array3;

	a=11+42;
	b=52+64;
	c=102+78;

	array1 = malloc(12);
	array2 = malloc(12);
	array3 = malloc(12);

	array1 = 100;
	a = array1;


	(array1+4) = 5;

	a = (array1+4) ;
	return 0;
}
