int main(int argc, int* argv) {
  int* i;
  int a;

  initLibrary();

  i = malloc(1*4);
  a = 5;

  i = &a;
  *i = 10;

  if(a == 10)
    print("OK");
  else
    print("WRONG");
  println();
}
