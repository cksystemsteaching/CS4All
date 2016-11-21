int main(){

  int i;
  int squared;

	initLibrary();

	i = 0;
	while(i < 10) {
		squared = i*i;

		shm_write((int*) "a", i);
		shm_read((int*) "a");

		shm_write((int*) "b", squared);
		shm_read((int*) "b");

		i = i + 1;
	}
	return 1;
}