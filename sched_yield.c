int* itoa(int i);

int main() {
  // little program to demonstrate yielding
  int  repeats;
  int* counterConv;
  int* output;
  repeats = 10;

  while (repeats > 0) {
    write(1, (int*) "LOOP: ", 6);
    counterConv = itoa(repeats);
    write(1, counterConv, 2);
    write(1, (int*) " ; ", 3);
    sched_yield();
    repeats = repeats - 1;
  }

  return 0;
}

int* itoa(int i) {
  int* str;
  str = malloc(20);

  if (i == 0) return (int*) " 0";
  else if (i == 1) return (int*) " 1";
  else if (i == 2) return (int*) " 2";
  else if (i == 3) return (int*) " 3";
  else if (i == 4) return (int*) " 4";
  else if (i == 5) return (int*) " 5";
  else if (i == 6) return (int*) " 6";
  else if (i == 7) return (int*) " 7";
  else if (i == 8) return (int*) " 8";
  else if (i == 9) return (int*) " 9";
  else return (int*) "10"; // if i == 10
}
