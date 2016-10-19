int main(int argc, int* argv) {
  int* i;
  initLibrary();
  i=malloc(2*4);
  *i=0;
  *(i+1)=3;
  if( ++*(++i) == 4)
    print("OK");
  println();
}
