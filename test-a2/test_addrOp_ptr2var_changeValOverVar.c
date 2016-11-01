int main(int argc, int* argv) {
  int* i;
  int* j;
  int a;
  initLibrary();

  i = malloc(1*4);
  j = malloc(1*4);
  a = 5;

  i = &a;
  j = &a;

  a = 34;

  if(*i == 34)
    if(*j == 34)
      print("OK");
  println();
}
