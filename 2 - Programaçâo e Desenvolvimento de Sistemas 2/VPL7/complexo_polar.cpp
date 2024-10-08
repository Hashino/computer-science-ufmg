// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>


Complexo::Complexo() {
real_ = 0;
imag_ = 0;
}

Complexo::Complexo(double a, double b)
{
    real_ = sqrt(pow(a, 2) + pow(b, 2));
    imag_ = atan(b / a);
}

double Complexo::real()
{
     double r = cos(imag_) * real_;
    return r;
}

double Complexo::imag()
{
    double r = sin(imag_) * real_;
    return r;
}

bool Complexo::igual(Complexo x)
{
    bool r = (x.real_ == real_) && (x.imag_ == imag_);
    return r;
}

void Complexo::Atribuir(Complexo x)
{
    real_ = x.real_;
    imag_ = x.imag_;
}

double Complexo::modulo()
{
    return real_;
}

Complexo Complexo::conjugado()
{
    Complexo c;
    c.real_ = real_;
    c.imag_ = -imag_;

    return c;
}

Complexo Complexo::simetrico()
{
    Complexo c;
    c.real_ = -real_;
    c.imag_ = imag_;
    return c;
}

Complexo Complexo::inverso()
{
    Complexo r;
    r.real_ = 1 / real_;
    r.imag_ = -imag_;

    return r;
}

Complexo Complexo::somar(Complexo y)
{
    double a = real() + y.real();
    double b = imag() + y.imag();
    return Complexo(a, b);
}

Complexo Complexo::subtrair(Complexo y)
{
    double a = real() - y.real();
    double b = imag() - y.imag();
    return Complexo(a, b);
}

Complexo Complexo::multiplicar(Complexo y)
{
    Complexo r;
    r.real_ = real_ * y.real_;
    r.imag_ = imag_ + y.imag_;

    return r;
}

Complexo Complexo::dividir(Complexo y)
{
    Complexo r;
    r.real_ = real_ / y.real_;
    r.imag_ = imag_ - y.imag_;

    return r;
}