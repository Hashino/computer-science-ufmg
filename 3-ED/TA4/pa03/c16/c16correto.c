#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b) {
  if (b == 0) {
    fprintf(stderr, "%s", "division by zero\n");
    return 1;
  }
  return a / b;
}

int calc() {
  int a;
  int b;
  a = 13;
  b = 0;
  actual_calc(a, b);
  return 0;
}

int main() {
  calc();
  return 0;
}
