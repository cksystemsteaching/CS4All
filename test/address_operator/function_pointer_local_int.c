int f1(int one, int two) {
  return (one - two);
}

int f2(int one, int two) {
  return (two - one);
}

int main() {

  int x;
  int y;

  int (*fp);

  x = f1(42, 42);

  fp = &f1;

  x = fp(55, 77);

  fp = &f2;

  y = fp(66, 99);

  return x + y; // -22 + 33 = 11
}
