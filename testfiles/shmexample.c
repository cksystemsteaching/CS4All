
int main(int argc, int *argv){
	int id;
	int size;
	//int hypsterID;
	int* vaddr;
	int j;
  	initLibrary();
	id = shm_open("dummyshm");
	size = shm_size(id,5000);
	vaddr = shm_map(0,id);
	//hypsterID = hypster_ID();

	//*(vaddr) = 0;
	j=10;
	while(j>0){
		printd("Vaddr ",*(vaddr+1));
		*(vaddr+1) = *(vaddr+1) + 1;
		j=j-1;
	}



	//printd("SHMEXAMPLE vaddrsegfault",*(vaddr+17000));

	return 0;
}
