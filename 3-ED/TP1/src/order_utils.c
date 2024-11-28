#include "../include/order_utils.h"
#include "../include/stats.h"

void *nth_key(OrderStruct order, int n) {
  memLog(order.data + (n * order.data_entry_size) + order.key_mem_offset);
  return order.data + (n * order.data_entry_size) + order.key_mem_offset;
}

void *nth_entry(OrderStruct order, int n) {
  memLog(order.data + (n * order.data_entry_size));
  return order.data + (n * order.data_entry_size);
}

void *get_max(OrderStruct order, cmpFn cmp) {
  void *max = nth_key(order, 0);
  for (int i = 1; i < order.data_len; i++) {
    void *curr = nth_key(order, i);
    if (cmp(curr, max))
      max = curr;
  }
  return max;
}

void swap(OrderStruct order, int dest, int source) {
  void *tmp = malloc(order.data_entry_size);
  void *s = nth_entry(order, source);
  void *d = nth_entry(order, dest);

  memcpy(tmp, d, order.data_entry_size);
  memcpy(d, s, order.data_entry_size);
  memcpy(s, tmp, order.data_entry_size);

  free(tmp);
}

void swap_index(int data_index[], int dest, int source) {
  memLog(data_index);
  int tmp = data_index[dest];
  data_index[dest] = data_index[source];
  data_index[source] = tmp;
}

void reorder_index(OrderStruct order, int data_index[]) {
  int data_size = order.data_len * order.data_entry_size;
  void *tmp = malloc(data_size);
  memcpy(tmp, order.data, data_size);
  memLog(tmp);

  for (int i = 0; i < order.data_len; i++) {
    void *curr_tmp_entry = tmp + (data_index[i] * order.data_entry_size);
    memLog(curr_tmp_entry);
    memcpy(nth_entry(order, i), curr_tmp_entry, order.data_entry_size);
  }

  free(tmp);
}
