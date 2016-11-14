int a = 0;

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

int main(int argc, int *argv) {
    int i;
    int *ptr;
    i = 0;
    while (i < 1000) {
        i = i + 1;
    }
    ptr = malloc(4);
    *ptr = 1;
    *ptr = *ptr + 1;
    a = a + 1;
    dumbITOA(a);
    dumbITOA(*ptr);
    return 0;
}