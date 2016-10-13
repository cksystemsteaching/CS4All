

int *dumbATOI(int number, int *stringBuf);

int *dumbATOI(int number, int *stringBuf) {
    int tmpNumber;
    int* startPointer;

    startPointer = stringBuf;

    if (number == 0) {
        *stringBuf = (int) "0";
        stringBuf = (int*) (((int)stringBuf) + 1);
        *stringBuf = (int) "\0";
    } else {
        while (number > 0) {
            tmpNumber = number % 10;
            *stringBuf = (int) ("0" + tmpNumber);
            stringBuf = (int*) (((int)stringBuf) + 1);
            number = (int) number / 10;

        }
        *stringBuf = (int) "\0";
    }
    write(1, "0", 2);
    return stringBuf;
}

int main(int argc, int *argv) {
    int someMath;
    int someMath2;
    int someMath3;
    int hypsterIDVar;
    int *stringBuff;

    stringBuff = "test output";

    write(1, stringBuff, 12);

    someMath = 2;
    someMath2 = 3;
    someMath3 = 4;

    stringBuff = malloc(50);

    someMath = someMath2 * someMath;

    someMath3 = someMath3 + someMath2;

    someMath2 = someMath3 - someMath;

    //1 == filedescriptor for shell
    write(1, (int *) "          assign2text executed with result      ", 50);
    hypsterIDVar = hypster_ID();
    dumbATOI(hypsterIDVar, stringBuff);
    write(1, stringBuff, 2);

    return 0;
}