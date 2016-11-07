
// enabled: false
// expected: 42
// assemblyOk: 42
// assemblyNg: 66
int main(int argc, int* argv) {
  int l; // msg
  int* p; // msg
  int** pp; // msg
  p = &l; // msg
  pp = &p;
  **pp = 42; //msg
  return l; // msg
}
