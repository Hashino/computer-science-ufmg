#ifndef ORDER_CMPS
#define ORDER_CMPS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// INT
#define INT_PRFX_ASC (void *)(int[10]){0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
#define INT_PRFX_DES (void *)(int[10]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
#define INT_P_N_ENTRIES 10
#define INT_P_ENTRY_SIZE sizeof(int)

/// LONG
#define LNG_PRFX_ASC (void *)(long[10]){0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
#define LNG_PRFX_DES (void *)(long[10]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
#define LNG_P_N_ENTRIES 10
#define LNG_P_ENTRY_SIZE sizeof(long)

/// STRING
#define STR_PRFX_ASC                                                           \
  " !\"#$%&'()*+,-./"                                                          \
  "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`"                         \
  "abcdefghijklmnopqrstuvwxyz{|}~"
#define STR_PRFX_DES                                                           \
  "~}|{zyxwvutsrqponmlkjihgfedcba`_^]\\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:"     \
  "9876543210/.-,+*)('&%$#\"!"
#define STR_B_N_ENTRIES 128
#define STR_B_ENTRY_SIZE sizeof(char)

/** @brief returns true if any1 == any2 by memcmp */
bool eqANY(void *any1, void *any2, int byte_size);

/** @brief returns true if int1 == int2 */
bool eqINT(void *int1, void *int2);
/** @brief returns true if int1 > int2 */
bool gtINT(void *int1, void *int2);
/** @brief returns true if int1 < int2 */
bool ltINT(void *int1, void *int2);

/** @brief returns true if lng1 == lng2 */
bool eqLNG(void *lng1, void *lng2);
/** @brief returns true if lng1 > lng2 */
bool gtLNG(void *lng1, void *lng2);
/** @brief returns true if lng1 < lng2 */
bool ltLNG(void *lng1, void *lng2);

/** @brief returns true if str1 == str2 (by strcmp) */
bool eqSTR(void *str1, void *str2);
/** @brief returns true if str1 > str2 (by strlen) */
bool gtSTR(void *str1, void *str2);
/** @brief returns true if str1 < str2 (by strlen) */
bool ltSTR(void *str1, void *str2);

/** @brief uses strcmp to compare string */
bool ltBIN_STR(void *bin1, void *bin2);
/** @brief uses strcmp to compare string */
bool gtBIN_STR(void *bin1, void *bin2);

/** @brief res = first char of string */
void prefixSTR(void *bucket, void *res);
/** @brief res = first digit of integer */
void prefixINT(void *bucket, void *res);
/** @brief res = first digit of integer */
void prefixLNG(void *bucket, void *res);
#endif
