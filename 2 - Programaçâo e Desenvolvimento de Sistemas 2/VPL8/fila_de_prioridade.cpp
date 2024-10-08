#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p)
{
  list<Pessoa>::iterator itn;

  for (itn=lista_.begin(); itn != lista_.end(); itn++)
  {
    if (itn->prioridade < p.prioridade)
    {
      break;
    }
  }
  lista_.insert(itn, p);
}

string FilaDePrioridade::RemoverMaiorPrioridade()
{
  string nome = this->lista_.front().nome;
  this->lista_.pop_front();
  return nome;
}

void FilaDePrioridade::Remover(string nome)
{
  for (list<Pessoa>::iterator itn = lista_.begin(); itn != lista_.end(); itn++)
  {
    if (itn->nome == nome)
    {
      this->lista_.erase(itn);
      break;
    }
  }
}

int FilaDePrioridade::tamanho()
{
  return this->lista_.size();
}

vector<string> FilaDePrioridade::listar()
{
  vector<string> r;

  for (Pessoa pessoa:this->lista_)
  {
    r.push_back(pessoa.nome);
  }

  return r;
}