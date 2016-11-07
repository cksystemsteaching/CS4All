int double(int x) {
  int a;
  a = x * 2;
  return a;
}

int test(int (*fct), int a) {
  int x;
  x = fct(a);
  return x;
}

int main(int argc, int* argv) {
  int j;
  initLibrary();

  j = test(&double, 2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}
