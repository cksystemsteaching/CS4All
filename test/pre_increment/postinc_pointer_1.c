int main() {
  int* x;
  x = (int*) malloc(8);
  *x = 1234;
  *(x+1) = 2345;
  x++;
  return *x; // 2345
}
