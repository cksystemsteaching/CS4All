int main() {
  int* x;
  int y;
  x = (int*) malloc(4);
  *x = 20;
  y = *x++;
  return *x; // 21
}
