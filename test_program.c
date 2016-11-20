int main(){

  int i;

	initLibrary();

	i = 0;
	while(i < 10) {
		shm_write((int*) "a", i);
		shm_read((int*) "a");

		i = i + 1;
	}
	return 1;
}