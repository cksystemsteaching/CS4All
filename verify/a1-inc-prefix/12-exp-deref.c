
// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  int* i;
  i = malloc(8); // 2x int
  *i=0; // msg
  *(i+1)=41; // msg
  return ++*(++i);// msg
}
