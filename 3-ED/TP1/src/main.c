#include "../include/args.h"
#include "../include/cad.h"
#include "../include/parse_files.h"
#include "../include/stats.h"
#include "../include/tests.h"

#include <sys/resource.h>
#include <time.h>

opt_t opts;
struct timespec inittp;

xCSV *file;
Cadastro *cadastros;

void initialize() {
  clock_gettime(CLOCK_MONOTONIC, &inittp);

  file = read_file(opts.file_path);

  size_t s = file->n_lines * sizeof(Cadastro);
  cadastros = malloc(s);

  fromXCSV(file, MAX_LEN, cadastros);
  close_file(file);
}

void choose_sort_alg() {

  if (opts.alg) {
    switch (opts.alg[0]) {
    case 'q':
      switch (opts.alg[1]) {
      case 'n':
        if (opts.asc) {
          quickSortInd(makeORDER_DYNAMIC(cadastros, nome, file->n_lines),
                       ltSTR);
        } else {
          quickSortInd(makeORDER_DYNAMIC(cadastros, nome, file->n_lines),
                       gtSTR);
        }
        break;
      case 'c':
        if (opts.asc) {
          quickSortInd(makeORDER_DYNAMIC(cadastros, cpf, file->n_lines), ltLNG);
        } else {
          quickSortInd(makeORDER_DYNAMIC(cadastros, cpf, file->n_lines), gtLNG);
        }
        break;
      }
      break;
      break;
    case 'b':
      switch (opts.alg[1]) {
      case 'n':
        if (opts.asc) {
          bucketSort(makeORDER_DYNAMIC(cadastros, nome, file->n_lines),
                     makePREFIXES_STR_ASC());
        } else {
          bucketSort(makeORDER_DYNAMIC(cadastros, nome, file->n_lines),
                     makePREFIXES_STR_DES());
        }
        break;
      case 'c':
        if (opts.asc) {
          bucketSort(makeORDER_DYNAMIC(cadastros, cpf, file->n_lines),
                     makePREFIXES_LNG_ASC());
        } else {
          bucketSort(makeORDER_DYNAMIC(cadastros, cpf, file->n_lines),
                     makePREFIXES_LNG_DES());
        }
        break;
      }
      break;
    case 'r':
      switch (opts.alg[1]) {
      case 'n':
        radixSort(makeORDER_DYNAMIC(cadastros, nome, file->n_lines), 's',
                  opts.asc);
        break;
      case 'c':
        radixSort(makeORDER_DYNAMIC(cadastros, cpf, file->n_lines), 'l',
                  opts.asc);
        break;
      }
      break;
    default:
      warnAssert(opts.alg, "invalid algorithm");
    }
  } else {
    warnAssert(!opts.alg, "no sorting algorithm specified");
  }
}

void finish() {
  if (opts.debug) {
    for (int i = 0; i < file->n_lines; i++) {
      fprintf(stdout, "%s\n", toString(cadastros[i]));
    }
  }

  struct timespec endtp;
  clock_gettime(CLOCK_MONOTONIC, &endtp);
  struct timespec t_end = clkDiff(inittp, endtp);

  // system and user usage time
  int who = RUSAGE_SELF;
  int ret;

  struct rusage usage;
  ret = getrusage(who, &usage);

  printf("%ld.%.9ld\t", t_end.tv_sec, t_end.tv_nsec);
  printf("%ld.%.9ld\t", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
  printf("%ld.%.9ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);

  free(cadastros);
}

int main(int argc, char **argv) {
  parse_args(argc, argv, &opts);

  if (opts.file_path) {

    initialize();

    choose_sort_alg();

    finish();
  } else {
    warnAssert(!opts.file_path, "no file");
  }

  if (opts.debug) {
    runTests();
  }

  exit(EXIT_SUCCESS);
}
