int foo(int* x) {
  *x = *x + *x;
}

int main(int argc, int* argv) {
  initLibrary();
  int* i;
  int a;

  i=malloc(1*4);
  a = 7;

  foo(&a);

  if(a == 14)
    print("OK");
}
