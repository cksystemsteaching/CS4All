Assignment 0: Your Team!
------------------------
* "This is PAAMs Selfie" is printed before doing anything else

Assignment 1: Revisiting Compilers
----------------------------------
* prefix/postfix increment and decrement are implemented
* all provided test cases (test-a1) are working without errors and warnings.

Assignment 2: Addresses
----------------------------------
__Address operator__

* with our selfie version it is not possibly to use the address operator in combination with expressions for example:

```C
int* i;
int* j;
*i = 0;
*(i+1) = 1;

j = &*(i+1);
```

* all the other possibilities should be implemented like in C
* therefore all our test cases (test-a2) expected *test_addrOp_ptr_expression.c* work without errors and warnings


__Function pointer__

* our function pointers only work if the function is already defined
* it is not possible to use the function pointers if the function is defined later
* it is also not possible to use the function as a function parameter
* only the testcases (test_fctptr_global_before_int.c, test_fctptr_global_before_void.c, test_fctptr_local_before_int.c, test_fctptr_local_before_void.c) work without errors and warnings

__New possibilities address operator__

1. *(is working)* Call by Reference: Use the address as a parameter with the address operator to change the value with a function
```C
int foo(int* x) {
  *x = *x + *x;
}

int main(int argc, int* argv) {
  int* i;
  int a;
  initLibrary();

  i = malloc(1*4);
  a = 7;

  foo(&a);

  if(a == 14)
    print("OK");
  else
    print("WRONG");
  println();
}
```

2. *(is working)* Get the address where the pointer is pointing to
```C
int main(int argc, int* argv) {
  int* i;
  int* j;
  initLibrary();

  i = malloc(1*4);

  *i = 99;

  j = &*i;

  if(*j == 99)
    print("OK");
  else
    print("WRONG");
  println();
}
```

3. *(is working)* Get the address of the integer value
```C
int a;

int main(int argc, int* argv) {
  int* i;
  initLibrary();

  i = malloc(1*4);
  a = 5;

  i = &a;

  if(*i == 5)
    print("OK");
  else
    print("WRONG");
  println();
}
```

4. *(is working)* Save the address of the integer value and change the value over the pointer
```C
int main(int argc, int* argv) {
  int* i;
  int a;

  initLibrary();

  i = malloc(1*4);
  a = 5;

  i = &a;
  *i = 10;

  if(*i == 10)
    print("OK");
  else
    print("WRONG");
  println();
}
```

5. *(is working)* Save the address of the integer value and change the value over the integer value and access over the two pointers
```C
int main(int argc, int* argv) {
  int* i;
  int* j;
  int a;
  initLibrary();

  i = malloc(1*4);
  j = malloc(1*4);
  a = 5;

  i = &a;
  j = &a;

  a = 34;

  if(*i == 34) {
    if(*j == 34)
      print("OK");
    else
      print("WRONG");
  } else
    print("WRONG");
  println();
}
```

6. *(is working)* Get the address of the integer value
```C
int main(int argc, int* argv) {
  int* i;
  int a;

  initLibrary();

  i = malloc(1*4);
  a = 5;

  i = &a;

  if(*i == 5)
    print("OK");
  else
    print("WRONG");
  println();
}
```

7. *(is not working)* Get the address where the next pointer is pointing to
```C
int main(int argc, int* argv) {
  int* i;
  int* j;
  initLibrary();

  i = malloc(3*4);
  j = malloc(1*4);

  *i = 0;
  *(i+1) = 1;
  *(i+2) = 2;

  j = &*(i+1);

  if(*(j-1) == 0) {
    if(*j == 1) {
      if(*(j+1) == 2)
        print("OK");
      else
        print("WRONG 3");
    } else
      print("WRONG 2");
  } else
    print("WRONG 1");
  println();
}
```

__New possibilities function pointer__

1) *(is working)* Global int pointer to a function (function definition before call)
```C
int (*i);

int double(int x) {
  int a;
  a = x * 2;
  return a;
}

int main(int argc, int* argv) {
  int j;
  initLibrary();

  i = &double;

  j = i(2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}
```

2) *(is working)* Global void pointer to a function (function definition before call)
```C
void (*i);

void double(int* x) {
  int a;
  *x = *x * 2;
}

int main(int argc, int* argv) {
  int j;
  initLibrary();

  i = &double;
  j = 2;

  i(&j);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}
```

3) *(is working)* Local int pointer to a function (function definition before call)
```C
int double(int x) {
  int a;
  a = x * 2;
  return a;
}

int main(int argc, int* argv) {
  int (*i);
  int j;
  initLibrary();

  i = &double;

  j = i(2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}
```

4) *(is working)* Local void pointer to a function (function definition before call)
```C
void double(int* x) {
  int a;
  *x = *x * 2;
}

int main(int argc, int* argv) {
  void (*i);
  int j;
  initLibrary();

  i = &double;
  j = 2;

  i(&j);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}
```

5) *(is not working)* Function as a parameter (function definition after call)
```C
int double(int x);

int test(int (*fct), int a) {
  int x;
  x = fct(a);
  return x;
}

int main(int argc, int* argv) {
  int j;
  initLibrary();

  j = test(&double, 2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}

int double(int x) {
  int a;
  a = x * 2;
  return a;
}
```

6) *(is not working)* Function as a parameter (function definition before call)
```C
int double(int x) {
  int a;
  a = x * 2;
  return a;
}

int test(int (*fct), int a) {
  int x;
  x = fct(a);
  return x;
}

int main(int argc, int* argv) {
  int j;
  initLibrary();

  j = test(&double, 2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}
```

7) *(is not working)* Global int pointer to a function (function definition after call)
```C
int (*i);

int double(int x);

int main(int argc, int* argv) {
  int j;
  initLibrary();

  i = &double;

  j = i(2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}

int double(int x) {
  int a;
  a = x * 2;
  return a;
}
```

8) *(is not working)* Global void pointer to a function (function definition after call)
```C
void (*i);

void double(int x);

int main(int argc, int* argv) {
  int j;
  initLibrary();

  i = &double;
  j = 2;

  i(&j);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}

void double(int* x) {
  int a;
  *x = *x * 2;
}
```

9) *(is not working)* Local int pointer to a function (function definition after call)
```C
int double(int x);

int main(int argc, int* argv) {
  int (*i);
  int j;
  initLibrary();

  i = &double;

  j = i(2);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}

int double(int x) {
  int a;
  a = x * 2;
  return a;
}
```

10) *(is not working)* Local void pointer to a function (function definition after call)
```C
void double(int* x);

int main(int argc, int* argv) {
  void (*i);
  int j;
  initLibrary();

  i = &double;
  j = 2;

  i(&j);

  if(j == 4)
    print("OK");
  else
    print("WRONG");
  println();
}

void double(int* x) {
  int a;
  *x = *x * 2;
}
```
