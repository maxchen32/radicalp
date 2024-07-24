#include <iostream>
#include <sstream>
#include "Fraction.hpp"
using namespace std;

int main(int argc, char* argv[]){
    Fraction aaa = Fraction(2,3);
    Fraction bbb = Fraction(4,6);

    cout << aaa << " < " << bbb << ": " << (aaa < bbb) << endl;
    cout << aaa << " > " << bbb << ": " << (aaa > bbb) << endl;
    cout << aaa << " <= " << bbb << ": " << (aaa <= bbb) << endl;
    cout << aaa << " >= " << bbb << ": " << (aaa >= bbb) << endl;
    cout << aaa << " == " << bbb << ": " << (aaa == bbb) << endl;
    cout << "cmpFrac: " << Fraction::cmpFrac(aaa, bbb) << endl;

    cout << aaa << " *= " << bbb << ": ";
    aaa *= bbb;
    cout << aaa << endl;

    Fraction c = 4;
    cout << c << endl;
    c += -1.1;
    cout << c << endl;

    stringstream ss;
    ss << aaa << " " << bbb << " " << c;

    cout << ss.str() << endl;
    return 0;
}
