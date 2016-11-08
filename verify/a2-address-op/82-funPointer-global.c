int (* foo)(int); // msg

int increment(int value) { // msg
  return ++value; // msg
} // msg

// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  foo = &increment; // msg
  return foo(41); // msg
}
