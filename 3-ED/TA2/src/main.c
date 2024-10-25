//---------------------------------------------------------------------
// Arquivo      : evalenum.c
// Conteudo     : avaliacao de desempenho de algoritmos de ordenacao
// Autor        : Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico    : 2023-11-04 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../include/alg.h"

void clkDiff(struct timespec t1, struct timespec t2, struct timespec *res)
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
{
  if (t2.tv_nsec < t1.tv_nsec) {
    // ajuste necessario, utilizando um segundo de tv_sec
    res->tv_nsec = 1000000000 + t2.tv_nsec - t1.tv_nsec;
    res->tv_sec = t2.tv_sec - t1.tv_sec - 1;
  } else {
    // nao e necessario ajuste
    res->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    res->tv_sec = t2.tv_sec - t1.tv_sec;
  }
}

int main(int argc, char **argv) {
  sortperf_t s;
  int *vet;
  char buf[200];
  char pref[100];
  opt_t opt;
  struct timespec inittp, endtp, restp;
  int retp;

  // parse_args
  parse_args(argc, argv, &opt);

  // malloc with opt.size+1 for heapsort
  vet = (int *)malloc((opt.size + 1) * sizeof(int));

  // initialize
  resetcounter(&s);
  srand48(opt.seed);
  initVector(vet, opt.size);
  vet[opt.size] = vet[0]; // for heapsort
  // if (opt.size < 100) printVector(vet, opt.size);

  retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

  alg_t algvet[] = {
      {ALGINSERTION, "i"}, {ALGSELECTION, "s"}, {ALGQSORT, "q"},
      {ALGQSORT3, "q3"},   {ALGQSORTINS, "qi"}, {ALGQSORT3INS, "q3i"},
      {ALGSHELLSORT, "h"}, {ALGRECSEL, "rs"},   {0, 0}};

  // execute algorithm
  switch (opt.alg) {
  case ALGINSERTION:
    insertionSort(vet, opt.size - 1, &s);
    break;
  case ALGSELECTION:
    selectionSort(vet, opt.size - 1, &s);
    break;
  case ALGQSORT:
    quickSort(vet, opt.size - 1, &s);
    break;
  case ALGQSORT3:
    quickSort3(vet, opt.size - 1, &s);
    break;
  case ALGQSORTINS:
    quickSortIns(vet, opt.size - 1, &s);
    break;
  case ALGQSORT3INS:
    quickSort3Ins(vet, opt.size - 1, &s);
    break;
  case ALGSHELLSORT:
    shellSort(vet, opt.size, &s);
    break;
  case ALGRECSEL:
    recursiveSelectionSort(vet, 0, opt.size - 1, &s);
    break;
  }
  retp = clock_gettime(CLOCK_MONOTONIC, &endtp);
  clkDiff(inittp, endtp, &restp);

  // if (opt.size<100) printVector(vet, opt.size);

  // print stats
  sprintf(pref, "alg %s seed %d size %d time %ld.%.9ld", num2name(opt.alg),
          opt.seed, opt.size, restp.tv_sec, restp.tv_nsec);

  printsortperf(&s, buf, pref);
  printf("%s\n", buf);

  exit(0);
}
