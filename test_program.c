int main(){

  	int i;

	initLibrary();

	i = 0;
	while(i < 15){
      	printInteger(i);
		println();
		i = i + 1;
	}
	return 1;
}