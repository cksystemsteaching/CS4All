int main(){

  int i;

  int fd_a;
  int fd_b;

  int a;
  int b;

	initLibrary();

	i = 0;
	while(i < 10) {
		fd_a = shm_open("a");
		fd_b = shm_open("b");

		a = shm_read(fd_a);
		b = shm_read(fd_b);

		print((int*) "[BEFORE WRITE] a: ");
		printInteger(a);
		print((int*) ", b: ");
		printInteger(b);
		println();

		shm_write(fd_a, a + 1);
		shm_write(fd_b, 2*(a+1));

		a = shm_read(fd_a);
		b = shm_read(fd_b);


		print((int*) "[AFTER WRITE] a: ");
		printInteger(a);
		print((int*) ", b: ");
		printInteger(b);
		println();

		// shm_close(fd_a);
		// shm_close(fd_b);

		a = shm_read(fd_a);
		b = shm_read(fd_b);

		print((int*) "[AFTER CLOSE] a: ");
		printInteger(a);
		print((int*) ", b: ");
		printInteger(b);
		println();

		i = i + 1;

		sched_yield();
	}

	shm_close(99);
	shm_close(98);

	return 1;
}