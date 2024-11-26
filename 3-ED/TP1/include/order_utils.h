#ifndef ORDER_UTILS
#define ORDER_UTILS
#include "order.h"

/// nth functions
void *nth_key(OrderStruct order, int n);
void *nth_entry(OrderStruct order, int n);

/** @brief returns the biggest (by cmp) key */
void *get_max(OrderStruct order, cmpFn cmp);

void swap(OrderStruct order, int dest, int source);
void swap_ptr(OrderStruct order, int dest, int source);
void swap_index(int data_index[], int dest, int source);

void reorder_index(OrderStruct order, int data_index[]);
#endif
