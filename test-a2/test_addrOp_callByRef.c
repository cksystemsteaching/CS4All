int foo(int* x) {
  *x = *x + *x;
}

int main(int argc, int* argv) {
  int* i;
  int a;
  initLibrary();

  i = malloc(1*4);
  a = 7;

  foo(&a);

  if(a == 14)
    print("OK");
  else
    print("WRONG");
  println();
}
