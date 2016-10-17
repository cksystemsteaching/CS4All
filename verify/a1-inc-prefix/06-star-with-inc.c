
// enabled: true
// expected: 42
// assemblyOk: 40
// assemblyNg: 66
int main(int argc, int* argv) {
  int *l;
  l = malloc(8); // 2x int
  *(l + 1) = 42; // msg
  return *++l; // msg
}
