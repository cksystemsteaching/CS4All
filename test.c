int main(int argc, int* argv) {
    int i;

    i = 0;

    while (i < 5) {
        write(1, "Testoutput...", 50);
        i = i + 1;
    }

    return 0;
}