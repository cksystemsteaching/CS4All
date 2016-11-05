int f1(int one, int two) {
  return (one - two);
}

int f2(int one, int two) {
  return (two - one);
}

int main() {
  int x;
  // by now, points nowhere (i.e., NOT DEFINED yet)
  // int (*f)(int, int); // in selfie: int* f;
  int (*f);

  x = f1(1, 10);

  // let f point to DEFINED function f1
  f = &f1; // compiler knows f1 and thus if f is called, actually f1 is called
  x = f(1, 10);
  return x; //r -9
}
