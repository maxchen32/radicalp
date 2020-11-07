#include <iostream>
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

    return 0;
}
