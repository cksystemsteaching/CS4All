
// enabled: true
// expected: 42
// assemblyOk: 40
// assemblyNg: 66
int main(int argc, int* argv) {
  int i;
  i = 40; // msg
  return ++i + 1; // msg
}
