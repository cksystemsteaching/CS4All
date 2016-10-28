

void swap(int* one, int* two) {
	int  help;
	help = *one;
	*one = *two;
	*two = help;
}

int main(int argc, int* argv) {

	int a;
	int b;

	a = 44;
	b = 42;

	swap(&a, &b);

	return 0; //44
}
