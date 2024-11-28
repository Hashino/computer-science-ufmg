#include "../include/stats.h"

typedef struct Stats {
  struct timespec t0;
  struct timespec t_init;
  struct timespec t_end;
  bool memlog_enabled;
} Stats;

Stats s;

struct timespec clkDiff(struct timespec t1, struct timespec t2) {

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

FILE *f_stats;

bool open_stats_file(char *path) {
  f_stats = fopen(path, "w");
  return f_stats == NULL;
}

void startStats(char *path) {
  clock_gettime(CLOCK_MONOTONIC, &s.t0);

  if (path != NULL) {

    s.memlog_enabled = true;
    erroAssert(open_stats_file(path), "Couldn't open file");
  } else {
    s.memlog_enabled = false;
  }
}

void timeInit() {
  clock_gettime(CLOCK_MONOTONIC, &s.t_init);
  s.t_init = clkDiff(s.t0, s.t_init);
}

void timeEnd() {
  clock_gettime(CLOCK_MONOTONIC, &s.t_end);
  s.t_end = clkDiff(s.t0, s.t_end);
  s.t_end = clkDiff(s.t_init, s.t_end);
}

void printStats() {
  fprintf(stdout, "%ld.%.9ld\t", s.t_init.tv_sec, s.t_init.tv_nsec);
  fprintf(stdout, "%ld.%.9ld\n", s.t_end.tv_sec, s.t_end.tv_nsec);
  if (f_stats)
    fclose(f_stats);
}

void memLog(void *address) {
  if (address != NULL && s.memlog_enabled) {
    struct timespec curr;
    clock_gettime(CLOCK_MONOTONIC, &curr);
    curr = clkDiff(s.t0, curr);

    fprintf(f_stats, "%ld.%.9ld %lu\n", curr.tv_sec, curr.tv_nsec,
            (unsigned long)address);
  }
}
