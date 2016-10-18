int main(int argc, int* argv) {
  int i;
  initLibrary();

  i = 0;

  while (i < 20) {
    print((int*)"Testoutput");
    println();
    i = i + 1;
  }

  return 0;
}