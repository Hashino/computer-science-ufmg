#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int *p;
  while (1) {
    p = malloc(128);
    printf("%ld\n", (long)p);
  }
  return (0);
}
