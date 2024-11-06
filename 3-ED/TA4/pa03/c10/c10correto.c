#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p;
  for (int i = 0; i < 10; i++) {
    p = malloc(128);
    printf("%ld\n", (long)p);
    free(p);
  }
  return 0;
}
