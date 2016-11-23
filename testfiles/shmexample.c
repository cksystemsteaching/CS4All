
int main(int argc, int *argv){
	int id;
	int size;
	//int hypsterID;
	int* vaddr;
  initLibrary();

	id = shm_open("dummyshm");
	size = shm_size(id,16000);
	vaddr = shm_map(0,id);
	//hypsterID = hypster_ID();

	//*(vaddr) = 0;

	*(vaddr+1) = *(vaddr+1) + 1;

	printd("SHMEXAMPLE ID",id);
	printd("SHMEXAMPLE size",size);

	printd("SHMEXAMPLE vaddr",*(vaddr+1));

	//printd("SHMEXAMPLE vaddrsegfault",*(vaddr+17000));
	return 0;
}
