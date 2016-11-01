int main(int argc, int* argv) {
  int i;
  initLibrary();
  i=1;
  if( --i == 0)
    if( i == 0)
      print("OK --e");
  println();

  i=1;
  if( i-- == 1)
    if( i == 0)
      print("OK e--");
  println();

  i=1;
  --i;
  if( i == 0 )
    print("OK --s");
  println();

  i=1;
  i--;
  if( i == 0 )
    print("OK s--");
  println();
}
