int main(int argc, int* argv) {
  int* i;
  i=malloc(2*4);
  *(i+1)=1234;
  *(i+1)++;
  return *(i+1); // 1235
}
