
// enabled: false
// expected: 42
// assemblyOk:
// assemblyNg: 66
int main(int argc, int* argv) {
  int* l; // msg
  int* p; // msg
  l = malloc(3*4);

  *l = 10;
  *(l+1) = 30;
  *(l+2) = 2;

  p = &*(l+1); // msg
  return *(p-1) + *p + *(p+1); // msg
}
