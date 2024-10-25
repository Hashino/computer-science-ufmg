
#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT 3
#define ALGQSORT3 4
#define ALGQSORTINS 5
#define ALGQSORT3INS 6
#define ALGSHELLSORT 7
#define ALGRECSEL 8

typedef struct sortperf {
  int cmp;
  int move;
  int calls;
} sortperf_t;

typedef struct alg {
  int num;
  char *name;
} alg_t;

typedef struct opt {
  int size;
  int seed;
  int alg;
} opt_t;

void parse_args(int argc, char **argv, opt_t *opt);
