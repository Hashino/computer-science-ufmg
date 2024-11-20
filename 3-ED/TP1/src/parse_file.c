#include "../include/parse_files.h"
#include <stdlib.h>

#define MAX_LEN 300

FILE *f;
char *line = "";
size_t curr_len = 0;

xCSV csv;

bool open_file(char *path) {
  f = fopen(path, "r");
  return f == NULL;
}

xCSV read_file(char *path) {
  erroAssert(open_file(path), "Couldn't open file");

  getline(&line, &curr_len, f);
  int n_fields = strtol(line, NULL, 10);

  for (int i = 0; i < n_fields; i++) {
    getline(&line, &curr_len, f);
  }

  getline(&line, &curr_len, f);
  int n_lines = strtol(line, NULL, 10);

  csv = (xCSV){n_fields, n_lines};

  csv.data = malloc((csv.n_lines) * (sizeof(char) * MAX_LEN));

  for (int i = 0; i < csv.n_lines; i++) {
    getline(&csv.data[i], &curr_len, f);
  }

  return csv;
}

void close_file() {
  if (f)
    fclose(f);
  if (csv.data)
    free(csv.data);
}
