int main(int argc, int *argv){
	int *out;
	int hypsterID;
	initLibrary();
	hypsterID=hypster_ID();
	print("Executing: ");
	printInteger(hypsterID);
	println();
	return 0;
}
