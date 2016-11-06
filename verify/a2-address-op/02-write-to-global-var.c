int g; // msg

// enabled: true
// expected: 42
// assemblyOk: 42
// assemblyNg: 66
int main(int argc, int* argv) {
  int* p; // msg
  p = &g; // msg
  *p = 42; // msg
  return g; // msg
}
