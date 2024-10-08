#include "vetor.h"
#include <iostream>

Vetor::Vetor(int inicio, int fim)
{
    if (inicio > fim)
    {
        throw IntervaloVazio{inicio, fim};
    }
    else
    {
        this->inicio_ = inicio;
        this->fim_ = fim;
        this->elementos_ = new string[fim - inicio + 1];
    }
}

void Vetor::atribuir(int i, string valor)
{
    if (i < this->inicio_ || i > this->fim_)
    {
        throw IndiceInvalido{this->inicio_, this->fim_, i};
    }
    else
    {
        this->elementos_[i - this->inicio_] = valor;
    }
}

string Vetor::valor(int i) const
{
    if (i < this->inicio_ || i > this->fim_)
    {
        throw IndiceInvalido{this->inicio_, this->fim_, i};
    }
    else
    {
        if (this->elementos_[i - this->inicio_] == "")
        {
            throw IndiceNaoInicializado{ i };
        }
        else
        {
            return this->elementos_[i - this->inicio_];
        }
    }
}

Vetor::~Vetor()
{
    delete[] this->elementos_;
}