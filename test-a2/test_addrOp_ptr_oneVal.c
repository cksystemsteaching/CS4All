int main(int argc, int* argv) {
  initLibrary();
  int* i;
  int* j;

  i=malloc(1*4);

  *i = 99;

  j = &*i;

  if(*j == 99)
    print("OK");
}
