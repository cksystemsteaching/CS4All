int main(){

  int i;
  int squared;

  int fd_a;
  int fd_b;

  int a;
  int b;

	initLibrary();

	i = 0;
	while(i < 10) {
		squared = i*i;

		fd_a = shm_open("a");
		fd_b = shm_open("b");

		a = shm_read(fd_a);
		b = shm_read(fd_b);

		print((int*) "[BEFORE WRITE] a: ");
		printInteger(a);
		print((int*) ", b: ");
		printInteger(b);
		println();

		shm_write(fd_a, i);
		a = shm_read(fd_a);

		shm_write(fd_b, squared);
		b = shm_read(fd_b);


		print((int*) "[AFTER WRITE] a: ");
		printInteger(a);
		print((int*) ", b: ");
		printInteger(b);
		println();

		i = i + 1;
	}
	return 1;
}