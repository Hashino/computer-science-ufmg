#include <stdio.h>
#include <stdlib.h>

#include "../include/alg.h"

void resetcounter(sortperf_t *s) {
  // Descricao: inicializa estrutura
  // Entrada:
  // Saida: s
  s->cmp = 0;
  s->move = 0;
  s->calls = 0;
}

void inccmp(sortperf_t *s, int num) {
  // Descricao: incrementa o numero de comparacoes em num
  // Entrada: s, num
  // Saida: s
  s->cmp += num;
}

void incmove(sortperf_t *s, int num) {
  // Descricao: incrementa o numero de movimentacoes de dados em num
  // Entrada: s, num
  // Saida: s
  s->move += num;
}

void inccalls(sortperf_t *s, int num) {
  // Descricao: incrementa o numero de chamadas de função em num
  // Entrada: s, num
  // Saida: s
  s->calls += num;
}


void initVector(int *vet, int size) {
  // Descricao: inicializa vet com valores aleatorios
  // Entrada: vet
  // Saida: vet
  int i;
  // inicializa a parte alocada da vetor com valores aleatorios
  for (i = 0; i < size; i++) {
    vet[i] = (int)(drand48() * size);
  }
}

void printVector(int *vet, int size) {
  // Descricao: inicializa vet com valores aleatorios
  // Entrada: vet
  // Saida: vet
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
}

void swap(int *xp, int *yp, sortperf_t *s) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
  incmove(s, 3);
}

// shellsort
void shellSort(int *A, int n, sortperf_t *s) {}

// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s) {
  // find the minimum element in the unsorted subarray `[i…n-1]`
  // and swap it with `arr[i]`
  int min = l;
  inccalls(s, 1);
  for (int j = l + 1; j <= r; j++) {
    // if `arr[j]` is less, then it is the new minimum
    inccmp(s, 1);
    if (arr[j] < arr[min]) {
      min = j; // update the index of minimum element
    }
  }

  // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
  if (min != l)
    swap(&arr[min], &arr[l], s);

  if (l + 1 < r) {
    recursiveSelectionSort(arr, l + 1, r, s);
  }
}

// median of 3 integers
int median(int a, int b, int c) {
  if ((a <= b) && (b <= c))
    return b; // a b c
  if ((a <= c) && (c <= b))
    return c; // a c b
  if ((b <= a) && (a <= c))
    return a; // b a c
  if ((b <= c) && (c <= a))
    return c; // b c a
  if ((c <= a) && (a <= b))
    return a; // c a b
  return b;   // c b a
}
// selection sort
void selectionSort(int arr[], int len, sortperf_t *s) {
  for (int *curr = arr; curr < &arr[len]; curr++) {
    int *min = curr;
    for (int *rec_curr = curr + 1; rec_curr <= &arr[len]; rec_curr++) {
      s->cmp++;
      if (*rec_curr < *curr) {
        swap(rec_curr, curr, s);
        min = rec_curr;
      }
    }
  }
}

// insertion sort
void insertionSort(int arr[], int len, sortperf_t *s) {
  printVector(arr, len);
  for (int *curr = arr; curr <= &arr[len]; curr++) {
    for (int *rec_curr = curr; curr > arr; curr--) {
      if (*rec_curr > *(rec_curr - 1)) {
        swap(rec_curr, rec_curr - 1, s);
      }
    }
  }
  printVector(arr, len);
}

void insertionSort_(int arr[], int l, int r, sortperf_t *s) {
  for (int curr = r; curr > l; curr--) {
    if (arr[curr] < arr[curr - 1]) {
      swap(&arr[curr], &arr[curr - 1], s);
    }
  }
  for (int curr = l + 2; curr <= r; curr++) {
    int start = curr;
    int temp = arr[curr];
    while (temp < arr[start - 1]) {
      arr[start] = arr[start - 1];
      start--;
    }
    arr[start] = temp;
  }
}

// quicksort partition using median of 3
void partition3(int *A, int r, int *i, int *j, sortperf_t *s) {
  // TODO:
}

// standard quicksort partition
void partition(int *A, int r, int *i, int *j, sortperf_t *s) {
  // TODO:
}

// standard quicksort
void quickSort(int *A, int r, sortperf_t *s) {
  // TODO:
}

// quicksort with median of 3
void quickSort3(int *A, int r, sortperf_t *s) {
  // TODO:
}

// quicksort with insertion for small partitions
void quickSortIns(int *A, int r, sortperf_t *s) {
  // TODO:
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int *A, int r, sortperf_t *s) {
  // TODO:
}
