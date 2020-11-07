#include <iostream>
#include "Fraction.hpp"

inline int Fraction::serious_error() {
    std::cerr << "Serious error: Maybe 0(zero) appered in denominators." << std::endl;
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
Fraction::Fraction(const Fraction &b) {
    this->up = b.up;
    this->down = b.down;
}
void Fraction::reduce(int& a, int& b){
    int gcdn = gcd(a, b);
    a /= gcdn;
    b /= gcdn;
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
Fraction Fraction::operator+=(const Fraction &b){
    *this = *this + b;
    return *this;
}
Fraction Fraction::operator-(const Fraction &b){
	Fraction res = b;
	res.up = -res.up;
	return *this + res;
}
Fraction Fraction::operator*(const Fraction &b){
    Fraction res, tmp;
	int gcdn1 = gcd(this->up, b.down);
	int gcdn2 = gcd(this->down, b.up);
	res.up = this->up / gcdn1;
	tmp.down = b.down / gcdn1;
	res.down = this->down / gcdn2;
	tmp.up = b.up / gcdn2;
	res.up *= tmp.up;
	res.down *= tmp.down;
	res.fixsignFrac();
	return res;
}
Fraction Fraction::operator/(const Fraction &b){
    Fraction res = b;
	res.up ^= res.down ^= res.up ^= res.down;
	return *this * res;
}
Fraction Fraction::operator^(int expt){
    Fraction res;
	res.up = qpow(this->up, expt);
	res.down = qpow(this->down, expt);
	return res;
}

bool Fraction::operator<(const Fraction &nextFrac){
    Fraction a = *this;
    Fraction b = nextFrac;
    if ((a.up == b.up && a.down == b.down) || (a.up == 0 && b.up == 0))
		return false;
    else if (a.up < 0 && b.up > 0)
        return true;
    reduce(a.up, b.up);
    reduce(a.down, b.down);
    long long resup = a.up * b.down;
    long long resdown = a.down * b.up;
    if (resup < resdown)
        return true;
    return false;
}
bool Fraction::operator>(const Fraction &nextFrac){
    Fraction a = *this;
    Fraction b = nextFrac;
    if ((a.up == b.up && a.down == b.down) || (a.up == 0 && b.up == 0))
		return false;
    else if (a.up > 0 && b.up < 0)
        return true;
    reduce(a.up, b.up);
    reduce(a.down, b.down);
    long long resup = a.up * b.down;
    long long resdown = a.down * b.up;
    if (resup > resdown)
        return true;
    return false;
}
bool Fraction::operator==(const Fraction &b){
    Fraction a = *this;
    if ((a.up == b.up && a.down == b.down) || (a.up == 0 && b.up == 0))
		return true;
    return false;
}
bool Fraction::operator<=(const Fraction &b){
    Fraction a = *this;
    if (a < b || a == b)
        return true;
    else
        return false;
}
bool Fraction::operator>=(const Fraction &b){
    Fraction a = *this;
    if (a > b || a == b)
        return true;
    else
        return false;
}
