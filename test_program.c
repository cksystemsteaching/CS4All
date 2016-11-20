int main(){

  int i;

	initLibrary();

	i = 0;
	while(i < 10) {
    printInteger(i);
		println();

		print((int*) "test!");
		shm_write((int*) "a",666);
		shm_read((int*) "b");
		
		i = i + 1;
	}
	return 1;
}