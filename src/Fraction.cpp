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
/** @warning Unlike the normal gcd function, \n
 *  this function never returns 0 and negative number. \n
 *	e.g. gcd(0,0) returns 1; \n
 *		 gcd(1,0) returns 1; \n
 *		 gcd(0,114514) returns 1.
 */
int Fraction::gcd(int a, int b){
	if (a && b) {
		while((a%=b) && (b%=a));
		return abs(a+b);
		} else {
		return 1;
	}
}
long long Fraction::gcd(long long a, long long b){
	if (a && b) {
		while((a%=b) && (b%=a));
		return abs(a+b);
		} else {
		return 1;
	}
}
int Fraction::lcm(int a, int b){
	return a / gcd(a, b) * b ;
}
Fraction Fraction::qpow(int base, int expt){
	if(base == 0)
		return Fraction(0, 1);
	int res = 1;
	bool flag = true;
	if (expt < 0) {
		expt = -expt;
		flag = false;
	}
	while (expt){
		if (expt & 1)
			res *= base ;
		base *= base;
		expt >>= 1;
	}
	return flag ? Fraction(res, 1) : Fraction(1, res);
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
	Fraction up = qpow(this->up, expt);
	Fraction down = qpow(this->down, expt);
	return up / down;
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
