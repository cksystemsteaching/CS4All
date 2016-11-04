int f1(int one, int two) {
  return (one - two);
}

int f2(int one, int two) {
  return (two - one);
}

int main() {

  int* arr;
  int size;
  int arr_size;
  int i;
  int threshold;
  int return_value;

  // by now, points nowhere (i.e., NOT DEFINED yet)
  int (*f)(int, int); // in selfie: int* f;

  threshold = 45;

  arr_size = 10; // number of entries in arr
  size = 4; // int
  arr = malloc(arr_size * size); // allocate arr

  // fill arr with values between 42 and 51
  i = 0;
  while (i < arr_size) {
    *(arr + i) = (42 + i);

    i = i + 1;
  }

  // let f point to DEFINED function f1
  f = f1; // compiler knows f1 and thus if f is called, actually f1 is called

  i = 0;
  while (i < arr_size) {
  
    return_value = f(*(arr + i), threshold);
    
    if (return_value > 0) {
    }

    i = i + 1;
  }

  return *(arr + 9); //return 51
}
