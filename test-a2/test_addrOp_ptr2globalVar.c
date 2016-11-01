int a;

int main(int argc, int* argv) {
  int* i;
  initLibrary();

  i = malloc(1*4);
  a = 5;

  i = &a;

  if(*i == 5)
    print("OK");
  println();
}
