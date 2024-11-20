#ifndef CADASTRO
#define CADASTRO

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../include/order.h"
#include "../include/parse_files.h"

typedef struct Cadastro {
  char nome[300];
  uint64_t cpf;
  char end[500];
  char other[500];
} Cadastro;

char *toString(Cadastro cad);

bool eqCAD(Cadastro c1, Cadastro c2);
bool eqCAD_ARR(Cadastro *arr1, Cadastro *arr2, size_t len);

void fromXCSV(xCSV csv, Cadastro* res);

void exemploCadastro();
#endif
