int main() {
  // little program to demonstrate yielding
  int counter;
  counter = 5;

  while (counter > 0) {
    write(1, (int*) "Loop: ", 6);
    // TODO: print counter
    sched_yield();
    counter = counter - 1;
  }

  return 0;
}
