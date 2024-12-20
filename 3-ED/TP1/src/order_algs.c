#include "../include/order.h"
#include "../include/order_utils.h"

// standar selection sort implementation with comparison changed to
// use function passed as argument instead
void _selectionSort(OrderStruct order, cmpFn cmp) {
  for (int i = 0; i < order.data_len - 1; i++) {
    int min_idx = i;

    for (int j = i + 1; j < order.data_len; j++) {
      void *curr = nth_key(order, j);
      void *min = nth_key(order, min_idx);

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

// standar selection sort implementation with comparison changed to
// use function passed as argument instead
void _selectionSortInd(OrderStruct order, int data_index[], cmpFn cmp) {
  for (int i = 0; i < order.data_len - 1; i++) {
    int min_idx = i;

    for (int j = i + 1; j < order.data_len; j++) {
      void *curr = nth_key(order, data_index[j]);
      void *min = nth_key(order, data_index[min_idx]);

      if (cmp(curr, min)) {
        min_idx = j;
      }
    }

    if (i != min_idx)
      swap_index(data_index, i, min_idx);
    // swap(order, i, min_idx);
  }
}
void selectionSortInd(OrderStruct order, cmpFn cmp) {
  makeDATA_INDEX(order);

  _selectionSortInd(order, data_index, cmp);

  reorder_index(order, data_index);
}

int partition(OrderStruct order, cmpFn cmp, int left, int right) {
  // starts with pivot on the last entry
  void *pivot = nth_key(order, right);
  int i = (left - 1);

  for (int j = left; j < right; j++) {
    // iterates entries and compares keys
    void *curr_key = nth_key(order, j);
    if (cmp(curr_key, pivot) || eqANY(curr_key, pivot, order.key_size)) {
      // finds correct place of pivot
      i++;
      swap(order, i, j);
    }
  }

  // puts pivot in correct place
  swap(order, i + 1, right);
  return (i + 1);
}

void _quickSort(OrderStruct order, cmpFn cmp, int left, int right) {
  // recusively splits data in partitions
  if (left < right) {
    int part = partition(order, cmp, left, right);

    _quickSort(order, cmp, left, part - 1);
    _quickSort(order, cmp, part + 1, right);
  }
}

void quickSort(OrderStruct order, cmpFn cmp) {
  _quickSort(order, cmp, 0, order.data_len - 1);
}

int partitionInd(OrderStruct order, int data_index[], cmpFn cmp, int left,
                 int right) {
  // starts with pivot on the last entry
  void *pivot = nth_key(order, data_index[right]);
  int i = (left - 1);

  for (int j = left; j < right; j++) {
    // iterates entries and compares keys
    void *curr_key = nth_key(order, data_index[j]);

    if (cmp(curr_key, pivot) || eqANY(curr_key, pivot, order.key_size)) {
      // finds correct place of pivot
      i++;
      swap_index(data_index, i, j);
      // swap(order, data_index[i], data_index[j]);
    }
  }

  // puts pivot in correct place
  swap_index(data_index, i + 1, right);
  // swap(order, data_index[i + 1], data_index[right]);
  return (i + 1);
}

void _quickSortInd(OrderStruct order, int data_index[], cmpFn cmp, int left,
                   int right) {
  // recusively splits data in partitions
  if (left < right) {
    int part = partitionInd(order, data_index, cmp, left, right);

    _quickSortInd(order, data_index, cmp, left, part - 1);
    _quickSortInd(order, data_index, cmp, part + 1, right);
  }
}

void quickSortInd(OrderStruct order, cmpFn cmp) {
  makeDATA_INDEX(order);

  _quickSortInd(order, data_index, cmp, 0, order.data_len - 1);

  reorder_index(order, data_index);
}

void _bucketSort(OrderStruct order, cmpFn eq, prefixFn prfx, void *prefixes,
                 int n_prefixes, int prefix_size, cmpFn cmp) {
  int *buckets = (int *)calloc(n_prefixes, sizeof(int));
  int *counts = (int *)calloc(n_prefixes, sizeof(int));

  void *curr_key_prefix = malloc(prefix_size + 1);
  void *curr_bucket_prefix = malloc(prefix_size + 1);

  // getting count of buckets
  // first iterates through keys
  for (int i = 0; i < order.data_len; i++) {
    prfx(nth_key(order, i), curr_key_prefix);

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
        prfx(nth_key(order, k), curr_key_prefix);

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

void _radixSortInt(OrderStruct order, cmpFn cmp, bool asc) {
  void *output = malloc(order.data_len * order.data_entry_size);

  // Get maximum element
  int maxElement = *(int *)get_max(order, cmp);

  // Apply counting sort to sort elements based on place value
  // INFO: place must match number memory size
  for (int place = 1; maxElement / place > 0; place *= 10) {
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < order.data_len; i++) {
      int curr_key = *(int *)nth_key(order, i);
      int index = (curr_key / place) % 10;
      count[index]++;
    }

    // change count[i] so that count[i] now contains actual position of this
    // digit in output[]
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    // build the output array
    for (int i = order.data_len - 1; i >= 0; i--) {
      int curr_key = *(int *)nth_key(order, i);
      int index = (curr_key / place) % 10;

      int target = (count[index] - 1) * order.data_entry_size;

      memcpy(output + target, nth_entry(order, i), order.data_entry_size);

      count[index]--;
    }

    // copies output back to data
    for (int i = 0; i < order.data_len; i++) {
      // decides if ascending or descending
      int target = asc ? i : order.data_len - 1 - i;
      memcpy(nth_entry(order, target), output + (i * order.data_entry_size),
             order.data_entry_size);
    }
  }
  free(output);
}

void _radixSortLng(OrderStruct order, cmpFn cmp, bool asc) {
  void *output = malloc(order.data_len * order.data_entry_size);

  // Get maximum element
  long maxElement = *(long *)get_max(order, cmp);

  // Apply counting sort to sort elements based on place value
  // INFO: place must match number memory size
  for (long place = 1; maxElement / place > 0; place *= 10) {
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < order.data_len; i++) {
      long curr_key = *(long *)nth_key(order, i);
      int index = (curr_key / place) % 10;
      count[index]++;
    }

    // change count[i] so that count[i] now contains actual position of this
    // digit in output[]
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    // build the output array
    for (int i = order.data_len - 1; i >= 0; i--) {
      long curr_key = *(long *)nth_key(order, i);
      int index = (curr_key / place) % 10;

      int target = (count[index] - 1) * order.data_entry_size;

      memcpy(output + target, nth_entry(order, i), order.data_entry_size);

      count[index]--;
    }

    // copies output back to data
    for (int i = 0; i < order.data_len; i++) {
      // decides if ascending or descending
      int target = asc ? i : order.data_len - 1 - i;
      memcpy(nth_entry(order, target), output + (i * order.data_entry_size),
             order.data_entry_size);
    }
  }
  free(output);
}

void radixSort(OrderStruct order, char type, bool asc) {
  switch (type) {
  case 'i': // integer (8bits)
    _radixSortInt(order, gtINT, asc);
    break;
  case 'l': // long (64bits)
    _radixSortLng(order, gtLNG, asc);
    break;
  case 's': // string (char*)
    if (asc) {
      quickSort(order, ltBIN_STR);
    } else {
      quickSort(order, gtBIN_STR);
    }
    break;
  default:
    break;
  }
}
