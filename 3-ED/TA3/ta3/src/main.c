#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../include/algs.h"
#include "../include/args.h"

#include <sys/resource.h>
#include <time.h>

struct timespec clkDiff(struct timespec t1, struct timespec t2)
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
{
  struct timespec res;
  if (t2.tv_nsec < t1.tv_nsec) {
    // ajuste necessario, utilizando um segundo de tv_sec
    res.tv_nsec = 1000000000 + t2.tv_nsec - t1.tv_nsec;
    res.tv_sec = t2.tv_sec - t1.tv_sec - 1;
  } else {
    // nao e necessario ajuste
    res.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    res.tv_sec = t2.tv_sec - t1.tv_sec;
  }
  
  return res;
}

int main(int argc, char *argv[]) {
  opt_t opts;
  parse_args(argc, argv, &opts);

  // clock time start
  bool debug = false;
  struct timespec inittp;
  clock_gettime(CLOCK_MONOTONIC, &inittp);

  if (strcmp("fib", opts.alg) == 0) {
    if (opts.rec) {
      long double res = fib_rec(opts.num);
      if (opts.debug)
        printf("result: %.0Lf\n", res);
    } else {
      long double res = fib_ite(opts.num);
      if (opts.debug)
        printf("result: %.0Lf\n", res);
    }
  }
  if (strcmp("fac", opts.alg) == 0) {
    if (opts.rec) {
      long double res = fac_rec(opts.num);
      if (opts.debug)
        printf("result: %.0Lf\n", res);
    } else {
      long double res = fac_ite(opts.num);
      if (opts.debug)
        printf("result: %.0Lf\n", res);
    }
  }

  struct timespec endtp;
  clock_gettime(CLOCK_MONOTONIC, &endtp);
  struct timespec t_end = clkDiff(inittp, endtp);

  // system and user usage time
  int who = RUSAGE_SELF;
  int ret;

  struct rusage usage;
  ret = getrusage(who, &usage);

  if (opts.debug) {
    printf("%s ", opts.alg);
    printf(opts.rec ? "r " : "i ");
  }

  printf("%ld.%.9ld\t", t_end.tv_sec, t_end.tv_nsec);
  printf("%ld.%.9ld\t", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
  printf("%ld.%.9ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);

  return 0;
}
