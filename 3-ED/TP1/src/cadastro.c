#include "../include/cadastro.h"

char buf[2000];

char *toString(Cadastro cad) {
  sprintf(buf, "name:%s,\tcpf:%lu,\tend:%s\tother:%s", cad.name, cad.cpf,
          cad.address, cad.other);
  return buf;
}

bool eqCAD(Cadastro c1, Cadastro c2) {
  return strcmp(c1.name, c2.name) == 0 && c1.cpf == c2.cpf &&
         strcmp(c1.address, c2.address) == 0;
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
    snprintf(res[i].name, MAX_LEN, "%s", curr_token);

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
    snprintf(res[i].address, MAX_LEN, "%s", curr_token);

    curr_token = strtok_r(NULL, ",", &curr_line);
    if (curr_token == NULL) {
      warnAssert(curr_line, "Couldn't read Other");
    }
    snprintf(res[i].other, MAX_LEN, "%s", curr_token);
  }
}

void exemploCadastro() {
  typedef struct cad {
    char name[300];
    int cpf;
    char address[500];
    char other[500];
  } cad;

  cad cads[6] = {
      {.name = "Iam", .cpf = 666, .address = "Ravara"},
      {.name = "Gabriel", .cpf = 567, .address = "Coelho"},
      {.name = "Samuel", .cpf = 294, .address = "Brum"},
      {.name = "Gileade", .cpf = 361, .address = "Valente"},
      {.name = "Inaue", .cpf = 879, .address = "NaoSei"},
      {.name = "Marcos", .cpf = 193, .address = "NaoLembro"},
  };

  for (int i = 0; i < 6; i++) {
    fprintf(stdout, "%s\t\t%d\n", cads[i].name, cads[i].cpf);
  }

  fprintf(stdout, "\nSELECTION SORT BY name ASCENDING\n");
  selectionSort(makeORDER(cads, name), ltSTR);

  fprintf(stdout, "\nBUCKET SORT BY cpf DESCENDING\n");
  bucketSort(makeORDER(cads, cpf), makePRFX_INT_DES());

  fprintf(stdout, "\nQUICK SORT BY name ASCENDING\n");
  quickSort(makeORDER(cads, name), ltSTR);

  fprintf(stdout, "\nQUICK SORT IND BY name ASCENDING\n");
  quickSortInd(makeORDER(cads, name), ltBIN_STR);

  fprintf(stdout, "\nRADIX SORT BY name ASCENDING\n");
  radixSort(makeORDER(cads, name), 's', true);

  for (int i = 0; i < 6; i++) {
    fprintf(stdout, "%s\t\t%d\n", cads[i].name, cads[i].cpf);
  }
}
