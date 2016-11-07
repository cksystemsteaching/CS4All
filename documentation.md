## Documentation

The  whole scope of functions will be shown in the directory test. Here in particular if  ' make address_operator ' is executed.

#### Address of variable

###### '&' operator on local variables

 ```
 int main() {
  int x;
  int* y;
  x = 7;
  y = &x;
  return *y; //7
}

 ```
The  address operator assigns to the integerpointer the addresse of the variable x. Variable x is  pushed on the stack.

###### '&' operator on global variables

```
int x;

int main() {
  int* y;
  x = 334;
  y = &x;
  return *y; //334
}
```

The address operator assigns to the integerpointer the address of variable x. Variable x is located at the global data segment.

#### Function Pointer

```
int f1(int one, int two) {
  return (one - two);
}

int f2(int one, int two) {
  return (two - one);
}

int main() {

  int x;
  int y;

  int (*fp)(int, int);

  x = f1(42, 42);

  fp = &f1;

  x = fp(55, 77);

  fp = &f2;

  y = fp(66, 101);

  return x + y; // -22 + 33 = 11
}

```
First to the functionpinter fp the address of in function f1 will be assignd.
The next line demonstrates a function call by the functionpointer fp.
The 'C-Standard' functionpointer declaration is accepted too, however paramter information disdiscarded.
