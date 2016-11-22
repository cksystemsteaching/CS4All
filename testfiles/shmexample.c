
int main(int argc, int *argv){
	int id;
	int size;
	//int hypsterID;
	int* vaddr;

	id = shm_open("dummyshm");
	size = shm_size(id,500);
	vaddr = shm_map(0,id);
	//hypsterID = hypster_ID();

	*(vaddr+4100) = 12345;

	return 0;
}
