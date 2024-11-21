#include "../include/parse_files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f;
char *line;
int curr_len = 0;

xCSV csv;

bool open_file(char *path) {
  f = fopen(path, "r");
  return f == NULL;
}

xCSV read_file(char *path) {
  erroAssert(open_file(path), "Couldn't open file");

  size_t s = 0;

  line = malloc(MAX_LEN * sizeof(char));

  // getline(&line, &s, f);
  fgets(line, MAX_LEN, f);
  int n_fields = strtol(line, NULL, 10);

  for (int i = 0; i < n_fields; i++) {
    // getline(&line, &s, f);
    fgets(line, MAX_LEN, f);
  }

  // getline(&line, &s, f);
  fgets(line, MAX_LEN, f);
  int n_lines = strtol(line, NULL, 10);

  csv = (xCSV){n_fields, n_lines};

  csv.data = malloc(csv.n_lines * sizeof(char *));

  for (int i = 0; i < csv.n_lines; i++) {
    // getline(&csv.data[i], &s, f);
    // getline(&csv.data + (i * MAX_LEN * sizeof(char)), &s, f);
    csv.data[i] = malloc(MAX_LEN * sizeof(char));

    fgets(csv.data[i], MAX_LEN, f);
    csv.data[i][strcspn(csv.data[i], "\n")] = 0;

    char* final = csv.data[i];
    int i = 0;
  }

  return csv;
}

void close_file() {
  if (f) {
    fclose(f);
  }
  // for (int i =0; i < csv.n_lines; i++) {
  //   free(csv.data[i]);
  // }
}
