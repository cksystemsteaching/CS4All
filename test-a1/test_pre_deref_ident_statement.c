int main(int argc, int* argv) {
  int* i;
  initLibrary();
  i=malloc(2);
  *i=0;
  ++*i;
  if( *i == 1)
    print("OK");
  println();
}
