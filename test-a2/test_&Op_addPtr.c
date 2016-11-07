int add(int* two, int* three) {
  return *two + *three;
}

int main(int argc, int* argv) {
  int i;
  int j;
  int *p;
  int *q;
  initLibrary();

  p = malloc(4);
  q = malloc(4);
  i = 2;
  j = 3;
  p = &i;
  q = &j;

  j = add(p,q);

  if(j == 5) {
    print("OK");
  }
  println();
}
