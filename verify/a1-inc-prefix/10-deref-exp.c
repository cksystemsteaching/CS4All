
// enabled: true
// expected: 42
// assemblyOk: 41
// assemblyNg: 66
int main(int argc, int* argv) {
  int* i;
  i = malloc(8); // 2x int
  *(i+1)=41; // msg
  if ( ++*(i+1) == 42) // msg
   return *(i+1); // msg
  else
    return 43;

  return *(i+1);
}
