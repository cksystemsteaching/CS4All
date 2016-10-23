
int main(int argc, int *argv) {
    int i;
    initLibrary();
    while (i < 100000) {
        i = i + 1;
    }
    print((int*)"Process ");
    printInteger(hypster_ID());
    print((int*)" terminates with result: ");
    printInteger(i);
    println();
    return 0;
}