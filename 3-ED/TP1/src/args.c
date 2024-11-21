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

// bool in(char **arr, int len, char *target) {
//   int i;
//   for (i = 0; i < len; i++) {
//     if (strncmp(arr[i], target, strlen(target)) == 0) {
//       return true;
//     }
//   }
//   return false;
// }

void parse_args(int argc, char **argv, opt_t *opts)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
  // inicializacao variaveis globais para opcoes
  opts->debug = false;
  opts->asc = true;

  // variaveis externas do getopt
  extern char *optarg;
  extern int optind;

  // variavel auxiliar
  char c;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((c = getopt(argc, argv, "f:a:o:d")) != EOF) {
    switch (c) {
    case 'f':
      opts->file_path = optarg;
      break;
    case 'a':
      opts->alg = optarg;
      break;
    case 'o':
      if (optarg[0] == 'd') {
        opts->asc = false;
      }
      break;
    case 'd':
      opts->debug = true;
      break;
    default:
      uso();
      exit(1);
    }
  }
}
