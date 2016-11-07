//used for simple integer output in range [0 - 99];
void dumbITOA(int number);

void dumbITOA(int number) {
	int i;
	int *buff;
	int tmp;
	int ptr;
	int div;
	ptr = 0;
	div = 10;
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
    int *a;
    int b;
    a = malloc(4);
    *a = 10;
    b = --*a;
    dumbITOA(b);
    dumbITOA(*a);
}

void funcA() {
	int a;
	int b;
	a = 4;
	b = 0;
	b = 2 + ++a;

	dumbITOA(a);
	dumbITOA(b);

}

void funcB() {
	int *c;
	int *d;
	c = malloc(4);
	d = malloc(4);
	*c = 2;
	*d = 0;
	*d = ++*c + 3;

	dumbITOA(*c);
	dumbITOA(*d);
}

void funcC() {
	int *c;
	int *d;
	int i;
	int result;
	i = 0;

	c = malloc(16);
	*c = 0;
	*(c + 1) = 1;
	*(c + 2) = 2;
	*(c + 3) = 3;

	result = ++*(c+1) + 10;

	while (i < 4) {
		dumbITOA(*(c+i));
        ++i;
	}
	write(1, "result: ", 10);
	dumbITOA(result);
}

void funcD() {
	int a;
	int *b;

	a = 4;
	b = malloc(4);
	*b = 3;
	dumbITOA(a);
	++a;
	dumbITOA(a);
	write(1, "|", 4);
	dumbITOA(*b);
	++*b;
	dumbITOA(*b);
}

void funcE() {
	int a;
	a = 0;
	++a;
	++a;
	++a;
	++a;
	++a;
	++a;
	++a;
	++a;
	++a;
	++a;
	dumbITOA(a);
}

void funcF() {
    int *a;
    a = malloc(4);
    *a = 0;

    ++*a;
    ++*a;
    dumbITOA(*a);
    *a = *a + 3;
    dumbITOA(*a);
    ++*a;

    dumbITOA(*a);

}

void funcG() {
    int *a;

    a = malloc(8);
    *a = 33;
    *(a+1) = 66;

    ++a;
    *a = 99;
    --a;
    *a = 11;

    dumbITOA(*a);
    dumbITOA(*(a+1));
}

void funcH() {
    int *a;
    int *b;
    int *c;
    int i;
    i = 0;
    a = malloc(7 * 4);
    c = a;
    while (i < 7) {
        *(a+i) = i;
        ++i;
    }

    b = ++a + 4;
    *b = 88;

    i = 0;
    while (i < 7) {
        dumbITOA(*(c+i));
        ++i;
    }
}
