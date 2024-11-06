typedef struct opt {
  int num;
  char* alg;
  bool rec;
  bool debug;
} opt_t;

void parse_args(int argc, char **argv, opt_t *opt);
void uso();

extern char *algs[];
extern char *types[];
