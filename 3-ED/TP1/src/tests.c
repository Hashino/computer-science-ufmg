#include "../include/tests.h"

int n_tests_made = 0;
int n_tests_passed = 0;

void printResult(char *test_name, bool result) {
  if (!result) {
    char *res_color = result ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;
    char *res_symbol = result ? "o" : "x";
    char *res_end = ANSI_COLOR_RESET;

    fprintf(stdout, "[%s%s%s] %s%s%s\n", res_color, res_symbol, res_end,
            res_color, test_name, res_end);
  } else {
    n_tests_passed++;
  }
}

void testSelectionSort() {
  Cadastro data[7] = UNORDERED_DATA;
  bool res = false;

  selectionSort(makeORDER(data, nome), ltSTR);
  res = eqCAD_ARR(data, ORDERED_NOME_ASC, 7);
  printResult("selectionSort\tby Name\tAscending", res);
  n_tests_made++;

  selectionSort(makeORDER(data, nome), gtSTR);
  res = eqCAD_ARR(data, ORDERED_NOME_DES, 7);
  printResult("selectionSort\tby Name\tDescending", res);
  n_tests_made++;

  selectionSort(makeORDER(data, cpf), ltINT);
  res = eqCAD_ARR(data, ORDERED_CPF_ASC, 7);
  printResult("selectionSort\tby CPF\tAscending", res);
  n_tests_made++;

  selectionSort(makeORDER(data, cpf), gtINT);
  res = eqCAD_ARR(data, ORDERED_CPF_DES, 7);
  printResult("selectionSort\tby CPF\tDescending", res);
  n_tests_made++;
}

void testQuickSort() {
  Cadastro data[7] = UNORDERED_DATA;
  bool res = false;

  quickSort(makeORDER(data, nome), ltSTR);
  res = eqCAD_ARR(data, ORDERED_NOME_ASC, 7);
  printResult("quickSort\t\tby Name\tAscending", res);
  n_tests_made++;

  quickSort(makeORDER(data, nome), gtSTR);
  res = eqCAD_ARR(data, ORDERED_NOME_DES, 7);
  printResult("quickSort\t\tby Name\tDescending", res);
  n_tests_made++;

  quickSort(makeORDER(data, cpf), ltINT);
  res = eqCAD_ARR(data, ORDERED_CPF_ASC, 7);
  printResult("quickSort\t\tby CPF\tAscending", res);
  n_tests_made++;

  quickSort(makeORDER(data, cpf), gtINT);
  res = eqCAD_ARR(data, ORDERED_CPF_DES, 7);
  printResult("quickSort\t\tby CPF\tDescending", res);
  n_tests_made++;
}

void testQuickSortInd() {
  Cadastro data[7] = UNORDERED_DATA;
  bool res = false;

  quickSortInd(makeORDER(data, nome), ltSTR);
  res = eqCAD_ARR(data, ORDERED_NOME_ASC, 7);
  printResult("quickSortInd\tby Name\tAscending", res);
  n_tests_made++;

  quickSortInd(makeORDER(data, nome), gtSTR);
  res = eqCAD_ARR(data, ORDERED_NOME_DES, 7);
  printResult("quickSortInd\tby Name\tDescending", res);
  n_tests_made++;

  quickSortInd(makeORDER(data, cpf), ltINT);
  res = eqCAD_ARR(data, ORDERED_CPF_ASC, 7);
  printResult("quickSortInd\tby CPF\tAscending", res);
  n_tests_made++;

  quickSortInd(makeORDER(data, cpf), gtINT);
  res = eqCAD_ARR(data, ORDERED_CPF_DES, 7);
  printResult("quickSortInd\tby CPF\tDescending", res);
  n_tests_made++;
}

void testBucketSort() {
  Cadastro data[7] = UNORDERED_DATA;
  bool res = false;

  bucketSort(makeORDER(data, nome), makePRFX_STR_ASC());
  res = eqCAD_ARR(data, ORDERED_NOME_ASC, 7);
  printResult("bucketSort\t\tby Name\tAscending", res);
  n_tests_made++;

  bucketSort(makeORDER(data, nome), makePRFX_STR_DES());
  res = eqCAD_ARR(data, ORDERED_NOME_DES, 7);
  printResult("bucketSort\t\tby Name\tDescending", res);
  n_tests_made++;

  bucketSort(makeORDER(data, cpf), makePRFX_INT_ASC());
  res = eqCAD_ARR(data, ORDERED_CPF_ASC, 7);
  printResult("bucketSort\t\tby CPF\tAscending", res);
  n_tests_made++;

  bucketSort(makeORDER(data, cpf), makePRFX_INT_DES());
  res = eqCAD_ARR(data, ORDERED_CPF_DES, 7);
  printResult("bucketSort\t\tby CPF\tDescending", res);
  n_tests_made++;
}

void testRadixSort() {

  Cadastro data[7] = UNORDERED_DATA;
  bool res = false;

  radixSort(makeORDER(data, nome), 's', true);
  res = eqCAD_ARR(data, ORDERED_NOME_ASC, 7);
  printResult("radixSort\t\tby Name\tAscending", res);
  n_tests_made++;

  radixSort(makeORDER(data, nome), 's', false);
  res = eqCAD_ARR(data, ORDERED_NOME_DES, 7);
  printResult("radixSort\t\tby Name\tDescending", res);
  n_tests_made++;

  radixSort(makeORDER(data, cpf), 'i', true);
  res = eqCAD_ARR(data, ORDERED_CPF_ASC, 7);
  printResult("radixSort\t\tby CPF\tAscending", res);
  n_tests_made++;

  radixSort(makeORDER(data, cpf), 'i', false);
  res = eqCAD_ARR(data, ORDERED_CPF_DES, 7);
  printResult("radixSort\t\tby CPF\tDescending", res);
  n_tests_made++;
}

void printResultsTotal() {
  char total_results[100];
  sprintf(total_results, "[%d/%d] TESTS PASSED", n_tests_passed, n_tests_made);

  bool result = (n_tests_made == n_tests_passed);

  char *res_color = result ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;
  char *res_end = ANSI_COLOR_RESET;

  if (!result) {
    fprintf(stdout, "-------------------------------------------\n");
  }

  fprintf(stdout, "[%s%d/%d%s] %sTESTS_PASSED%s\n", res_color, n_tests_passed,
          n_tests_made, res_end, res_color, res_end);
}

void runTests() {
  fprintf(stdout, "-------------------------------------------\n");
  testSelectionSort();
  testQuickSort();
  testQuickSortInd();
  testBucketSort();
  testRadixSort();

  printResultsTotal();
  fprintf(stdout, "-------------------------------------------\n");
}
