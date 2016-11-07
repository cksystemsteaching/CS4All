int main(int argc, int* argv) {
  int i;
  int j;
  int *p;
  int *q;
  initLibrary();

  p = malloc(4);
  q = malloc(4);
  p = &i;
  q = &j;

  if((p-q) == 4) {
    print("OK");
  }
  println();
}
