int main(int argc, int* argv) {
  initLibrary();
  int* i;
  int a;

  i = malloc(1*4);
  a = 5;

  i = &a;

  if(*i == 5)
    printf("OK");
}
