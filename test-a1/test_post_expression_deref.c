int main(int argc, int* argv) {
  int* i;
  int* j;
  initLibrary();
  i=malloc(2*4);
  j=i;
  *i=0;
  *(i+1)=3;
  if( *(i++)++ == 0)
    if( *j == 1)
      if( *i == 3)
        print("OK");
  println();
}
