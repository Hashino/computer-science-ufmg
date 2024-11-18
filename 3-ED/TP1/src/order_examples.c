#include "../include/order.h"
#include <stdlib.h>

#pragma region examples

void exampleStatic() {
  struct Data {
    char value[100];
    int key;
  };

  struct Data entries[6] = {
      {"Iam", 6},     {"Gabriel", 1}, {"Samuel", 5},
      {"Gileade", 2}, {"Inaue", 4},   {"Marcos", 3},
  };

  selectionSort(makeORDER(entries, value), ltSTR);
}

void exampleDynamic() {
  typedef struct Data {
    char value[100];
    int key;
  } Data;

  int entry_size = 6;
  struct Data *entries = malloc(sizeof(Data) * entry_size);

  entries[0] = (Data){"Iam", 6};
  entries[1] = (Data){"Gabriel", 1};
  entries[2] = (Data){"Samuel", 5};
  entries[3] = (Data){"Gileade", 2};
  entries[4] = (Data){"Inaue", 4};
  entries[5] = (Data){"Marcos", 3};

  selectionSort(makeORDER_DYNAMIC(entries, value, 6), gtSTR);
}

void exampleBucket() {
  typedef struct Cadastro {
    char nome[10];
    int cpf;
    char end[10];
  } Cadastro;

  Cadastro cad[7] = {
      {.nome = "Iam", .cpf = 666, .end = "Ravara"},
      {.nome = "Gabriel", .cpf = 567, .end = "Coelho"},
      {.nome = "Samuel", .cpf = 294, .end = "Brum"},
      {.nome = "Gileade", .cpf = 361, .end = "Valente"},
      {.nome = "Inaue", .cpf = 879, .end = "NãoSei"},
      {.nome = "Marcos", .cpf = 193, .end = "NãoLembro"},
      {.nome = "Fernando", .cpf = 772, .end = "NãoLembro"},
  };

  bucketSort(makeORDER(cad, cpf), makeBUCKET_INT(), ltINT);
  // bucketSort( makeORDER(cad, nome), makeBUCKET_STR(), ltSTR);
}

void exampleQuick() {
  typedef struct Cadastro {
    char nome[10];
    int cpf;
    char end[10];
  } Cadastro;

  Cadastro cad[7] = {
      {.nome = "Iam", .cpf = 666, .end = "Ravara"},
      {.nome = "Gabriel", .cpf = 567, .end = "Coelho"},
      {.nome = "Samuel", .cpf = 294, .end = "Brum"},
      {.nome = "Gileade", .cpf = 361, .end = "Valente"},
      {.nome = "Inaue", .cpf = 879, .end = "NãoSei"},
      {.nome = "Marcos", .cpf = 193, .end = "NãoLembro"},
      {.nome = "Fernando", .cpf = 772, .end = "NãoLembro"},
  };

  quickSort(makeORDER(cad, cpf), ltINT);
}

#pragma endregion


// WARN: remnant code
#include <string.h>
#include <math.h>
double strToInt(void *value, int _) {
  int str_len = strlen(value);

  double res = 1 * pow(10, 3 * str_len);
  char *str = (char *)value;

  for (int i = 0; i < str_len; i++) {
    char curr = str[i];
    res += ((int)curr) * pow(10, 3 * i);
  }

  return res;
}
