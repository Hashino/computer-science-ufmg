#include "../include/args.h"

void selectionSort(int arr[], int r, sortperf_t *s);
void insertionSort(int v[], int r, sortperf_t *s);
void partition3(int *A, int r, int *i, int *j, sortperf_t *s);
void quickSort(int *A, int r, sortperf_t *s);
void quickSort3(int *A, int r, sortperf_t *s);
void quickSortIns(int *A, int r, sortperf_t *s);
void quickSort3Ins(int *A, int r, sortperf_t *s);

int name2num(char *name);
char *num2name(int num);
void resetcounter(sortperf_t *s);
void inccmp(sortperf_t *s, int num);
void incmove(sortperf_t *s, int num);
void inccalls(sortperf_t *s, int num);
char *printsortperf(sortperf_t *s, char *str, char *pref);
void initVector(int *vet, int size);
void printVector(int *vet, int size);
void swap(int *xp, int *yp, sortperf_t *s);
void shellSort(int *A, int n, sortperf_t *s);
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t *s);
int median(int a, int b, int c);
