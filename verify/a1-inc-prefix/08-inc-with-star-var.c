
// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  int *l;
  l = malloc(8); // 2x int
  *l = 41; // msg
  ++*l; // msg
  return *l; // msg
}
