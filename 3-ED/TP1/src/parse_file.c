#include "../include/parse_files.h"

FILE *f = NULL;
char *line = "";
int curr_len = 0;

xCSV csv;

bool open_file(char *path) {
  f = fopen(path, "r");
  return f == NULL;
}

void read_and_check_line() {
  if (fgets(line, MAX_LEN, f) == NULL) {
    erroAssert(line, "Couldn't read file line");
    exit(EXIT_FAILURE);
  }
}

void read_header(char *path) {
  line = malloc(MAX_LEN * sizeof(char));
  erroAssert(open_file(path), "Couldn't open file");

  read_and_check_line();
  csv.n_fields = strtol(line, NULL, 10);

  if (csv.n_fields == 0) {
    erroAssert(!csv.n_fields, "Couldn't read file header: number of fields");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < csv.n_fields; i++) {
    read_and_check_line();
  }

  read_and_check_line();
  csv.n_lines = strtol(line, NULL, 10);

  if (csv.n_lines == 0) {
    erroAssert(!csv.n_lines, "Couldn't read file header: number of lines");
    exit(EXIT_FAILURE);
  }

  free(line);
}

xCSV *readFile(char *path) {
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
    if (s == 0) {
      erroAssert(i, "Couldn't read data entry");
    }

    snprintf(csv.data[i], MAX_LEN, "%s", line);
    csv.data[i][strcspn(csv.data[i], "\n")] = 0;

    free(line);
    line = NULL;
  }

  return &csv;
}

void closeFile(xCSV *file) {
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
