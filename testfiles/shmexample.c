
int main(int argc, int *argv){
	int firstShmId;
	int firstShmSize;
	int* firstShmVaddr;
	int j;
	int unsharedOff;
	int pagesize;
	int wordsize;

	initLibrary();
	pagesize=4096;
	wordsize=4;
	
	firstShmId = shm_open("dummyshm");
	firstShmSize = shm_size(firstShmSize,1);
	firstShmVaddr = shm_map(0,firstShmId);
	
	print((int*)"Writing/Reading to/from shared memory");
	j=10;
	while(j>0){
		printd("Vaddr ",*(firstShmVaddr+1));
		*(firstShmVaddr+1) = *(firstShmVaddr+1) + 1;
		j=j-1;
	}
	unsharedOff=pagesize/wordsize;

	//now lets write to a non shared variable
	//print((int*)"Writing/Reading to/from unshared memory");
	//while(j<10){
//		printd("Vaddr ",*(firstShmVaddr+unsharedOff));
//		*(firstShmVaddr+unsharedOff) = *(firstShmVaddr+unsharedOff) + 1;
//		j=j+1;
//	}
	shm_close(firstShmId);


	*(firstShmVaddr+1) = 0;
	print((int*)"Writing/Reading to/from shared memory(AFTER CLOSE)");
	j=10;
	while(j>0){
		printd("Vaddr ",*(firstShmVaddr+1));
		*(firstShmVaddr+1) = *(firstShmVaddr+1) + 1;
		j=j-1;
	}

	//printd("SHMEXAMPLE vaddrsegfault",*(vaddr+17000));

	return 0;
}
