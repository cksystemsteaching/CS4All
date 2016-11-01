// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// ---------------------     L I B R A R Y     ---------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ----------------------- BUILTIN PROCEDURES ----------------------
// -----------------------------------------------------------------

void exit(int code);
int read(int fd, int* buffer, int bytesToRead);
int write(int fd, int* buffer, int bytesToWrite);
int open(int* filename, int flags, int mode);
int* malloc(int size);

// -----------------------------------------------------------------
// ----------------------- LIBRARY PROCEDURES ----------------------
// -----------------------------------------------------------------

void initLibrary();
void resetLibrary();

int twoToThePowerOf(int p);
int leftShift(int n, int b);
int rightShift(int n, int b);

int  loadCharacter(int* s, int i);
int* storeCharacter(int* s, int i, int c);

int  stringLength(int* s);
void stringReverse(int* s);
int  stringCompare(int* s, int* t);

int  atoi(int* s);
int* itoa(int n, int* s, int b, int a, int p);

int fixedPointRatio(int a, int b);

void putCharacter(int c);

void print(int* s);
void println();

void printCharacter(int c);
void printString(int* s);
void printInteger(int n);
void printFixedPointPercentage(int a, int b);
void printFixedPointRatio(int a, int b);
void printHexadecimal(int n, int a);
void printOctal(int n, int a);
void printBinary(int n, int a);

int roundUp(int n, int m);


// ------------------------ GLOBAL CONSTANTS -----------------------

int CHAR_EOF          = -1; // end of file
int CHAR_TAB          = 9;  // ASCII code 9  = tabulator
int CHAR_LF           = 10; // ASCII code 10 = line feed
int CHAR_CR           = 13; // ASCII code 13 = carriage return
int CHAR_SPACE        = ' ';
int CHAR_SEMICOLON    = ';';
int CHAR_PLUS         = '+';
int CHAR_DASH         = '-';
int CHAR_ASTERISK     = '*';
int CHAR_SLASH        = '/';
int CHAR_UNDERSCORE   = '_';
int CHAR_EQUAL        = '=';
int CHAR_LPARENTHESIS = '(';
int CHAR_RPARENTHESIS = ')';
int CHAR_LBRACE       = '{';
int CHAR_RBRACE       = '}';
int CHAR_COMMA        = ',';
int CHAR_LT           = '<';
int CHAR_GT           = '>';
int CHAR_EXCLAMATION  = '!';
int CHAR_PERCENTAGE   = '%';
int CHAR_SINGLEQUOTE  = 39; // ASCII code 39 = '
int CHAR_DOUBLEQUOTE  = '"';

int SIZEOFINT     = 4; // must be the same as WORDSIZE
int SIZEOFINTSTAR = 4; // must be the same as WORDSIZE

int* power_of_two_table;

int INT_MAX; // maximum numerical value of a signed 32-bit integer
int INT_MIN; // minimum numerical value of a signed 32-bit integer

int INT16_MAX; // maximum numerical value of a signed 16-bit integer
int INT16_MIN; // minimum numerical value of a signed 16-bit integer

int maxFilenameLength = 128;

int* character_buffer; // buffer for reading and writing characters
int* integer_buffer;   // buffer for printing integers
int* filename_buffer;  // buffer for opening files
int* binary_buffer;    // buffer for binary I/O

// flags for opening read-only files
// LINUX:       0 = 0x0000 = O_RDONLY (0x0000)
// MAC:         0 = 0x0000 = O_RDONLY (0x0000)
// WINDOWS: 32768 = 0x8000 = _O_BINARY (0x8000) | _O_RDONLY (0x0000)
// since LINUX/MAC do not seem to mind about _O_BINARY set
// we use the WINDOWS flags as default
int O_RDONLY = 32768;

// flags for opening write-only files
// MAC: 1537 = 0x0601 = O_CREAT (0x0200) | O_TRUNC (0x0400) | O_WRONLY (0x0001)
int MAC_O_CREAT_TRUNC_WRONLY = 1537;

// LINUX: 577 = 0x0241 = O_CREAT (0x0040) | O_TRUNC (0x0200) | O_WRONLY (0x0001)
int LINUX_O_CREAT_TRUNC_WRONLY = 577;

// WINDOWS: 33537 = 0x8301 = _O_BINARY (0x8000) | _O_CREAT (0x0100) | _O_TRUNC (0x0200) | _O_WRONLY (0x0001)
int WINDOWS_O_BINARY_CREAT_TRUNC_WRONLY = 33537;

