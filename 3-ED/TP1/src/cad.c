#include "../include/cad.h"
#include "../include/order.h"
#include <stdio.h>
#include <string.h>

char buf[211];

char *toString(Cadastro cad) {
  sprintf(buf, "nome:%s,\tcpf:%d,\tend:%s", cad.nome, cad.cpf, cad.end);
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
  // bucketSort(makeORDER(cad, cpf), makeBUCKET_INT(), gtINT);

  // fprintf(stdout, "\nQUICK SORT BY name ASCENDING\n");
  // quickSort(makeORDER(cad, nome), ltSTR);

  // fprintf(stdout, "\nRADIX SORT BY cpf ASCENDING\n");
  // radixSort(makeORDER(cad, cpf), ltBIN);

  for (int i = 0; i < 7; i++) {
    fprintf(stdout, "%s\n", toString(cad[i]));
  }
}
