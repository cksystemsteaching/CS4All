int main(int argc, int* argv) {
  int* i;
  int* j;
  initLibrary();

  i = malloc(1*4);

  *i = 99;

  j = &*i;

  if(*j == 99)
    print("OK");
  println();
}
