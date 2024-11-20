#ifndef MSGASSERTH
#define MSGASSERTH

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define warnAssert(e, msg)                                                     \
  ((void)((e) ? __warnassert(#e, __FILE__, __LINE__, msg) : 0))
#define __warnassert(e, file, line, msg)                                       \
  ((void)fprintf(stderr, "%s%s:%u: Aviso: '%s' - %s%s\n", ANSI_COLOR_YELLOW,   \
                 file, line, e, msg, ANSI_COLOR_RESET),                        \
   0)
#define erroAssert(e, msg)                                                     \
  ((void)((e) ? __erroassert(#e, __FILE__, __LINE__, msg) : 0))
#define __erroassert(e, file, line, msg)                                       \
  ((void)fprintf(stderr, "%s%s:%u: Erro '%s' - %s%s\n", ANSI_COLOR_RED, file,  \
                 line, e, msg, ANSI_COLOR_RESET),                              \
   abort(), 0)

#endif
