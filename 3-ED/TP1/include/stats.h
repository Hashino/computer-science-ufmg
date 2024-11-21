#ifndef STATS
#define STATS
#include "../include/msg_assert.h"

#include <bits/time.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/resource.h>
#include <time.h>
#include <inttypes.h>

void startStats();

void timeInit();

void timeEnd();

void printStats();

void memLog(void* address);

#endif
