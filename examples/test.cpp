#include <iostream>
#include "Fraction.hpp"

using namespace std;

int main() {
  Fraction a, b;
  a = Fraction(1, 2);
  b = Fraction(1, 3);
  cout << a * b << endl;
  return 0;
}