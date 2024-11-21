#include "../include/args.h"
#include "../include/cad.h"
#include "../include/parse_files.h"
#include "../include/stats.h"
#include "../include/tests.h"

#include <sys/resource.h>
#include <time.h>

void testing() {
  // char *path =
  //     "/home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/cad.r5000.p5000.xcsv";
  char *path = "/home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/test.xcsv";
  xCSV file = read_file(path);

  size_t s = file.n_lines * sizeof(Cadastro);
  Cadastro *arr = malloc(s);

  fromXCSV(file, MAX_LEN, arr);
  close_file();

  // selectionSort(makeORDER_DYNAMIC(arr, cpf, file.n_lines), ltLNG);
  //
  // quickSort(makeORDER_DYNAMIC(arr, cpf, file.n_lines), ltLNG);
  //
  // quickSortInd(makeORDER_DYNAMIC(arr, cpf, file.n_lines), ltLNG);
  //
  // bucketSort(makeORDER_DYNAMIC(arr, cpf, file.n_lines), makePREFIXES_LNG_ASC());
  //
  // radixSort(makeORDER_DYNAMIC(arr, cpf, file.n_lines), 'l', true);
  //
  // selectionSort(makeORDER_DYNAMIC(arr, nome, file.n_lines), ltSTR);
  //
  // quickSort(makeORDER_DYNAMIC(arr, nome, file.n_lines), ltSTR);
  //
  // quickSortInd(makeORDER_DYNAMIC(arr, nome, file.n_lines), ltSTR);
  //
  // bucketSort(makeORDER_DYNAMIC(arr, nome, file.n_lines), makePREFIXES_STR_ASC());
  //
  // radixSort(makeORDER_DYNAMIC(arr, nome, file.n_lines), 's', true);

  for (int i = 0; i < file.n_lines; i++) {
    fprintf(stdout, "%s\n", toString(arr[i]));
  }

  free(arr);
}

int main(int argc, char **argv) {
  opt_t opts;
  parse_args(argc, argv, &opts);

  testing();

  // if (opts.file_path) {
  //   struct timespec inittp;
  //   clock_gettime(CLOCK_MONOTONIC, &inittp);
  //
  //   xCSV file = read_file(opts.file_path);
  //
  //   size_t s = file.n_lines * sizeof(Cadastro);
  //   Cadastro *arr = malloc(s);
  //
  //   fromXCSV(file, MAX_LEN, arr);
  //   close_file();
  //
  //   if (opts.alg) {
  //     switch (opts.alg[0]) {
  //     case 'q':
  //       switch (opts.alg[1]) {
  //       case 'n':
  //         if (opts.asc) {
  //           quickSortInd(makeORDER_DYNAMIC(arr, nome, file.n_lines), ltSTR);
  //         } else {
  //           quickSortInd(makeORDER_DYNAMIC(arr, nome, file.n_lines), gtSTR);
  //         }
  //         break;
  //       case 'c':
  //         if (opts.asc) {
  //           quickSortInd(makeORDER_DYNAMIC(arr, cpf, file.n_lines), ltLNG);
  //         } else {
  //           quickSortInd(makeORDER_DYNAMIC(arr, cpf, file.n_lines), gtLNG);
  //         }
  //         break;
  //       }
  //       break;
  //       break;
  //     case 'b':
  //       switch (opts.alg[1]) {
  //       case 'n':
  //         if (opts.asc) {
  //           bucketSort(makeORDER_DYNAMIC(arr, nome, file.n_lines),
  //                      makePREFIXES_STR_ASC());
  //         } else {
  //           bucketSort(makeORDER_DYNAMIC(arr, nome, file.n_lines),
  //                      makePREFIXES_STR_DES());
  //         }
  //         break;
  //       case 'c':
  //         if (opts.asc) {
  //           bucketSort(makeORDER_DYNAMIC(arr, cpf, file.n_lines),
  //                      makePREFIXES_LNG_ASC());
  //         } else {
  //           bucketSort(makeORDER_DYNAMIC(arr, cpf, file.n_lines),
  //                      makePREFIXES_LNG_DES());
  //         }
  //         break;
  //       }
  //       break;
  //     case 'r':
  //       switch (opts.alg[1]) {
  //       case 'n':
  //         radixSort(makeORDER_DYNAMIC(arr, nome, file.n_lines), 's',
  //         opts.asc); break;
  //       case 'c':
  //         radixSort(makeORDER_DYNAMIC(arr, cpf, file.n_lines), 'l',
  //         opts.asc); break;
  //       }
  //       break;
  //     default:
  //       warnAssert(opts.alg, "invalid algorithm");
  //     }
  //   } else {
  //     warnAssert(!opts.alg, "no sorting algorithm specified");
  //   }
  //
  //   if (opts.debug) {
  //     for (int i = 0; i < file.n_lines; i++) {
  //       fprintf(stdout, "%s", toString(arr[i]));
  //     }
  //     struct timespec endtp;
  //     clock_gettime(CLOCK_MONOTONIC, &endtp);
  //     struct timespec t_end = clkDiff(inittp, endtp);
  //
  //     // system and user usage time
  //     int who = RUSAGE_SELF;
  //     int ret;
  //
  //     struct rusage usage;
  //     ret = getrusage(who, &usage);
  //
  //     printf("%ld.%.9ld\t", t_end.tv_sec, t_end.tv_nsec);
  //     printf("%ld.%.9ld\t", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
  //     printf("%ld.%.9ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
  //   }
  //
  //   free(arr);
  // } else {
  //   warnAssert(!opts.file_path, "no file");
  // }

  if (opts.debug) {
    runTests();
  }

  exit(EXIT_SUCCESS);
}
