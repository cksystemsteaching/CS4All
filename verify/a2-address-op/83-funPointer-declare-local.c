// enabled: true
// expected: 42
// assemblyOk: 42
// assemblyNg: 66
int main(int argc, int* argv) {
  int (* lfp)(int); // msg
  return 42;
}

