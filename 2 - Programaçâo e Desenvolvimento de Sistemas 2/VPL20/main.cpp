#include <iostream>

#include "racional.h"

using namespace std;

int main()
{
  try
  {
    Racional a;
    Racional b;
    cin >> a >> b;
    cout << static_cast<string>(a) << endl;
    cout << static_cast<string>(b) << endl;
    cout << static_cast<float>(a) << endl;
    cout << static_cast<float>(b) << endl;
    cout << -a << endl;
    cout << -b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
  }
  catch(Racional::ExcecaoDivisaoPorZero e)
  {
    cout << "erro (0)\n";
  }
  catch(...)
  {
    cout << "erro\n";
  }

  return 0;
}