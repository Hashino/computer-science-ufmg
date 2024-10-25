#include "vetor.h"
#include <iostream>

Vetor::Vetor(int inicio, int fim)
{
    this->inicio_ = inicio;
    this->elementos_ = new string[fim - inicio + 1];
}

void Vetor::atribuir(int i, string valor)
{
    this->elementos_[i - this->inicio_] = valor;
}

string Vetor::valor(int i) const
{
    return this->elementos_[i - this->inicio_];
}

Vetor::~Vetor()
{
    delete[] this->elementos_;
}

