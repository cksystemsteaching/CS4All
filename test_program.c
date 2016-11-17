int main(){

  int i;

	initLibrary();

	i = 0;
	while(i < 10) {
		println();
		//sched_yield();
		printInteger(i);
		i = i + 1;
	}
	return 1;
}