// flags for rw-r--r-- file permissions
// 420 = 00644 = S_IRUSR (00400) | S_IWUSR (00200) | S_IRGRP (00040) | S_IROTH (00004)
// these flags seem to be working for LINUX, MAC, and WINDOWS
int S_IRUSR_IWUSR_IRGRP_IROTH = 420;

int MEGABYTE = 1048576;

int VIRTUALMEMORYSIZE = 67108864; // 64MB of virtual memory

int WORDSIZE = 4; // must be the same as SIZEOFINT and SIZEOFINTSTAR

// ------------------------ GLOBAL VARIABLES -----------------------

int numberOfWrittenCharacters = 0;

int* outputName = (int*) 0;
int  outputFD   = 1;

int* selfieName = (int*) 0;

// ------------------------- INITIALIZATION ------------------------

void initLibrary() {
  int i;

  // powers of two table with 31 entries for 2^0 to 2^30
  // avoiding overflow for 2^31 and larger numbers with 32-bit signed integers
  power_of_two_table = malloc(31 * SIZEOFINT);

  *power_of_two_table = 1; // 2^0 == 1

  i = 1;

  while (i < 31) {
    // compute powers of two incrementally using this recurrence relation
    *(power_of_two_table + i) = *(power_of_two_table + (i - 1)) * 2;

    i = i + 1;
  }

  // compute INT_MAX and INT_MIN without integer overflows
  INT_MAX = (twoToThePowerOf(30) - 1) * 2 + 1;
  INT_MIN = -INT_MAX - 1;

  INT16_MAX = twoToThePowerOf(15) - 1;
  INT16_MIN = -INT16_MAX - 1;

  // allocate and touch to make sure memory is mapped for read calls
  character_buffer  = malloc(1);
  *character_buffer = 0;

  // accommodate at least 32-bit numbers for itoa, no mapping needed
  integer_buffer = malloc(33);

  // does not need to be mapped
  filename_buffer = malloc(maxFilenameLength);

  // allocate and touch to make sure memory is mapped for read calls
  binary_buffer  = malloc(SIZEOFINT);
  *binary_buffer = 0;

  selfieName=(int*)"testlib";
}

void resetLibrary() {
  numberOfWrittenCharacters = 0;
}

// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~
// -----------------------------------------------------------------
// ---------------------     L I B R A R Y     ---------------------
// -----------------------------------------------------------------
// *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~ *~*~

// -----------------------------------------------------------------
// ----------------------- LIBRARY PROCEDURES ----------------------
// -----------------------------------------------------------------

int twoToThePowerOf(int p) {
  // assert: 0 <= p < 31
  return *(power_of_two_table + p);
}

int leftShift(int n, int b) {
  // assert: b >= 0;

  if (b < 31)
    // left shift of integers works by multiplication with powers of two
    return n * twoToThePowerOf(b);
  else if (b == 31)
    // twoToThePowerOf(b) only works for b < 31
    return n * twoToThePowerOf(30) * 2;
  else
    // left shift of a 32-bit integer by more than 31 bits is always 0
    return 0;
}

int rightShift(int n, int b) {
  // assert: b >= 0

  if (n >= 0) {
    if (b < 31)
      // right shift of positive integers works by division with powers of two
      return n / twoToThePowerOf(b);
    else
      // right shift of a 32-bit integer by more than 31 bits is always 0
      return 0;
  } else if (b < 31)
    // right shift of negative integers requires resetting the sign bit first,
    // then dividing with powers of two, and finally restoring the sign bit
    // but b bits to the right; this works even if n == INT_MIN
    return ((n + 1) + INT_MAX) / twoToThePowerOf(b) +
      (INT_MAX / twoToThePowerOf(b) + 1);
  else if (b == 31)
    // right shift of a negative 32-bit integer by 31 bits is 1 (the sign bit)
    return 1;
  else
    // right shift of a 32-bit integer by more than 31 bits is always 0
    return 0;
}

int loadCharacter(int* s, int i) {
  // assert: i >= 0
  int a;

  // a is the index of the word where the to-be-loaded i-th character in s is
  a = i / SIZEOFINT;

  // shift to-be-loaded character to the left resetting all bits to the left
  // then shift to-be-loaded character all the way to the right and return
  return rightShift(leftShift(*(s + a), ((SIZEOFINT - 1) - (i % SIZEOFINT)) * 8), (SIZEOFINT - 1) * 8);
}

int* storeCharacter(int* s, int i, int c) {
  // assert: i >= 0, all characters are 7-bit
  int a;

  // a is the index of the word where the with c
  // to-be-overwritten i-th character in s is
  a = i / SIZEOFINT;

  // subtract the to-be-overwritten character resetting its bits in s
  // then add c setting its bits at the i-th position in s
  *(s + a) = (*(s + a) - leftShift(loadCharacter(s, i), (i % SIZEOFINT) * 8)) + leftShift(c, (i % SIZEOFINT) * 8);

  return s;
}

