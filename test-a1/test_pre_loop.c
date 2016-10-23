int main(int argc, int* argv) {
  int i;
  int k;
  initLibrary();
  i=0;
  while(i < 100){
    i = ++i + ++i;
    k = k + 1;
    if(k > 10)
      return 0;
  }
  if(k == 6)
    print("OK");
  println();
}
