int (*i);

int double(int x) {
  int a;
  a = x * 2;
  return x;
}

int main(int argc, int* argv) {
  int j;
  initLibrary();

  i = &double;

  j = i(2);

  if(j == 4)
    print("OK");
  else
    print("WRONG")
  println();
}
