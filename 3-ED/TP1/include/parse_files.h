#ifndef PARSE_FILES
#define PARSE_FILES

#include "../include/msg_assert.h"
#include "../include/stats.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 500

typedef struct xCSV {
  int n_fields;
  int n_lines;
  char **data;
} xCSV;

xCSV *read_file(char *);

void close_file(xCSV *file);

#endif
