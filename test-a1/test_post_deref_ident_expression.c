int main(int argc, int* argv) {
  int* i;
  initLibrary();
  i=malloc(4);
  *i=0;
  if( *i++ == 0)
    if( *i == 1)
      print("OK");
  println();
}
