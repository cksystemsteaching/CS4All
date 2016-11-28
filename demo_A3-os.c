int main(){

  int i;

	initLibrary();

	i = 0;
	while(i < 5) {
		println();
		printInteger(i);
		sched_yield();
		println();
		i = i + 1;
	}
	return 1;
}
