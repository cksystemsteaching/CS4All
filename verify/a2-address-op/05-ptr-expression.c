
// enabled: false
// expected: 42
// assemblyOk:
// assemblyNg: 66
int main(int argc, int* argv) {
  int* l; // msg
  int* p; // msg
  l = malloc(3*4);

  *l = 10; // msg
  *(l+1) = 30; // msg
  *(l+2) = 2; // msg

  p = &*(l+1); // msg
  return *(p-1) + *p + *(p+1); // msg
}
