

int main(int argc, int *argv){
  int i;
  initLibrary();
  i=0;
	println();
	println();
  while(i<10){
    printInteger(i);  
    i=i+1; 
    sched_yield();
  }
	println();
	println();
  return 0;
}


