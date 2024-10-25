#include "fila.h";
#include <string>;

using std::string;

Fila::Fila()
{
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}

string Fila::primeiro()
{
    string chave = this->primeiro_->chave;
    return chave;
}

string Fila::ultimo()
{
    string chave = this->ultimo_->chave;
    return chave;
}

bool Fila::vazia()
{
    return (this->primeiro_ == nullptr) && (this->ultimo_ == nullptr);
}

void Fila::Inserir(string k)
{
    No* novo = new No;
    *novo = {k, nullptr};

    if(this->ultimo_ == nullptr)
    {
        this->primeiro_ = novo;
    }
    else
    {
        this->ultimo_->proximo = novo;
    }

    ultimo_ = novo;
}

void Fila::Remover()
{
    No* elemento = this->primeiro_;
    primeiro_ = elemento->proximo;

    if(this->ultimo_ == elemento)
    {
        ultimo_ = nullptr;
    }
}

int Fila::tamanho()
{
    int size = 0;

    if(this->primeiro_ != nullptr)
    {
        No* curr = this->primeiro_;

        while(curr != nullptr)
        {
            size++;
            curr = curr->proximo;
        }
    }

    return size;
}

Fila::~Fila()
{
    while(this->primeiro_ != nullptr)
    {
        this->Remover();
        delete this->primeiro_;
    }
}