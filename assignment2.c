//used for simple integer output in range [0 - 99];
void dumbITOA(int number) {
    int i;
    int *buff;
    int tmp;
    int ptr;
    int div;
    ptr = 0;
    div = 100;
    tmp = number;
    buff = malloc(20);

    while (div != 0) {
        *(buff + ptr) = (tmp / div) + 48;
        tmp = tmp % div;
        div = div / 10;
        ptr = ptr + 1;
    }
    *(buff + ptr) = ' ';
    write(1, buff, 20);
}


int *selectionsort(int *array, int n, int *comp);


int add(int a, int b) {
    return a +b ;
}

int sub(int a, int b);

int mult(int a, int b);

int metafunc(int a, int b, int *func);

int *funcfactory(int funcindex);

int sort(int a, int b);

int sortReverse(int a, int b);


int main(int argc, int *argv) {
    int a;
    int b;
    int *ptr;
    int *func;
    int *funcarray;
    int choice;
    int *numbers;
    int counter;

    a = 24;
    b = 12;

    write(1, "Example A: ", 20);

    // ----------------------------------------------------------------
    // Example A: use of the address operator & on a (local) variable a
    // ----------------------------------------------------------------

    //print out the initial value of a, which is 24
    dumbITOA(a);
    // load the address of a into the pointer ptr
    ptr = &a;
    // update the value contained in the memory location ptr is pointing to
    *ptr = 99;
    // a is 99 afterwards
    dumbITOA(a);


    a = 24;

    write(1, " --- Example B: ", 20);


    // ----------------------------------------------------------------
    // Example B: build array of function pointers
    // ----------------------------------------------------------------

    // allocate funcarray
    funcarray = malloc(4 * 4);
    // load the 4 entries of funcarray with pointers to various arithmetic functions
    *funcarray = &add;
    *(funcarray + 1) = &sub;
    *(funcarray + 2) = &mult;
    *(funcarray + 3) = &div;

    // set func to the start of funcarray
    func = funcarray;

    // iterate through funcarray. Apply each stored function to a and b
    while (func != funcarray + 4) {
        dumbITOA(metafunc(a, b, *func));
        ++func;
    }

    write(1, " --- Example C: ", 20);

    // ----------------------------------------------------------------
    // Example C: function factory
    // ----------------------------------------------------------------

    //Based on an integer in [0, 3], a function pointer to the concerning arithmetic
    // function is returned (note that we obviously just imitate a function factory,
    // as no function objects are created

    // 0 = add, see below
    choice = 0;

    // return a pointer to the desired function
    func = funcfactory(choice);

    // apply the function to 72 and 8
    dumbITOA(func(72, 8));


    write(1, " --- Example D: ", 20);

    // ----------------------------------------------------------------
    // Example D: control sorting with comparator
    // ----------------------------------------------------------------

    // Here we want to sort an array with 8 int values. The sorting is specified by a comparator function
    // (sort/sortReverse), given as a function pointer to the sort function.

    numbers = malloc(8*4);
    counter = 0;

    // initialized the array
    *(numbers) = 32;
    *(numbers+1) = 4;
    *(numbers+2) = 7;
    *(numbers+3) = 80;
    *(numbers+4) = 1;
    *(numbers+5) = 64;
    *(numbers+6) = 28;
    *(numbers+7) = 39;

    // sort the values with the comparator
    selectionsort(numbers, 8, &sortReverse);

    // output the values
    while (counter < 8) {
        dumbITOA(*(numbers+counter));
        ++counter;
    }

}


int *funcfactory(int funcindex) {
    if (funcindex == 0)
        return &add;
    else if (funcindex == 1)
        return &sub;
    else if (funcindex == 2)
        return &mult;
    else if (funcindex == 3)
        return &div;
    else
        return (int*) 0;
}


int mult(int a, int b) {
    return a * b;
}

int sub(int a, int b) {
    return a - b;
}

int div(int a, int b) {
    return a / b;
}

int metafunc(int a, int b, int *func) {
    return func(a, b);
}

int *selectionsort(int *array, int n, int *comp) {
    int i;
    int j;
    int min;
    int tmp;

    i = 0;
    j = 0;

    while (i < n) {
        min = i;
        j = i + 1;
        while (j < n) {
            if (comp(*(array + j), *(array + min))) {
                min = j;
            }
            ++j;
        }
        tmp = *(array + i);
        *(array + i) = *(array + min);
        *(array + min) = tmp;
        ++i;
    }
}

int sort(int a, int b) {
    return a < b;
}

int sortReverse(int a, int b) {
    return a > b;
}





