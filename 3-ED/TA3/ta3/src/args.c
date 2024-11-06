#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/args.h"

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr, "\t-n <int>\t(input number)\n");
  fprintf(stderr, "\t-a <fib|fac>\t(algorithm)\n");
  fprintf(stderr, "\t    fib \t fibonacci\n");
  fprintf(stderr, "\t    fac \t factorial\n");
  fprintf(stderr, "\t-r \t(recursive implementation)\n");
  fprintf(stderr, "\t-i \t(iteractive implementation)\n");
  fprintf(stderr, "\n");
  fprintf(stderr, "output: {clock_time} {system_time} {user_time}\n");
}

char *algs[] = {"fib", "fac"};
#define ALG_LEN 2

bool in(char **arr, int len, char *target) {
  int i;
  for (i = 0; i < len; i++) {
    if (strncmp(arr[i], target, strlen(target)) == 0) {
      return true;
    }
  }
  return false;
}

void parse_args(int argc, char **argv, opt_t *opts)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
  // variaveis externas do getopt
  extern char *optarg;
  extern int optind;

  // variavel auxiliar
  char c;

  // inicializacao variaveis globais para opcoes
  opts->num = 0;
  opts->alg = "\0";
  opts->rec = false;
  opts->debug = false;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((c = getopt(argc, argv, "n:a:rid")) != EOF) {
    switch (c) {
    case 'n':
      opts->num = atoi(optarg);
      break;
    case 'a':
      opts->alg = optarg;
      break;
    case 'r':
      opts->rec = true;
      break;
    case 'i':
      opts->rec = false;
      break;
    case 'd':
      opts->debug = true;
      break;
    default:
      uso();
      exit(1);
    }
  }
  if (opts->num == 0 || !in(algs, ALG_LEN, opts->alg)) {
    uso();
    exit(1);
  }
}
