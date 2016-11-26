int main() {
  int* x;
  int y;

  x = (int*) malloc(4);
  *x = 5;
  y = ++*x;
  return y; // 6
}
