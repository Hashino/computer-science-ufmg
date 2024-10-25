#include "racional.h"

#include <cmath>
#include <iostream>

Racional::Racional()
{
    this->numerador_ = 0;
    this->denominador_ = 1;
}

Racional::Racional(int n)
{
    this->numerador_ = n;
    this->denominador_ = 1;
}

Racional::Racional(int n, int d)
{
    this->numerador_ = n;
    this->denominador_ = d;
}

int Racional::numerador() const
{
    return this->numerador_;
}

int Racional::denominador() const
{
    return this->denominador_;
}

Racional Racional::simetrico() const
{
    Racional r(this->numerador_ * -1, this->denominador_);
    r.Normalizar();
    return r;
}

Racional Racional::somar(Racional k) const
{
    Racional soma;
    soma.denominador_ = this->denominador_ * k.denominador_;

    soma.numerador_ = ( ( soma.denominador_ / k.denominador_ ) * k.numerador_ ) + ( ( soma.denominador_ / this->denominador_ ) * this->numerador_ );

    soma.Normalizar();

    return soma;
}

Racional Racional::subtrair(Racional k) const
{
    Racional r = k.simetrico();
    r = this->somar(r);
    r.Normalizar();
    return r;
}

Racional Racional::multiplicar(Racional k) const
{
    Racional r(this->numerador_ * k.numerador_, this->denominador_ * k.denominador_);
    r.Normalizar();
    return r;
}

Racional Racional::dividir(Racional k) const
{
    Racional r(this->numerador_ * k.denominador_, this->denominador_ * k.numerador_);
    r.Normalizar();
    return r;
}

void Racional::Normalizar()
{
    if (denominador_ < 0)
    {
        Racional corretor(-1,-1);
        this->multiplicar(corretor);
    }

    int n1 = numerador_, n2 = denominador_,res = 0;

    do
    {
        res = n1 % n2;

        n1 = n2;
        n2 = res;
    }
    while (res != 0);

    this->numerador_ = this->numerador_/n1;
    this->denominador_ = this->denominador_/n1;
}