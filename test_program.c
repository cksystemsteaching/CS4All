int main(){

  int i;

  int fd_a;
  int fd_b;

  int a;
  int b;

  int a_size;
  int b_size;

  int* buf_a_write;
  int* buf_b_write;

  int* buf_a_read;
  int* buf_b_read;

  int bytesToRead;
  bytesToRead = 4;
  buf_a_write = (int*) "Test a";
  buf_a_write = (int*) "Test b";

	initLibrary();

	i = 0;
	while(i < 10) {
		fd_a = shm_open("a");
		fd_b = shm_open("b");

		a_size = shm_size(fd_a,bytesToRead);
		// printInteger(a_size);
		// println();	

		b_size = shm_size(fd_b,bytesToRead);
		// printInteger(b_size);
		// println();

		shm_write(fd_a,buf_a_write,bytesToRead);
		shm_write(fd_b,buf_a_write,bytesToRead);

		shm_read(fd_a,buf_a_read,bytesToRead);
		shm_read(fd_b,buf_b_read,bytesToRead);

		print(buf_a_read);
		print(buf_b_read);
		// a = shm_read(fd_a,buf_a,bytesToRead);
		// b = shm_read(fd_b,buf_b,bytesToRead);

		// print((int*) "[BEFORE WRITE] a: ");
		// printInteger(a);
		// print((int*) ", b: ");
		// printInteger(b);
		// println();

		// shm_write(fd_a, a + 1);
		// shm_write(fd_b, a+2);

		// a = shm_read(fd_a);
		// b = shm_read(fd_b);


		// print((int*) "[AFTER WRITE] a: ");
		// printInteger(a);
		// print((int*) ", b: ");
		// printInteger(b);
		// println();

		// shm_close(fd_a);
		// shm_close(fd_b);

		// a = shm_read(fd_a);
		// b = shm_read(fd_b);

		// // print((int*) "[AFTER CLOSE] a: ");
		// // printInteger(a);
		// // print((int*) ", b: ");
		// // printInteger(b);
		// // println();

		i = i + 1;

		// sched_yield();
	}

	// shm_close(26);
	// shm_close(98);

	return 1;
}