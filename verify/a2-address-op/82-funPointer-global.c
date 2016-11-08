int (* gfp)(int); // msg

int inc(int x) { // msg
  return ++x; // msg
} // msg

// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  gfp = &inc; // msg
  return gfp(41); // msg
}
