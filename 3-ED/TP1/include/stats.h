#ifndef STATS
#define STATS
#include <sys/resource.h>
#include <time.h>

typedef struct Stats {
  struct timespec t_start;
  struct timespec t1;
  struct timespec t2;
  struct timespec tend;
} Stats;

struct timespec clkDiff(struct timespec t1, struct timespec t2);
#endif
