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
    int a;
    int b;
    a = 5;
    b = 0;

    b = --a + 4;
    dumbITOA(a);
    dumbITOA(b);
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
		i = i + 1;
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
	*a = *a + 3;
	++*a;

	dumbITOA(*a);
}
