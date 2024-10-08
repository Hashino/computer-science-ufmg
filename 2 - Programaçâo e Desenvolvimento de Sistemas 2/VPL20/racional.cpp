#include "racional.h"

using namespace std;

/// @brief cria um racional 0/1
Racional::Racional()
{
    this->numerador_    = 0;
    this->denominador_  = 1;
}

/// @brief cria um numero racional no formato n/1
/// @param n
Racional::Racional(int n)
{
    this->numerador_    = n;
    this->denominador_  = 1;
}

/// @brief cria um numero racional simplificado
/// @param n numerador
/// @param d denominador
Racional::Racional(int n, int d)
{
    if (d == 0)
    {
        throw ExcecaoDivisaoPorZero{};
    }

    this->numerador_    = n;
    this->denominador_  = d;

    this->Simplificar();
}

int Racional::numerador() const
{
    return this->numerador_;
}

int Racional::denominador() const
{
    return this->denominador_;
}

Racional Racional::operator+(Racional k) const
{
    int denominator= this->denominador_ * k.denominador_;

    int numerator = ( denominator / k.denominador_ ) * k.numerador_ + ( denominator / this->denominador_ ) * this->numerador_;

    return Racional(numerator, denominator);
}

Racional Racional::operator-() const
{
    Racional simetrico;
    simetrico.numerador_ = this->numerador() * (-1);
    simetrico.denominador_ = this->denominador();

    return simetrico;
}

Racional Racional::operator-(Racional k) const
{
    return *this + (-k);
}

Racional Racional::operator*(Racional k) const
{
    return Racional(this->numerador_ * k.numerador_, this->denominador_ * k.denominador_);
}

Racional Racional::operator/(Racional k) const
{
    if (k.numerador() == 0)
    {
        throw ExcecaoDivisaoPorZero{};
    }

    return Racional (this->numerador_ * k.denominador_, this->denominador_ * k.numerador_);
}

Racional::operator float() const
{
    float r = (float)this->numerador() / (float)this->denominador();

    return (r == 0) ? 0 : r;
}

Racional::operator string() const
{
    return to_string(this->numerador()) + "/" + to_string(this->denominador());
}

ostream& operator<<(ostream& out, Racional r)
{
    return out << (string) r;
}

istream& operator>>(istream& in, Racional& r)
{
    int numerador = 0;
    int denominador = 0;

    in >> numerador >> denominador;

    r = Racional(numerador, denominador);
    return in;
}

void Racional::Simplificar()
{
    if( 0 > this->denominador_ )
    {
        this->numerador_ = -this->numerador();
        this->denominador_ = -this->denominador();
    }

    if (this->numerador() == 0)
    {
        *this = Racional();
        return;
    }

    int n1 = numerador_;
    int n2 = denominador_;
    int res = 0;

    do
    {
        res = n1 % n2;

        n1 = n2;
        n2 = res;
    }
    while (res != 0);

    numerador_=numerador_ / n1;
    denominador_=denominador_ / n1;
}