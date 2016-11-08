int sum(int a, int b) {
  return a + b;
}

int main(int argc, int* argv) {
  int *q;
  initLibrary();

  q = malloc(4);

  q = &sum;

  if(q != 0) {
    print("OK");
  }
  println();
}
