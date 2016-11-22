
int main(int argc, int *argv){
	int id;
	int size;
	int hypsterID;

	id = shm_open("dummyshm");
	size = shm_size(id,500);
	hypsterID = hypster_ID();
	println();
	println();
	println();
	println();
	printInteger(id);
	println();
	printInteger(size);
	println();
	printInteger(hypsterID);
	println();
	println();
	println();
	return 0;
}
