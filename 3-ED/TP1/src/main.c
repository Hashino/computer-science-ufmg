#include "../include/args.h"
#include "../include/cad.h"
#include "../include/parse_files.h"
#include "../include/stats.h"
#include "../include/tests.h"

#include <stdio.h>
#include <sys/resource.h>
#include <time.h>

opt_t opts;

xCSV *file;
Cadastro *arr;

void initialize() {

  file = readFile(opts.file_path);

  size_t s = file->n_lines * sizeof(Cadastro);
  arr = malloc(s);

  fromXCSV(file, MAX_LEN, arr);
  closeFile(file);
}

void choose_sort_alg() {
  if (opts.alg) {
    switch (opts.alg[0]) {
    case 's':
      switch (opts.alg[1]) {
      case 'n':
        selectionSort(makeORDER_DYN(arr, nome, file->n_lines),
                      opts.asc ? ltSTR : gtSTR);
        break;
      case 'c':
        selectionSort(makeORDER_DYN(arr, cpf, file->n_lines),
                      opts.asc ? ltSTR : gtSTR);
        break;
      case 'o':
        selectionSort(makeORDER_DYN(arr, other, file->n_lines),
                      opts.asc ? ltSTR : gtSTR);
        break;
      }
      break;
    case 'q':
      switch (opts.alg[1]) {
      case 'n':
        if (opts.asc) {
          quickSortInd(makeORDER_DYN(arr, nome, file->n_lines), ltSTR);
        } else {
          quickSortInd(makeORDER_DYN(arr, nome, file->n_lines), gtSTR);
        }
        break;
      case 'c':
        if (opts.asc) {
          quickSortInd(makeORDER_DYN(arr, cpf, file->n_lines), ltLNG);
        } else {
          quickSortInd(makeORDER_DYN(arr, cpf, file->n_lines), gtLNG);
        }
        break;
      case 'o':
        if (opts.asc) {
          quickSortInd(makeORDER_DYN(arr, other, file->n_lines), ltSTR);
        } else {
          quickSortInd(makeORDER_DYN(arr, other, file->n_lines), gtSTR);
        }
        break;
      }
      break;
    case 'Q':
      switch (opts.alg[1]) {
      case 'n':
        if (opts.asc) {
          quickSort(makeORDER_DYN(arr, nome, file->n_lines), ltSTR);
        } else {
          quickSort(makeORDER_DYN(arr, nome, file->n_lines), gtSTR);
        }
        break;
      case 'c':
        if (opts.asc) {
          quickSort(makeORDER_DYN(arr, cpf, file->n_lines), ltLNG);
        } else {
          quickSort(makeORDER_DYN(arr, cpf, file->n_lines), gtLNG);
        }
        break;
      case 'o':
        if (opts.asc) {
          quickSort(makeORDER_DYN(arr, other, file->n_lines), ltSTR);
        } else {
          quickSort(makeORDER_DYN(arr, other, file->n_lines), gtSTR);
        }
        break;
      }
      break;
    case 'b':
      switch (opts.alg[1]) {
      case 'n':
        if (opts.asc) {
          bucketSort(makeORDER_DYN(arr, nome, file->n_lines),
                     makePRFX_STR_ASC());
        } else {
          bucketSort(makeORDER_DYN(arr, nome, file->n_lines),
                     makePRFX_STR_DES());
        }
        break;
      case 'c':
        if (opts.asc) {
          bucketSort(makeORDER_DYN(arr, cpf, file->n_lines),
                     makePRFX_LNG_ASC());
        } else {
          bucketSort(makeORDER_DYN(arr, cpf, file->n_lines),
                     makePRFX_LNG_DES());
        }
        break;
      case 'o':
        if (opts.asc) {
          bucketSort(makeORDER_DYN(arr, other, file->n_lines),
                     makePRFX_STR_ASC());
        } else {
          bucketSort(makeORDER_DYN(arr, other, file->n_lines),
                     makePRFX_STR_DES());
        }
        break;
      }
      break;
    case 'r':
      switch (opts.alg[1]) {
      case 'n':
        radixSort(makeORDER_DYN(arr, nome, file->n_lines), 's', opts.asc);
        break;
      case 'c':
        radixSort(makeORDER_DYN(arr, cpf, file->n_lines), 'l', opts.asc);
        break;
      case 'o':
        radixSort(makeORDER_DYN(arr, other, file->n_lines), 's', opts.asc);
        break;
      }
      break;
    default:
      warnAssert(opts.alg, "invalid algorithm");
      uso();
      break;
    }
  } else {
    warnAssert(!opts.alg, "no sorting algorithm specified");
    uso();
  }
}

void finish() {
  if (opts.debug) {
    for (int i = 0; i < file->n_lines; i++) {
      // memLog(arr + i);
      char cpf[12];
      snprintf(cpf, 12, "%11lu", arr[i].cpf);
      for (int i = 0; i < 12; i++) {
        if (cpf[i] == ' ') {
          cpf[i] = '0';
        }
      }

      fprintf(stdout, "%-30s\t%s\n", arr[i].nome, cpf);
    }
    fprintf(stdout, "\n");
  }

  printStats();

  free(arr);
}

int main(int argc, char **argv) {

  parse_args(argc, argv, &opts);

  if (opts.file_path) {
    startStats();

    initialize();
    timeInit();

    choose_sort_alg();
    timeEnd();

    finish();
  } else {
    warnAssert(!opts.file_path, "no file");
    uso();
  }

  if (opts.debug) {
    runTests();
  }

  exit(EXIT_SUCCESS);
}
