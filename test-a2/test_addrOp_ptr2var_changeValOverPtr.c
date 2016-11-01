int main(int argc, int* argv) {
  initLibrary();
  int* i;
  i=malloc(1*4);
  int a = 5;

  i = &a;
  *i = 10;

  if(*i == 10)
    printf("OK");
}
