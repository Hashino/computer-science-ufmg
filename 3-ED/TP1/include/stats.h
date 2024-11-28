#ifndef STATS
#define STATS
#include "../include/msg_assert.h"

#include <bits/time.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/resource.h>
#include <time.h>
#include <inttypes.h>

// initlize internal values
void startStats(char* path);

// call after initial setup is done
void timeInit();

// call after main loop ends
void timeEnd();

// call at end of execution to display times
void printStats();

// writes memory addres and relative time to file
void memLog(void* address);

#endif
