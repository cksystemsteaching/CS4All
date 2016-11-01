int main(int argc, int* argv) {
  int* i;
  int* j;
  initLibrary();

  i = malloc(3*4);
  j = malloc(1*4);

  *i = 0;
  *(i+1) = 1;
  *(i+2) = 2;

  j = &*(i+1);

  if(*(j-1) == 0)
    if(*j == 1)
      if(*(j+1) == 2)
        print("OK");
  println();
}
