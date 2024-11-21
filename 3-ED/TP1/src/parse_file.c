#include "../include/parse_files.h"

FILE *f = NULL;
char *line = "";
int curr_len = 0;

xCSV csv;

bool open_file(char *path) {
  f = fopen(path, "r");
  return f == NULL;
}

void read_header(char *path) {
  line = malloc(MAX_LEN * sizeof(char));
  erroAssert(open_file(path), "Couldn't open file");

  fgets(line, MAX_LEN, f);
  csv.n_fields = strtol(line, NULL, 10);

  for (int i = 0; i < csv.n_fields; i++) {
    fgets(line, MAX_LEN, f);
  }

  fgets(line, MAX_LEN, f);
  csv.n_lines = strtol(line, NULL, 10);
  free(line);
}

xCSV *read_file(char *path) {
  read_header(path);

  // INFO: first allocs a block of pointers to strings
  // after that allocs the strings
  // [**s1,**s2,**s3][*s1,*s2,*s3,*s4]
  csv.data = malloc(csv.n_lines * sizeof(char *));

  for (int i = 0; i < csv.n_lines; i++) {
    csv.data[i] = malloc(MAX_LEN * sizeof(char));
    // memLog(csv.data[i]);

    size_t s = 0;
    getline(&line, &s, f);

    snprintf(csv.data[i], MAX_LEN, "%s", line);
    csv.data[i][strcspn(csv.data[i], "\n")] = 0;

    free(line);
    line = NULL;
  }

  return &csv;
}

void close_file(xCSV *file) {
  if (f) {
    fclose(f);
  }

  for (int i = 0; i < file->n_lines; i++) {
    // memLog(file->data[i]);
    free(file->data[i]);
    file->data[i] = NULL;
  }
  // memLog(file->data);
  free(file->data);
}
