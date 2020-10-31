#include <iostream>
#include "Fraction.hpp"

inline int Fraction::serious_error() {
    std::cout << "Serious error: Maybe 0(zero) appered in denominators." << std::endl;
    exit(1);
}

Fraction::Fraction(int up, int down) {
    this->up = up;
    this->down = down;
    if (down != 0)
        this->reduceFrac();
}
Fraction::Fraction(){
    this->up = 0;
    this->down = 1;
}

int Fraction::gcd(int a, int b){
	if (0 == a || 0 == b){
		return 1;
	}
	int tmp;
	while ((tmp = a % b)){
		a = b;
		b = tmp;
	}
	return b > 0 ? b : -b;
}
long long Fraction::lgcd(long long a, long long b){
	if (0 == a || 0 == b){
		return 1;
	}
	long long tmp;
	while ((tmp = a % b)){
		a = b;
		b = tmp;
	}
	return b > 0 ? b : -b;
}
int Fraction::lcm(int a, int b){
	return a / gcd(a, b) * b ;
}
int Fraction::qpow(int base, int expt){
	int res = 1;
	while (expt){
		if (expt & 1)
			res *= base ;
		base *= base;
		expt >>= 1;
	}
	return res;
}

void Fraction::fixsignFrac(){
	if (0 == this->down){
		serious_error();
	}
	if (0 == this->up){
		this->down = 1;
		return;
	}
	if (this->down < 0){
		this->up = -(this->up);
		this->down = -(this->down);
		return;
	}
}
void Fraction::reduceFrac(){
	this->fixsignFrac();
	int gcdn = gcd(this->up, this->down);
	this->up /= gcdn;
	this->down /= gcdn;
}

Fraction Fraction::operator+(const Fraction &b){
    Fraction res;
    int lcmn = lcm(this->down, b.down);
	res.up = lcmn / this->down * this->up + lcmn / b.down * b.up;
	res.down = lcmn;
	res.reduceFrac();
	return res;
}
