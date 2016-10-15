

int zero = 48;
int EOString = 0;
int newline = 10;
int *dumbATOI(int number, int* stringBuf);

int *dumbATOI(int number, int* stringBuf) {
    int tmpNumber;
    int* startPointer;

    number = number * 10;
    startPointer = stringBuf;

    if (number == 0) {
        *stringBuf = zero;
        //write(1, stringBuf, 1);
        stringBuf = stringBuf + 1;
    } else {
        while (number > 0) {
            tmpNumber = number % 10;
            *stringBuf = zero + tmpNumber;
            //write(1, stringBuf, 1);
            stringBuf = stringBuf + 1;
            number = number / 10;
        }
    }
    *stringBuf = EOString;

    return startPointer;
}

int main(int argc, int *argv) {
    int someMath;
    int someMath2;
    int someMath3;
    int hypsterIDVar;
    int *stringBuff;

    someMath = 2;
    someMath2 = 3;
    someMath3 = 4;

    stringBuff = malloc(50);

    someMath = someMath2 * someMath;

    someMath3 = someMath3 + someMath2;

    someMath2 = someMath3 - someMath;

    //1 == filedescriptor for shell
    write(1, (int *) "assign2text executed with result: ", 50);
    hypsterIDVar = 11;//hypster_ID();
    dumbATOI(hypsterIDVar, stringBuff);
    while (*stringBuff != 0){
        write(1, stringBuff, 1);
        stringBuff = stringBuff + 1;
    }
    *stringBuff = newline; //newline
    write(1, stringBuff, 1);

    return 0;
}