

int main(int argc, int *argv){
  int i;
  initLibrary();
  i=0;

  while(i<10){
    printInteger(i);  
    i=i+1; 
    sched_yield();
  }

  return 0;
}

