#include <iostream>
#include "Fraction.hpp"
using namespace std;

int main(int argc, char* argv[]){
    Fraction aaa = Fraction(1,2);
    Fraction bbb = Fraction(1,3);
    Fraction ccc;
    ccc = aaa + bbb;
    cout << ccc;
    return 0;
}
