// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo()
{
    this->imag_ = 0;
    this->real_ = 0;
}

// Cria o número complexo a + bi.
Complexo::Complexo(double a, double b)
{
    this->real_ = a;
    this->imag_ = b;
}

double Complexo::imag()
{
    return this->imag_;
}

double Complexo::real()
{
    return this->real_;
}

bool Complexo::igual(Complexo x)
{
    return this->imag() == x.imag() && this->real() == x.real();
}

void Complexo::Atribuir(Complexo x)
{
    this->imag_ = x.imag();
    this->real_ = x.real();
}

double Complexo::modulo()
{
    return sqrt(pow(this->imag() + this->real(), 2));
}

Complexo Complexo::conjugado()
{
    return Complexo(this->real(), this->imag() * -1);
}

Complexo Complexo::simetrico()
{
    return Complexo(this->real() * -1, this->imag() * -1);
}

Complexo Complexo::inverso()
{
    return Complexo(1, 0).dividir(*this);
}

Complexo Complexo::somar(Complexo y)
{
    return Complexo(this->real() + y.real(), this->imag() + y.imag());
}

Complexo Complexo::subtrair(Complexo y)
{
    return Complexo(this->real() - y.real(), this->imag() - y.imag());
}

Complexo Complexo::multiplicar(Complexo y)
{
    return Complexo(this->real() * y.real(), this->imag() * y.imag());
}

Complexo Complexo::dividir(Complexo y)
{
    return Complexo(this->real() / y.real(), this->imag() / y.imag());
}
