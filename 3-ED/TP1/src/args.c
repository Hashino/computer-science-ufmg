#include "../include/args.h"

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr, "\t-f <path>\t(caminho absoluto para o arquivo xcsv)\n");
  fprintf(stderr, "\t-a <string>\t(algoritimo)\n");
  fprintf(stderr, "\t    qual algoritimo usar e por qual atributo ordernar\n");
  fprintf(stderr, "\t    {s|r|b|q}{n|c|o}\n");
  fprintf(stderr, "\t    exemplos:\n");
  fprintf(stderr, "\t    sn \t selection sort por nome\n");
  fprintf(stderr, "\t    rc \t radix sort por cpf\n");
  fprintf(stderr, "\t    bo \t bucket sort por other\n");
  fprintf(stderr, "\t    qn \t quick sort por nome\n");
  fprintf(stderr, "\t-o <char>\t(ordernar por ordem ascendente/descendente)\n");
  fprintf(stderr, "\t    {a|d}\n");
  fprintf(stderr, "\t-d     \t(flag de debug)\n");
  fprintf(stderr, "\t    executa testes e mostra resultado da ordenação\n");
  fprintf(stderr, "\n");
  fprintf(stderr, "output: {tempo para recuperar dados} {tempo para ordenar dados}\n");
}


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
