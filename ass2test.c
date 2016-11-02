//used for simple integer output in range [0 - 99];
void dumbITOA(int number);

void dumbITOA(int number) {
    int i;
    int *buff;
    int tmp;
    int ptr;
    int div;
    ptr = 0;
    div = 1000;
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

int meta(int a, int b, int *func);

int main(int argc, int *argv)  {
    int a;
    int *ptr;
    a = 4;
    ptr = &a;
    *ptr = 99;
    dumbITOA(a);
}

void fun() {
    int a;
    int b;
    int *func;
    int *funcarray;

    a = 24;
    b = 12;
    funcarray = malloc(4 * 4);
    *funcarray = &add;
    *(funcarray+1) = &sub;
    *(funcarray+2) = &mult;
    *(funcarray+3) = &div;

    func = funcarray;

    while (func != funcarray + 4) {
        dumbITOA(meta(a, b, *func));
        ++func;
    }
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int meta(int a, int b, int *fun) {
    return fun(a, b);
}








