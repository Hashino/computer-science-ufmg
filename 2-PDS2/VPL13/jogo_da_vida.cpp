#include "jogo_da_vida.h"

#include <vector>
#include <iostream>

using namespace std;

JogoDaVida::JogoDaVida(int l, int c)
{
    for (int index_lin = 0; index_lin < l; index_lin++)
    {
        this->vivas_.push_back(vector<bool>(c, false));
    }
}

bool JogoDaVida::viva(int i, int j)
{
    return this->vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j)
{
    this->vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j)
{
    this->vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y)
{
    int n = 0;
    for (int index_lin = x - 1; index_lin <= x + 1; index_lin++)
    {
        for (int index_col = y - 1; index_col <= y + 1; index_col++)
        {
            int l = (index_lin + this->linhas()) % this->linhas();
            int c = (index_col + this->colunas()) % this->colunas();

            if (this->vivas_[l][c]) n++;
        }
    }
    return (this->vivas_[x][y]) ? n - 1 : n;
}

void JogoDaVida::ExecutarProximaIteracao()
{
    JogoDaVida copy = *this;
    for (int index_lin = 0; index_lin < this->vivas_.size(); index_lin++)
    {
        for (int index_col = 0; index_col < this->vivas_[index_lin].size(); index_col++)
        {
            int n_neighbors = copy.NumeroDeVizinhasVivas(index_lin, index_col);

            switch (n_neighbors)
            {
                case 2:
                    break;
                case 3:
                    this->Reviver(index_lin, index_col);
                    break;
                default:
                    this->Matar(index_lin, index_col);
                    break;
            }
        }
    }
}