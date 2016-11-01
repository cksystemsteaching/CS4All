int main(int argc, int* argv) {
  initLibrary();
  int* i;
  int* j;
  int a;

  i = malloc(1*4);
  j = malloc(1*4);
  a = 5;

  i = &a;
  j = &a;

  a = 34;

  if(*i == 34)
    if(*j == 34)
      printf("OK");
}
