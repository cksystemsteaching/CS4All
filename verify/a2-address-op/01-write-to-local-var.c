
// enabled: true
// expected: 42
// assemblyOk: 42
// assemblyNg: 66
int main(int argc, int* argv) {
  int l; // msg
  int* p; // msg
  p = &l; // msg
  *p = 42; //msg
  return l; // msg
}
