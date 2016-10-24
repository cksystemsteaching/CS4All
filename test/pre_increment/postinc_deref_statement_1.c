int main() {
  int* x;
  x = (int*) malloc(4);
  *x = 2345;
  *x++;
  return *x; // 2346
}
