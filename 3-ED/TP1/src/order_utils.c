#include "../include/order.h"

bool eqANY(void *bin1, void *bin2, int byte_size) {
  return memcmp(bin1, bin2, byte_size) == 0;
}

bool ltBIN_STR(void *bin1, void *bin2) {
  // memLog(bin1);
  // memLog(bin2);
  return strcmp(bin1, bin2) < 0;
}
bool gtBIN_STR(void *bin1, void *bin2) {
  // memLog(bin1);
  // memLog(bin2);
  return strcmp(bin1, bin2) > 0;
}

bool eqINT(void *int1, void *int2) {
  // memLog(int1);
  // memLog(int2);
  return *(int *)int1 == *(int *)int2;
}
bool gtINT(void *int1, void *int2) {
  // memLog(int1);
  // memLog(int2);
  return *(int *)int1 > *(int *)int2;
}
bool ltINT(void *int1, void *int2) {
  // memLog(int1);
  // memLog(int2);
  return *(int *)int1 < *(int *)int2;
}

bool eqLNG(void *lng1, void *lng2) {
  // memLog(lng1);
  // memLog(lng2);
  return *(long *)lng1 == *(long *)lng2;
}
bool gtLNG(void *lng1, void *lng2) {
  // memLog(lng1);
  // memLog(lng2);
  return *(long *)lng1 > *(long *)lng2;
}
bool ltLNG(void *lng1, void *lng2) {
  // memLog(lng1);
  // memLog(lng2);
  return *(long *)lng1 < *(long *)lng2;
}

bool eqSTR(void *str1, void *str2) {
  // memLog(str1);
  // memLog(str2);
  return strcmp(str1, str2) == 0;
}

bool ltSTR(void *str1, void *str2) {
  // memLog(str1);
  // memLog(str2);
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

bool gtSTR(void *str1, void *str2) {
  // memLog(str1);
  // memLog(str2);
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

void *nthKEY(OrderStruct order, int n) {
  // memLog(order.data + (n * order.data_entry_size) + order.key_mem_offset);
  return order.data + (n * order.data_entry_size) + order.key_mem_offset;
}
void *nthENTRY(OrderStruct order, int n) {
  // memLog(order.data + (n * order.data_entry_size));
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

  memcpy(tmp, d, order.data_entry_size);
  memcpy(d, s, order.data_entry_size);
  memcpy(s, tmp, order.data_entry_size);

  free(tmp);
}

void swap_ptr(OrderStruct order, int dest, int source) {
  int dest_offset = dest * order.data_entry_size;
  int source_offset = source * order.data_entry_size;

  // either god doesn't exist os hes not good.
  // because if he was, he wouldn't allow this to exist
  void *tmp = (&order.data)[dest_offset];
  (&order.data)[dest_offset] = (&order.data)[source_offset];
  (&order.data)[source_offset] = tmp;
}

void prefixSTR(void *bucket, void *res) {
  // memLog(bucket);
  // memLog(res);
  sprintf(res, "%c", ((char *)bucket)[0]);
}

void prefixINT(void *bucket, void *res) {
  // memLog(bucket);
  // memLog(res);
  int number_int = *(int *)bucket;

  char number_str[8];
  sprintf(number_str, "%d", number_int);
  number_str[1] = '\0';

  number_int = strtol(number_str, NULL, 10);
  memcpy(res, &number_int, sizeof(int));
}

void prefixLNG(void *bucket, void *res) {
  // memLog(bucket);
  // memLog(res);
  long number_lng = *(long *)bucket;

  char number_str[19];
  sprintf(number_str, "%lu", number_lng);
  number_str[1] = '\0';

  number_lng = strtol(number_str, NULL, 10);
  memcpy(res, &number_lng, sizeof(long));
}