int stringLength(int* s) {
  int i;

  i = 0;

  while (loadCharacter(s, i) != 0)
    i = i + 1;

  return i;
}

void stringReverse(int* s) {
  int i;
  int j;
  int tmp;

  i = 0;
  j = stringLength(s) - 1;

  while (i < j) {
    tmp = loadCharacter(s, i);

    storeCharacter(s, i, loadCharacter(s, j));
    storeCharacter(s, j, tmp);

    i = i + 1;
    j = j - 1;
  }
}

int stringCompare(int* s, int* t) {
  int i;

  i = 0;

  while (1)
    if (loadCharacter(s, i) == 0)
      if (loadCharacter(t, i) == 0)
        return 1;
      else
        return 0;
    else if (loadCharacter(s, i) == loadCharacter(t, i))
      i = i + 1;
    else
      return 0;
}

int atoi(int* s) {
  int i;
  int n;
  int c;

  // the conversion of the ASCII string in s to its numerical value n
  // begins with the leftmost digit in s
  i = 0;

  // and the numerical value 0 for n
  n = 0;

  c = loadCharacter(s, i);

  // loop until s is terminated
  while (c != 0) {
    // the numerical value of ASCII-encoded decimal digits
    // is offset by the ASCII code of '0' (which is 48)
    c = c - '0';

    if (c < 0)
      // c was not a decimal digit
      return -1;
    else if (c > 9)
      // c was not a decimal digit
      return -1;

    // assert: s contains a decimal number, that is, with base 10
    n = n * 10 + c;

    // go to the next digit
    i = i + 1;

    c = loadCharacter(s, i);

    if (n < 0) {
      // the only negative number for n allowed here is INT_MIN
      if (n != INT_MIN)
        // but n is not INT_MIN which may happen because of an earlier
        // integer overflow if the number in s is larger than INT_MAX
        return -1;
      else if (c != 0)
        // n is INT_MIN but s is not terminated yet
        return -1;
    }
  }

  return n;
}

int* itoa(int n, int* s, int b, int a, int p) {
  // assert: b in {2,4,8,10,16}

  int i;
  int sign;
  int msb;

  // the conversion of the integer n to an ASCII string in s
  // with base b, alignment a, and fixed point p
  // begins with the leftmost digit in s
  i = 0;

  // for now assuming n is positive
  sign = 0;

  // and msb not set
  msb = 0;

  if (n == 0) {
    storeCharacter(s, 0, '0');

    i = 1;
  } else if (n < 0) {
    // convert n to a positive number but remember the sign
    sign = 1;

    if (b == 10) {
      if (n == INT_MIN) {
        // rightmost decimal digit of 32-bit INT_MIN
        storeCharacter(s, 0, '8');

        // avoids overflow
        n = -(n / 10);
        i = 1;
      } else
        n = -n;
    } else {
      if (n == INT_MIN) {
        // rightmost non-decimal digit of INT_MIN
        storeCharacter(s, 0, '0');

        // avoids setting n to 0
        n = (rightShift(INT_MIN, 1) / b) * 2;
        i = 1;
      } else {
        // reset msb, restore below
        n   = rightShift(leftShift(n, 1), 1);
        msb = 1;
      }
    }

    // assert: n > 0
  }

  while (n != 0) {
    if (p > 0)
      if (i == p) {
        storeCharacter(s, i, '.'); // set point of fixed point number

        // go to the next digit
        i = i + 1;

        // we are done with the fixed point
        p = 0;
      }

    if (n % b > 9)
      // the ASCII code of hexadecimal digits larger than 9
      // is offset by the ASCII code of 'A' (which is 65)
      storeCharacter(s, i, n % b - 10 + 'A');
    else
      // the ASCII code of digits less than or equal to 9
      // is offset by the ASCII code of '0' (which is 48)
      storeCharacter(s, i, n % b + '0');

    // convert n by dividing n with base b
    n = n / b;

    i = i + 1;

    if (msb) {
      // restore msb from above
      n   = n + (rightShift(INT_MIN, 1) / b) * 2;
      msb = 0;
    }
  }

  if (p > 0) {
    while (i < p) {
      storeCharacter(s, i, '0'); // no point yet, fill with 0s

      i = i + 1;
    }

    storeCharacter(s, i, '.'); // set point
    storeCharacter(s, i + 1, '0'); // leading 0

    // go to the second next digit
    i = i + 2;

    // we are done with the fixed point
    p = 0;
  }

  if (b == 10) {
    if (sign) {
      storeCharacter(s, i, '-'); // negative decimal numbers start with -

      i = i + 1;
    }

    while (i < a) {
      storeCharacter(s, i, ' '); // align with spaces

      i = i + 1;
    }
  } else {
    while (i < a) {
      storeCharacter(s, i, '0'); // align with 0s

      i = i + 1;
    }

    if (b == 8) {
      storeCharacter(s, i, '0');   // octal numbers start with 00
      storeCharacter(s, i + 1, '0');

      i = i + 2;
    } else if (b == 16) {
      storeCharacter(s, i, 'x');   // hexadecimal numbers start with 0x
      storeCharacter(s, i + 1, '0');

      i = i + 2;
    }
  }

  storeCharacter(s, i, 0); // null-terminated string

  // our numeral system is positional hindu-arabic, that is,
  // the weight of digits increases right to left, which means
  // that we need to reverse the string we computed above
  stringReverse(s);

  return s;
}

