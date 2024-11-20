typedef struct opt {
  char* file_path;
  char* alg;
  bool debug;
} opt_t;

void parse_args(int argc, char **argv, opt_t *opt);
void uso();
