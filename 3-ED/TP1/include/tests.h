#ifndef TESTSLIB
#define TESTSLIB

#include "../include/cadastro.h"
#include "../include/order.h"

#include <stdbool.h>
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define UNORDERED_DATA                                                         \
  {                                                                            \
      {.name = "Iam", .cpf = 666, .address = "Ravara"},                        \
      {.name = "Gabriel", .cpf = 567, .address = "Coelho"},                    \
      {.name = "Samuel", .cpf = 294, .address = "Brum"},                       \
      {.name = "Gileade", .cpf = 361, .address = "Valente"},                   \
      {.name = "Inaue", .cpf = 879, .address = "NaoSei"},                      \
      {.name = "Marcos", .cpf = 193, .address = "NaoLembro"},                  \
      {.name = "Fernando", .cpf = 772, .address = "NaoLembro"},                \
  }

#define ORDERED_name_ASC                                                       \
  (Cadastro[7]) {                                                              \
    {.name = "Fernando", .cpf = 772, .address = "NaoLembro"},                  \
        {.name = "Gabriel", .cpf = 567, .address = "Coelho"},                  \
        {.name = "Gileade", .cpf = 361, .address = "Valente"},                 \
        {.name = "Iam", .cpf = 666, .address = "Ravara"},                      \
        {.name = "Inaue", .cpf = 879, .address = "NaoSei"},                    \
        {.name = "Marcos", .cpf = 193, .address = "NaoLembro"},                \
        {.name = "Samuel", .cpf = 294, .address = "Brum"},                     \
  }

#define ORDERED_name_DES                                                       \
  (Cadastro[7]) {                                                              \
    {.name = "Samuel", .cpf = 294, .address = "Brum"},                         \
        {.name = "Marcos", .cpf = 193, .address = "NaoLembro"},                \
        {.name = "Inaue", .cpf = 879, .address = "NaoSei"},                    \
        {.name = "Iam", .cpf = 666, .address = "Ravara"},                      \
        {.name = "Gileade", .cpf = 361, .address = "Valente"},                 \
        {.name = "Gabriel", .cpf = 567, .address = "Coelho"},                  \
        {.name = "Fernando", .cpf = 772, .address = "NaoLembro"},              \
  }

#define ORDERED_CPF_ASC                                                        \
  (Cadastro[7]) {                                                              \
    {.name = "Marcos", .cpf = 193, .address = "NaoLembro"},                    \
        {.name = "Samuel", .cpf = 294, .address = "Brum"},                     \
        {.name = "Gileade", .cpf = 361, .address = "Valente"},                 \
        {.name = "Gabriel", .cpf = 567, .address = "Coelho"},                  \
        {.name = "Iam", .cpf = 666, .address = "Ravara"},                      \
        {.name = "Fernando", .cpf = 772, .address = "NaoLembro"},              \
        {.name = "Inaue", .cpf = 879, .address = "NaoSei"},                    \
  }

#define ORDERED_CPF_DES                                                        \
  (Cadastro[7]) {                                                              \
    {.name = "Inaue", .cpf = 879, .address = "NaoSei"},                        \
        {.name = "Fernando", .cpf = 772, .address = "NaoLembro"},              \
        {.name = "Iam", .cpf = 666, .address = "Ravara"},                      \
        {.name = "Gabriel", .cpf = 567, .address = "Coelho"},                  \
        {.name = "Gileade", .cpf = 361, .address = "Valente"},                 \
        {.name = "Samuel", .cpf = 294, .address = "Brum"},                     \
        {.name = "Marcos", .cpf = 193, .address = "NaoLembro"},                \
  }

void runTests();

#endif
