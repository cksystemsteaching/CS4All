int main(int argc, int* argv) {
  int* p;
  int* q;
  initLibrary();

  p = malloc(4);
  q = malloc(4);

  *p = 7;

  q = &*p;

  if (*q == 7) {
    print("OK");
  }
  println();
}
