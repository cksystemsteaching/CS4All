int (*fptr);

int mult3(int nr);

int mult3(int nr) {
  int a;
  a = nr * 3;
  return a;
}

int main(int argc, int* argv) {
  int j;
  initLibrary();

  fptr = &mult3;

  j = fptr(2);

  if(j == 6) {
    print("OK");
  }
  println();
}
