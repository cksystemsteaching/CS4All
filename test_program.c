int main(){

  int i;

  int fd_a;
  int fd_b;

  int a_name;
  int b_name;

  int a_size;
  int b_size;

  int* write_a;
  int* write_b;

  int* read_before_a;
  int* read_before_b;

  int* read_after_a;
  int* read_after_b;

  int bytes_a;
  int bytes_b;

	a_name = (int*) "a";
	b_name = (int*) "b";

  write_a = (int*) "x";
  write_b = (int*) "y";

  bytes_a = 4;
  bytes_b = 4;

  read_before_a = malloc(bytes_a);
  read_before_b = malloc(bytes_b);

  read_after_a = malloc(bytes_a);
  read_after_b = malloc(bytes_b);

	initLibrary();

	// open FDs
	fd_a = shm_open(a_name);
	fd_b = shm_open(b_name);
	
	// set size of FDs' handled objects
	a_size = shm_size(fd_a,bytes_a);
	b_size = shm_size(fd_b,bytes_b);

	i = 0;
	while(i < 20) {
		print((int*) "i=");
		printInteger(i);
		println();

		write_a = (int*) "x";
		write_b = (int*) "y";

		if (i != 0) {
			if (i % 3 == 0) {
				write_a = (int*) "x3";		// on every 4th iteration, "x3" is written to fd_a
			} else if (i % 5 == 0) {
				write_b = (int*) "y5";		// on every 6th iteration, "y5" is written to fd_b
			}
		}

		shm_read(fd_a,read_before_a,bytes_a);
		shm_read(fd_b,read_before_b,bytes_b);

		shm_write(fd_a,write_a,bytes_a);
		shm_write(fd_b,write_b,bytes_b);

		shm_read(fd_a,read_after_a,bytes_a);
		shm_read(fd_b,read_after_b,bytes_b);

		printString(a_name);
		print((int*) " |  R:");
		printString(read_before_a);
		print((int*) "  W:");
		printString(write_a);
		print((int*) "  R:");
		printString(read_after_a);
		
		println();

		printString(b_name);
		print((int*) " |  R:");
		printString(read_before_b);
		print((int*) "  W:");
		printString(write_b);
		print((int*) "  R:");
		printString(read_after_b);

		println();
		println();

		i = i + 1;

		if (i % 2 == 0)
			sched_yield();		// yield after every 3rd iteration
	}

	shm_close(fd_a);		//after loop, close FDs
	shm_close(fd_b);

	return 1;
}