int add(int two, int three) {
  return two + three;
}

int main(int argc, int* argv) {
  int i;
  int j;
  int result;
  int (*fptr);
  initLibrary();

  fptr = malloc(4);
  i = 2;
  j = 3;

  fptr = &add;
  result = fptr(i,j);

  if(result == 5) {
    print("OK");
  }
  println();
}
