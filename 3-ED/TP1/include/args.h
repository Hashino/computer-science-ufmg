#ifndef ARGS
#define ARGS

#include <stdbool.h>

typedef struct opt {
  char *file_path;
  char *alg;
  bool asc;
  bool debug;
} opt_t;

void parse_args(int argc, char **argv, opt_t *opt);
void uso();

#endif
