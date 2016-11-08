int main(int argc, int* argv) {
  int i;
  int *q;
  initLibrary();

  q = malloc(4);
  i = 7;
  q = &i;

  if(*q == 7) {
    print("OK");
  }
  println();
}
