#define MAXTAM 5

#include <stdio.h>

typedef struct mat {
  double m[MAXTAM][MAXTAM];
  int tamx, tamy;
  int id;
} mat_tipo;

class Matrix {
public:
  static void criaMatriz(mat_tipo *mat, int tx, int ty, int id);
  static void inicializaMatrizNula(mat_tipo *mat);
  static void inicializaMatrizAleatoria(mat_tipo *mat);
  static double acessaMatriz(mat_tipo *mat);
  static void imprimeMatriz(mat_tipo *mat);
  static void salvaMatriz(mat_tipo *mat, FILE *out);
  static void escreveElemento(mat_tipo *mat, int x, int y, double v);
  static double leElemento(mat_tipo *mat, int x, int y);
  static void copiaMatriz(mat_tipo *src, mat_tipo *dst, int dst_id);
  static void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);
  static void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);
  static void transpoeMatriz(mat_tipo *a);
  static void destroiMatriz(mat_tipo *a);
};


