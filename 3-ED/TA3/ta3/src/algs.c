#include "../include/algs.h"

long double fib_rec(long double n) {
  // for (int i = 0; i < 1000000; i++) {
  //   // PASSES TIME
  // }
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return (fib_rec(n - 1) + fib_rec(n - 2));
  }
}

long double fac_rec(long double n) {
  // for (int i = 0; i < 1000000; i++) {
  //   // PASSES TIME
  // }
  if (n == 0) {
    return 1;
  } else {
    return n * fac_rec(n - 1);
  }
}

long double fib_ite(long double n) {
  long double last = 1;
  long double prev = 0;
  long double i;

  for (i = 1; i < n; ++i) {
    // for (int i = 0; i < 1000000; i++) {
    //   // PASSES TIME
    // }
    long double next = prev + last;

    prev = last;
    last = next;
  }

  return last;
}

long double fac_ite(long double n) {
  long double fact = 1;

  for (int i = 1; i <= n; i++) {
    // for (int i = 0; i < 1000000; i++) {
    //   // PASSES TIME
    // }
    fact = fact * i;
  }
  return fact;
}
