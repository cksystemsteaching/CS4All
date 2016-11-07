int g;
int incrementG();

// FIXME: just a test working with gcc -> will not work with selfie because of data type issues

// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  int* foo;
  g = 41;
  foo = &incrementG;
  return @foo();
}

int incrementG() {
  return ++g;
}
