#include "../include/cad.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char buf[211];

char *toString(Cadastro cad) {
  sprintf(buf, "nome:%s,\tcpf:%lu,\tend:%s", cad.nome, cad.cpf, cad.end);
  return buf;
}

bool eqCAD(Cadastro c1, Cadastro c2) {
  return strcmp(c1.nome, c2.nome) == 0 && c1.cpf == c2.cpf &&
         strcmp(c1.end, c2.end) == 0;
}

bool eqCAD_ARR(Cadastro *arr1, Cadastro *arr2, size_t len) {
  for (int i = 0; i < len; i++) {
    if (!eqCAD(arr1[i], arr2[i])) {
      return false;
    }
  }
  return true;
}

void fromXCSV(xCSV csv, Cadastro *res) {
  char *curr;
  for (int i = 0; i < csv.n_lines; i++) {
    curr = strsep(&csv.data[i], ",");
    sprintf(res[i].nome, "%s", curr);

    curr = strsep(&csv.data[i], ",");
    if (curr != NULL && isdigit(*curr)) {
      // safer than atoi
      res[i].cpf = strtol(curr, NULL, 10);
    } else {
      res[i].cpf = 0;
    }

    curr = strsep(&csv.data[i], ",");
    sprintf(res[i].end, "%s", curr);

    curr = strsep(&csv.data[i], ",");
    sprintf(res[i].other, "%s", curr);
  }
}

void exemploCadastro() {
  Cadastro cad[7] = {
      {.nome = "Iam", .cpf = 666, .end = "Ravara"},
      {.nome = "Gabriel", .cpf = 567, .end = "Coelho"},
      {.nome = "Samuel", .cpf = 294, .end = "Brum"},
      {.nome = "Gileade", .cpf = 361, .end = "Valente"},
      {.nome = "Inaue", .cpf = 879, .end = "NaoSei"},
      {.nome = "Marcos", .cpf = 193, .end = "NaoLembro"},
      {.nome = "Fernando", .cpf = 772, .end = "NaoLembro"},
  };

  for (int i = 0; i < 7; i++) {
    fprintf(stdout, "%s\n", toString(cad[i]));
  }

  // fprintf(stdout, "\nSELECTION SORT BY name ASCENDING\n");
  // selectionSort(makeORDER(cad, nome), ltSTR);

  // fprintf(stdout, "\nBUCKET SORT BY cpf DESCENDING\n");
  // bucketSort(makeORDER(cad, cpf), makePREFIXES_INT_ASC(), gtINT);

  // fprintf(stdout, "\nQUICK SORT BY name ASCENDING\n");
  // quickSort(makeORDER(cad, nome), ltSTR);

  fprintf(stdout, "\nQUICK SORT IND BY name ASCENDING\n");
  quickSortInd(makeORDER(cad, nome), ltSTR);

  // fprintf(stdout, "\nRADIX SORT BY nome ASCENDING\n");
  // radixSort(makeORDER(cad, nome), 's', true);

  for (int i = 0; i < 7; i++) {
    fprintf(stdout, "%s\n", toString(cad[i]));
  }
}
