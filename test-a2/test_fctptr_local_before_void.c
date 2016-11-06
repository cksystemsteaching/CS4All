void double(int* x) {
  int a;
  *x = *x * 2;
}

int main(int argc, int* argv) {
  void (*i);
  int j;
  initLibrary();

  i = &double;
  j = 2;

  i(&j);

  if(j == 4)
    print("OK");
  else
    print("WRONG")
  println();
}
