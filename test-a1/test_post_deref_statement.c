int main(int argc, int* argv) {
  int* i;
  initLibrary();
  i=malloc(2*4);
  *(i+1)=0;
  *(i+1)++;
  if( *(i+1) == 1)
    print("OK");
  println();
}
