#include "../include/order.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool eqANY(void *bin1, void *bin2, int byte_size) {
  return memcmp(bin1, bin2, byte_size) == 0;
}

/// binary functions
bool ltBIN_STR(void *bin1, void *bin2) { return strcmp(bin1, bin2) < 0; }
bool gtBIN_STR(void *bin1, void *bin2) { return strcmp(bin1, bin2) > 0; }
bool ltBIN_INT(void *bin1, void *bin2) {
  //
  return false;
}
bool gtBIN_INT(void *bin1, void *bin2) {
  //
  return false;
}

/* @return true if int1 > int2 (as integers) */
bool gtINT(void *int1, void *int2) { return *(int *)int1 > *(int *)int2; }
/* @return true if int1 < int2 (as integers) */
bool ltINT(void *int1, void *int2) { return *(int *)int1 < *(int *)int2; }
/* @return true if int1 == int2 (as integers) */
bool eqINT(void *int1, void *int2) { return *(int *)int1 == *(int *)int2; }

/* @return true if str1 == str2 (as char*) */
bool eqSTR(void *str1, void *str2) { return strcmp(str1, str2) == 0; }

/* @return true if str1 > str2 (as char* with internal lexographical order) */
bool gtSTR(void *str1, void *str2) {
  char *_str1 = (char *)str1;
  char *_str2 = (char *)str2;

  int common_size =
      (strlen(_str1) > strlen(_str2)) ? strlen(_str2) : strlen(_str1);

  for (int c = 0; c < common_size; c++) {
    if (_str1[c] > _str2[c]) {
      return true;
    } else if (_str1[c] < _str2[c]) {
      return false;
    }
  }

  return strlen(_str1) > strlen(_str2);
}

bool ltSTR(void *str1, void *str2) {
  char *_str1 = (char *)str1;
  char *_str2 = (char *)str2;

  int common_size =
      (strlen(_str1) > strlen(_str2)) ? strlen(_str2) : strlen(_str1);

  for (int c = 0; c < common_size; c++) {
    if (_str1[c] < _str2[c]) {
      return true;
    } else if (_str1[c] > _str2[c]) {
      return false;
    }
  }

  return strlen(_str1) < strlen(_str2);
}

/// nth functions
void *nthKEY(OrderStruct order, int n) {
  return order.data + (n * order.data_entry_size) + order.key_mem_offset;
}
void *nthENTRY(OrderStruct order, int n) {
  return order.data + (n * order.data_entry_size);
}

void *getMax(OrderStruct order, cmpFn cmp) {
  void *max = nthKEY(order, 0);
  for (int i = 1; i < order.data_len; i++) {
    void *curr = nthKEY(order, i);
    if (cmp(curr, max))
      max = curr;
  }
  return max;
}

void swap(OrderStruct order, int dest, int source) {
  void *tmp = malloc(order.data_entry_size);

  void *s = nthENTRY(order, source);
  void *d = nthENTRY(order, dest);

  // TODO: investigate safer way
  memcpy(tmp, d, order.data_entry_size);
  memcpy(d, s, order.data_entry_size);
  memcpy(s, tmp, order.data_entry_size);

  free(tmp);
}

void _selectionSort(OrderStruct order, cmpFn cmp) {
  for (int i = 0; i < order.data_len - 1; i++) {
    int min_idx = i;

    for (int j = i + 1; j < order.data_len; j++) {
      void *curr = nthKEY(order, j);
      void *min = nthKEY(order, min_idx);

      if (cmp(curr, min)) {
        min_idx = j;
      }
    }

    if (i != min_idx)
      swap(order, i, min_idx);
  }
}
void selectionSort(OrderStruct order, cmpFn cmp) {
  _selectionSort(order, cmp); //
}

void prefixSTR(void *bucket, void *res) {
  sprintf(res, "%c", ((char *)bucket)[0]);
}

void prefixINT(void *bucket, void *res) {
  char number_str[8];
  int number_int = *(int *)bucket;

  sprintf(number_str, "%d", number_int);
  number_str[1] = '\0';

  number_int = atoi(number_str);
  memcpy(res, &number_int, sizeof(int));
}

