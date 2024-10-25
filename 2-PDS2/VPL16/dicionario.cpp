#include "dicionario.h"

Dicionario::Dicionario()
{
    this->elementos_ = list<Elemento>();
}

int Dicionario::tamanho()
{
    return this->elementos_.size();
}

bool Dicionario::pertence(string chave)
{
    for (auto elemento:this->elementos_)
    {
        if(elemento.chave == chave)
        {
            return true;
        }
    }
    return false;
}

string Dicionario::menor()
{
    Elemento menor = *this->elementos_.begin();

    for (Elemento elemento:this->elementos_)
    {
        if (elemento.chave < menor.chave)
        {
            menor = elemento;
        }
    }
    return menor.valor;
}

string Dicionario::valor(string chave)
{
    for (Elemento elemento:this->elementos_)
    {
        if (elemento.chave == chave)
        {
            return elemento.valor;
        }
    }
    return "";
}

void Dicionario::Inserir(string chave, string valor)
{
    this->elementos_.push_back(Elemento {chave, valor});
}

void Dicionario::Remover(string chave)
{
    for (auto itr = this->elementos_.begin(); itr != this->elementos_.end(); itr++)
    {
        if (itr->chave == chave)
        {
            this->elementos_.erase(itr);
        }
    }
}

void Dicionario::Alterar(string chave, string valor)
{
    for (auto itr = this->elementos_.begin(); itr != this->elementos_.end(); itr++)
    {
        if (itr->chave == chave)
        {
            (*itr).valor = valor;
        }
    }
}

Dicionario::~Dicionario()
{
    delete[] &this->elementos_;
}