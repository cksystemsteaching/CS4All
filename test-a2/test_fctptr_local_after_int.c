int double(int x);

int main(int argc, int* argv) {
  int (*i);
  int j;
  initLibrary();

  i = &double;

  j = i(2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}

int double(int x) {
  int a;
  a = x * 2;
  return a;
}
