#include "../include/cad.h"

char buf[2000];

char *toString(Cadastro cad) {
  sprintf(buf, "nome:%s,\tcpf:%lu,\tend:%s\tother:%s", cad.nome, cad.cpf,
          cad.end, cad.other);
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

void fromXCSV(xCSV *csv, int max_len, Cadastro *res) {
  char *curr_line;
  char *curr_token;
  for (int i = 0; i < csv->n_lines; i++) {

    // memLog(&res[i]);
    // memLog(csv->data[i]);
    // memLog(curr_line);
    // memLog(curr_token);

    curr_token = strtok_r(csv->data[i], ",", &curr_line);
    if (curr_token == NULL) {
      warnAssert(curr_line, "Couldn't read Name");
    }
    snprintf(res[i].nome, MAX_LEN, "%s", curr_token);

    curr_token = strtok_r(NULL, ",", &curr_line);
    if (curr_token != NULL && isdigit(*curr_token)) {
      res[i].cpf = strtol(curr_token, NULL, 10);
    } else {
      warnAssert(curr_line, "Couldn't read CPF");
      res[i].cpf = 0;
    }

    curr_token = strtok_r(NULL, ",", &curr_line);
    if (curr_token == NULL) {
      warnAssert(curr_line, "Couldn't read End");
    }
    snprintf(res[i].end, MAX_LEN, "%s", curr_token);

    curr_token = strtok_r(NULL, ",", &curr_line);
    if (curr_token == NULL) {
      warnAssert(curr_line, "Couldn't read Other");
    }
    snprintf(res[i].other, MAX_LEN, "%s", curr_token);
  }
}

void exemploCadastro() {
  typedef struct cad {
    char nome[300];
    int cpf;
    char end[500];
    char other[500];
  } cad;

  cad cads[6] = {
      {.nome = "Iam", .cpf = 666, .end = "Ravara"},
      {.nome = "Gabriel", .cpf = 567, .end = "Coelho"},
      {.nome = "Samuel", .cpf = 294, .end = "Brum"},
      {.nome = "Gileade", .cpf = 361, .end = "Valente"},
      {.nome = "Inaue", .cpf = 879, .end = "NaoSei"},
      {.nome = "Marcos", .cpf = 193, .end = "NaoLembro"},
  };

  for (int i = 0; i < 6; i++) {
    fprintf(stdout, "%s\t\t%d\n", cads[i].nome, cads[i].cpf);
  }

  fprintf(stdout, "\nSELECTION SORT BY name ASCENDING\n");
  selectionSort(makeORDER(cads, nome), ltSTR);

  fprintf(stdout, "\nBUCKET SORT BY cpf DESCENDING\n");
  bucketSort(makeORDER(cads, cpf), makePRFX_INT_DES());

  fprintf(stdout, "\nQUICK SORT BY name ASCENDING\n");
  quickSort(makeORDER(cads, nome), ltSTR);

  fprintf(stdout, "\nQUICK SORT IND BY name ASCENDING\n");
  quickSortInd(makeORDER(cads, nome), ltBIN_STR);

  fprintf(stdout, "\nRADIX SORT BY nome ASCENDING\n");
  radixSort(makeORDER(cads, nome), 's', true);

  for (int i = 0; i < 6; i++) {
    fprintf(stdout, "%s\t\t%d\n", cads[i].nome, cads[i].cpf);
  }
}
