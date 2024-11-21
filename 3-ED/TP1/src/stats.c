#include "../include/stats.h"

struct timespec clkDiff(struct timespec t1, struct timespec t2)
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
{
  struct timespec res;
  if (t2.tv_nsec < t1.tv_nsec) {
    // ajuste necessario, utilizando um segundo de tv_sec
    res.tv_nsec = 1000000000 + t2.tv_nsec - t1.tv_nsec;
    res.tv_sec = t2.tv_sec - t1.tv_sec - 1;
  } else {
    // nao e necessario ajuste
    res.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    res.tv_sec = t2.tv_sec - t1.tv_sec;
  }
  
  return res;
}
