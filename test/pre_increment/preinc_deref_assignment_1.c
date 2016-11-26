int main() {
  int* x;
  int y;
  x = (int*) malloc(4);
  *x = 7654;
  y = ++*x;
  return y; // 7655
}
