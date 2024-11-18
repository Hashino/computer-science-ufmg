#ifndef MSGASSERTH
#define MSGASSERTH

#include <stdio.h>
#include <stdlib.h>

#define avisoAssert(e, msg)                                                    \
  ((void)((e) ? 0 : __avisoassert(#e, __FILE__, __LINE__, msg)))
#define __avisoassert(e, file, line, msg)                                      \
  ((void)fprintf(stderr, "%s:%u: Aviso: '%s' - %s\n", file, line, e, msg), 0)
#define erroAssert(e, msg)                                                     \
  ((void)((e) ? 0 : __erroassert(#e, __FILE__, __LINE__, msg)))
#define __erroassert(e, file, line, msg)                                       \
  ((void)fprintf(stderr, "%s:%u: Erro '%s' - %s\n", file, line, e, msg),       \
   abort(), 0)

#endif
