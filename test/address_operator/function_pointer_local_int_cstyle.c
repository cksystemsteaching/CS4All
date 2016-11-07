int f1(int one, int two) {
  return (one - two);
}

int f2(int one, int two) {
  return (two - one);
}

int main() {

  int x;
  int y;

  int (*fp)(int, int);

  x = f1(42, 42);

  fp = &f1;

  x = fp(55, 77);

  fp = &f2;

  y = fp(66, 101);

  return x + y; // -22 + 33 = 11
}
