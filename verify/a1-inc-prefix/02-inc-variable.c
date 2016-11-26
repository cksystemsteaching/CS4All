
// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  int i;
  i = 41; // msg
  ++i;
  return i; // msg
}
