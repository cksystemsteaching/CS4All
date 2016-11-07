int main() {
  int* x;
  x = (int*) malloc(4);
  *x = 7654;
  ++*x;
  return *x; // 7655
}
