int test(int x,int (* fp)(int)) { // msg
  return ++x; // msg
} // msg

int inc(int x) {
  return ++x;
}

// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  return test(41,&inc); // msg
}
