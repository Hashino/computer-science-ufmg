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
  s->calls++;

  s->move += 3;
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s) {
  // find the minimum element in the unsorted subarray `[i…n-1]`
  // and swap it with `arr[i]`
  s->calls++;

  int min = l;
  s->calls++;
  for (int j = l + 1; j <= r; j++) {
    // if `arr[j]` is less, then it is the new minimum
    s->cmp++;
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

// insertion sort
void insertionSort(int arr[], int len, sortperf_t *s) {
  s->calls++;

  for (int *curr = &arr[0]; curr <= &arr[len]; curr++) {
    for (int *rec_curr = curr; rec_curr > &arr[0]; rec_curr--) {
      s->cmp++;
      if (*rec_curr < *(rec_curr - 1)) {
        swap(rec_curr, rec_curr - 1, s);
      }
    }
  }
}

// selection sort
void selectionSort(int arr[], int len, sortperf_t *s) {
  s->calls++;

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

// shellsort
void shellSort(int arr[], int len, sortperf_t *s) {
  s->calls++;

  for (int gap = len / 2; gap > 0; gap = gap / 2) {
    for (int curr1 = gap; curr1 < len; curr1 += 1) {
      int temp = arr[curr1];

      int curr2;
      for (curr2 = curr1; curr2 >= gap; curr2 -= gap) {
        s->cmp++;
        if (arr[curr2 - gap] > temp) {
          s->move++;
          arr[curr2] = arr[curr2 - gap];
        } else {
          break;
        }
      }

      s->move++;
      arr[curr2] = temp;
    }
  }
}

// standard quicksort partition
int partition(int arr[], int left, int right, sortperf_t *s) {
  s->calls++;
  int pivot = arr[right];

  int i = left - 1;

  for (int j = left; j < right; j++) {
    s->cmp++;
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j], s);
    }
  }

  swap(&arr[i + 1], &arr[right], s);
  return i + 1;
}

// standard quicksort
void quickSort(int *arr, int left, int right, sortperf_t *s) {
  s->calls++;
  if (left < right) {
    int pi = partition(arr, left, right, s);

    quickSort(arr, left, pi - 1, s);
    quickSort(arr, pi + 1, right, s);
  }
}

// median of 3 integers
int *median(int *a, int *b, int *c, sortperf_t *s) {
  s->calls++;
  if (s->cmp++ && (*a <= *b) && s->cmp++ && (*b <= *c))
    return b; // a b c
  if (s->cmp++ && (*a <= *c) && s->cmp++ && (*c <= *b))
    return c; // a c b
  if (s->cmp++ && (*b <= *a) && s->cmp++ && (*a <= *c))
    return a; // b a c
  if (s->cmp++ && (*b <= *c) && s->cmp++ && (*c <= *a))
    return c; // b c a
  if (s->cmp++ && (*c <= *a) && s->cmp++ && (*a <= *b))
    return a; // c a b
  return b;   // c b a
}

// quicksort partition using median of 3
int partition3(int arr[], int left, int right, sortperf_t *s) {
  s->calls++;
  int middle = left + ((right - left) / 2);

  swap(&arr[middle], median(&arr[left], &arr[middle], &arr[right], s), s);

  s->cmp++;
  if (arr[left] > arr[right]) {
    swap(&arr[left], &arr[right], s);
  }
  int *pivot = &arr[middle];

  int i = left - 1;
  int j = right + 1;

  while (1) {
    while (s->cmp++ && arr[++i] < *pivot) { }
    while (s->cmp++ && arr[--j] > *pivot) { }
    if (i >= j)
      return j + 1;
    swap(&arr[i], &arr[j], s);
  }
}

// quicksort with median of 3
void quickSort3(int *arr, int left, int right, sortperf_t *s) {
  s->calls++;
  if (left < right) {
    int pi = partition3(arr, left, right, s);

    quickSort3(arr, left, pi - 1, s);
    quickSort3(arr, pi, right, s);
  }
}

// quicksort with insertion for small partitions
void quickSortIns(int *arr, int left, int right, sortperf_t *s) {
  s->calls++;
  if (right - left > 10) {
    int pi = partition(arr, left, right, s);

    quickSort(arr, left, pi - 1, s);
    quickSort(arr, pi + 1, right, s);
  } else {
    insertionSort(arr + left, left + (right - left), s);
  }
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int *arr, int left, int right, sortperf_t *s) {
  s->calls++;
  if (right - left > 10) {
    int pi = partition3(arr, left, right, s);

    quickSort3Ins(arr, left, pi - 1, s);
    quickSort3Ins(arr, pi, right, s);
  } else {
    insertionSort(arr + left, left + (right - left), s);
  }
}
