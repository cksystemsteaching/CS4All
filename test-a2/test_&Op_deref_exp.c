int main(int argc, int* argv) {
  int* p;
  int* q;
  initLibrary();

  p = malloc(4);
  q = malloc(4);

  *(p + 1) = 7;

  q = &*(p+1);

  if (*q == 7) {
    print("OK");
  }
  println();
}
