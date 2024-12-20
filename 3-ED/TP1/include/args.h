#ifndef ARGS
#define ARGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct opt {
  char *file_path;
  char *alg;
  char *memlog_file;
  bool asc;
  bool debug;
} opt_t;

// parse arguments to opt
void parse_args(int argc, char **argv, opt_t *opt);

// displays correct application use
void uso();

#endif