int fixedPointRatio(int a, int b) {
  // compute fixed point ratio with 2 fractional digits

  // multiply a/b with 100 but avoid overflow

  if (a <= INT_MAX / 100) {
    if (b != 0)
      return a * 100 / b;
  } else if (a <= INT_MAX / 10) {
    if (b / 10 != 0)
      return a * 10 / (b / 10);
  } else {
    if (b / 100 != 0)
      return a / (b / 100);
  }

  return 0;
}

int fixedPointPercentage(int r) {
  if (r != 0)
    // 1000000 = 10000 (for 100.00%) * 100 (for 2 fractional digits of r)
    return 1000000 / r;
  else
    return 0;
}

void putCharacter(int c) {
  *character_buffer = c;

  // assert: character_buffer is mapped

  // try to write 1 character from character_buffer
  // into file with outputFD file descriptor
  if (write(outputFD, character_buffer, 1) == 1) {
    if (outputFD != 1)
      // count number of characters written to a file,
      // not the console which has file descriptor 1
      numberOfWrittenCharacters = numberOfWrittenCharacters + 1;
  } else {
    // write failed
    if (outputFD != 1) {
      // failed write was not to the console which has file descriptor 1
      // to report the error we may thus still write to the console via print
      outputFD = 1;

      print(selfieName);
      print((int*) ": could not write character to output file ");
      print(outputName);
      println();
    }

    exit(-1);
  }
}

void print(int* s) {
  int i;

  i = 0;

  while (loadCharacter(s, i) != 0) {
    putCharacter(loadCharacter(s, i));

    i = i + 1;
  }
}

void println() {
  putCharacter(CHAR_LF);
}

void printCharacter(int c) {
  putCharacter(CHAR_SINGLEQUOTE);

  if (c == CHAR_EOF)
    print((int*) "end of file");
  else if (c == CHAR_TAB)
    print((int*) "tabulator");
  else if (c == CHAR_LF)
    print((int*) "line feed");
  else if (c == CHAR_CR)
    print((int*) "carriage return");
  else
    putCharacter(c);

  putCharacter(CHAR_SINGLEQUOTE);
}

void printString(int* s) {
  putCharacter(CHAR_DOUBLEQUOTE);

  print(s);

  putCharacter(CHAR_DOUBLEQUOTE);
}

void printInteger(int n) {
  print(itoa(n, integer_buffer, 10, 0, 0));
}

void printFixedPointPercentage(int a, int b) {
  print(itoa(fixedPointPercentage(fixedPointRatio(a, b)), integer_buffer, 10, 0, 2));
}

void printFixedPointRatio(int a, int b) {
  print(itoa(fixedPointRatio(a, b), integer_buffer, 10, 0, 2));
}

void printHexadecimal(int n, int a) {
  print(itoa(n, integer_buffer, 16, a, 0));
}

void printOctal(int n, int a) {
  print(itoa(n, integer_buffer, 8, a, 0));
}

void printBinary(int n, int a) {
  print(itoa(n, integer_buffer, 2, a, 0));
}

int roundUp(int n, int m) {
  if (n % m == 0)
    return n;
  else if (n >= 0)
    return n + m - n % m;
  else
    return n - n % m;
}

int* zalloc(int size) {
  // this procedure is only executed at boot level zero
  // zalloc allocates size bytes rounded up to word size
  // and then zeroes that memory, similar to calloc, but
  // called zalloc to avoid redeclaring calloc
  int* memory;
  int  i;

  size = roundUp(size, WORDSIZE);

  memory = malloc(size);

  size = size / WORDSIZE;

  i = 0;

  while (i < size) {
    // erase memory by setting it to 0
    *(memory + i) = 0;

    i = i + 1;
  }

  return memory;
}
