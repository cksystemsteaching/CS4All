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

__New possibilities__
* see testcases
