#include <stdio.h>
#include <stdlib.h>

#include "../include/cad.h"
#include "../include/parse_files.h"
#include "../include/tests.h"

#include "../include/args.h"

void testing() {
  // char *path =
  //     "/home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/cad.r5000.p5000.xcsv";
  char *path = "/home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/test.xcsv";
  xCSV file = read_file(path);

  size_t s = file.n_lines * sizeof(Cadastro);
  Cadastro *cad = malloc(s);

  fromXCSV(file, cad);

  // selectionSort(makeORDER_DYNAMIC(cad, cpf, file.n_lines), ltLNG);
  // quickSort(makeORDER_DYNAMIC(cad, cpf, file.n_lines), ltLNG);
  // quickSortInd(makeORDER_DYNAMIC(cad, cpf, file.n_lines), ltLNG);
  // bucketSort(makeORDER_DYNAMIC(cad, cpf, file.n_lines),
  // makePREFIXES_LNG_ASC()); radixSort(makeORDER_DYNAMIC(cad, cpf,
  // file.n_lines), 'l', true); selectionSort(makeORDER_DYNAMIC(cad, nome,
  // file.n_lines), ltSTR); quickSort(makeORDER_DYNAMIC(cad, nome,
  // file.n_lines), ltSTR); quickSortInd(makeORDER_DYNAMIC(cad, nome,
  // file.n_lines), ltSTR); bucketSort(makeORDER_DYNAMIC(cad, nome,
  // file.n_lines), makePREFIXES_STR_ASC()); radixSort(makeORDER_DYNAMIC(cad,
  // nome, file.n_lines), 's', true);
}

int main(int argc, char **argv) {
  opt_t opts;
  parse_args(argc, argv, &opts);

  xCSV file = read_file(opts.file_path);

  size_t s = file.n_lines * sizeof(Cadastro);
  Cadastro *cad = malloc(s);

  fromXCSV(file, cad);

  if (opts.debug) {
    runTests();
    for (int i = 0; i < file.n_lines; i++) {
      fprintf(stdout, "%lu\t%s\n", cad[i].cpf, cad[i].nome);
    }
  }

  if (cad)
    free(cad);
  exit(EXIT_SUCCESS);
}
