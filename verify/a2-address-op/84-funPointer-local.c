int inc(int x) { // msg
  return ++x; // msg
} // msg

// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  int (* lfp)(int); // msg
  lfp = &inc; // msg
  return lfp(41); // msg
}
