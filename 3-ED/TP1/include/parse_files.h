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

/**
 * @return a xCSV header with parameters neeeded for parsing file 
 */
xCSV *readFile(char *);

/**
 * @brief closes file and frees all memory allocated while parsing
 *
 * @param file the file returned by read_file()
 */
void closeFile(xCSV *file);

#endif
