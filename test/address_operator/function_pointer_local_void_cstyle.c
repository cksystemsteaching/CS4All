void swap(int* one, int* two) {
	int  help;
	help = *one;
	*one = *two;
	*two = help;
}

int main() {

	int a;
	int b;
  void (*fp)(int*, int*);

	a = 44;
	b = 42;

  fp = &swap;

	fp(&a, &b);

	return b; //44
}
