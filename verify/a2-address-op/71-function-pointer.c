int increment(int value);

// FIXME: just a test working with gcc -> will not work with selfie because of data type issues

// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  int* foo;
  foo = &increment;
  return @foo(41);
}

int increment(int value) {
  return ++value;
}