void _bucketSort(OrderStruct order, cmpFn eq, prefixFn prfx, void *prefixes,
                 int n_prefixes, int prefix_size, cmpFn cmp) {
  int *buckets = (int *)calloc(n_prefixes, sizeof(int));
  int *counts = (int *)calloc(n_prefixes, sizeof(int));

  void *curr_key_prefix = malloc(prefix_size);
  void *curr_bucket_prefix = malloc(prefix_size);

  // getting count of buckets
  // first iterates through keys
  for (int i = 0; i < order.data_len; i++) {
    prfx(nthKEY(order, i), curr_key_prefix);

    // for each key, iterates through buckets
    for (int j = 0; j < n_prefixes; j++) {
      // gets prefix of current bucket
      prfx(prefixes + (j * prefix_size), curr_bucket_prefix);

      // checks if bucket and key have same prefix
      if (eq(curr_key_prefix, curr_bucket_prefix)) {
        buckets[j]++;
        counts[j]++;

        break;
      }
    }
  }
  // reordering array into subarrays (buckets)
  int j = 0; // j is a variable which points at the index we are updating
  // first iterates through buckets
  for (int i = 0; j < order.data_len; i++) {
    // gets prefix of current bucket
    prfx(prefixes + (i * prefix_size), curr_bucket_prefix);

    // for each bucket, iterates through keys
    while (buckets[i] > 0) {
      for (int k = 0; buckets[i] > 0; k++) {
        // gets prefix of current key
        prfx(nthKEY(order, k), curr_key_prefix);

        // checks if bucket and key have same prefix
        if (eq(curr_bucket_prefix, curr_key_prefix)) {
          swap(order, j, k);

          j++;
          buckets[i]--;
        }
      }
    }
  }

  // ordering subarrays with selection sort (buckets)
  j = 0;
  // iterates through subarrays (buckets)
  for (int i = 0; j < order.data_len; i++) {
    if (counts[i]) {
      // sort each subarray (bucket) with selection sort
      selectionSort(order, cmp);
      j += counts[i];
    }
  }

  free(buckets);
  free(counts);
  free(curr_key_prefix);
  free(curr_bucket_prefix);
}

void bucketSort(OrderStruct order, cmpFn eq, prefixFn prfx, void *b_prefixes,
                int n_prefixes, int prefix_size, cmpFn cmp) {
  _bucketSort(order, eq, prfx, b_prefixes, n_prefixes, prefix_size, cmp);
}

int partition(OrderStruct order, cmpFn cmp, int left, int right) {
  void *pivot = nthKEY(order, right);
  int i = (left - 1);

  for (int j = left; j < right; j++) {
    void *curr_key = nthKEY(order, j);
    if (cmp(curr_key, pivot) || eqANY(curr_key, pivot, order.key_size)) {
      i++;
      swap(order, i, j);
    }
  }

  swap(order, i + 1, right);
  return (i + 1);
}

void _quickSort(OrderStruct order, cmpFn cmp, int left, int right) {
  if (left < right) {
    int part = partition(order, cmp, left, right);

    _quickSort(order, cmp, left, part - 1);
    _quickSort(order, cmp, part + 1, right);
  }
}

void quickSort(OrderStruct order, cmpFn cmp) {
  _quickSort(order, cmp, 0, order.data_len - 1);
}

void _radixPartialSort(OrderStruct order, cmpFn eq, prefixFn prfx,
                       void *prefixes, int n_prefixes, int prefix_size) {
  int *buckets = (int *)calloc(n_prefixes, sizeof(int));
  int *counts = (int *)calloc(n_prefixes, sizeof(int));

  void *curr_key_prefix = malloc(prefix_size);
  void *curr_bucket_prefix = malloc(prefix_size);

  // getting count of buckets
  // first iterates through keys
  for (int i = 0; i < order.data_len; i++) {
    prfx(nthKEY(order, i), curr_key_prefix);

    // for each key, iterates through buckets
    for (int j = 0; j < n_prefixes; j++) {
      // gets prefix of current bucket
      prfx(prefixes + (j * prefix_size), curr_bucket_prefix);

      // checks if bucket and key have same prefix
      if (eq(curr_key_prefix, curr_bucket_prefix)) {
        buckets[j]++;
        counts[j]++;

        break;
      }
    }
  }
  // reordering array into subarrays (buckets)
  int j = 0; // j is a variable which points at the index we are updating
  // first iterates through buckets
  for (int i = 0; j < order.data_len; i++) {
    // gets prefix of current bucket
    prfx(prefixes + (i * prefix_size), curr_bucket_prefix);

    // for each bucket, iterates through keys
    while (buckets[i] > 0) {
      for (int k = 0; buckets[i] > 0; k++) {
        // gets prefix of current key
        prfx(nthKEY(order, k), curr_key_prefix);

        // checks if bucket and key have same prefix
        if (eq(curr_bucket_prefix, curr_key_prefix)) {
          swap(order, j, k);

          j++;
          buckets[i]--;
        }
      }
    }
  }

  free(buckets);
  free(counts);
  free(curr_key_prefix);
  free(curr_bucket_prefix);
}

void radixSort(OrderStruct order, cmpFn eq, prefixFn prfx, void *b_prefixes,
               int n_prefixes, int prefix_size) {
  // for (int i = 0; i < order.data_len; i++) {
  //
  // }
  _radixPartialSort(order, eq, prfx, b_prefixes, n_prefixes, prefix_size);
}
