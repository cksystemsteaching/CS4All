int test(int x,int (* fp)(int)) { // msg
  return ++x; // msg
} // msg

// enabled: true
// expected: 42
// assemblyOk: 42
// assemblyNg: 66
int main(int argc, int* argv) {
  return 42;
}

