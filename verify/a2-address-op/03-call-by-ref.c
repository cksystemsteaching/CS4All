void foo(int* x) {
  *x = *x + *x;
}
// enabled: true
// expected: 42
// assemblyOk: 21
// assemblyNg: 66
int main(int argc, int* argv) {
  int l; // msg
  l = 21; //msg
  foo(&l);
  return l; // msg
}
