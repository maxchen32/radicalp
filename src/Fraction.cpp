#include <iostream>
#include "Fraction.hpp"

void Fraction::error_print(const char* error_function, const char* error_content) {
	std::cerr << "Error: Fraction: " << error_function << ": " << error_content << std::endl;
}

Fraction::Fraction(int up, int down) {
	this->up = up;
	this->down = down;
	if (down != 0)
		this->reduceFrac();
}
Fraction::Fraction(int up) : up(up), down(1) {
}
Fraction::Fraction(){
	this->up = 0;
	this->down = 1;
}
Fraction::Fraction(const Fraction &b) {
	this->up = b.up;
	this->down = b.down;
}
Fraction::~Fraction() {};

std::ostream& operator<<(std::ostream &out, const Fraction& a) {
	out << a.up;
	if (a.down != 1) {
		out << "/" << a.down;
	}
	return out;
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
		int g = a+b;
		return g > 0 ? g : -g;
	} else {
		return 1;
	}
}
/*
long long Fraction::gcd(long long a, long long b){
	if (a && b) {
		while((a%=b) && (b%=a));
		int g = a+b;
		return g > 0 ? g : -g;
	} else {
		return 1;
	}
}
*/
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
		error_print("fixsignFrac", "Zero in denominators.");
		exit(EDOM);
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
	fixsignFrac();
	int gcdn = gcd(this->up, this->down);
	this->up /= gcdn;
	this->down /= gcdn;
}

Fraction Fraction::operator+(const Fraction &b) const {
	Fraction res;
	int lcmn = lcm(this->down, b.down);
	res.up = lcmn / this->down * this->up + lcmn / b.down * b.up;
	res.down = lcmn;
	res.reduceFrac();
	return res;
}
Fraction Fraction::operator+=(const Fraction &b) {
	*this = *this + b;
	return *this;
}
Fraction Fraction::operator-(const Fraction &b) const {
	Fraction res = b;
	res.up = -res.up;
	return *this + res;
}
Fraction Fraction::operator-=(const Fraction &b) {
	*this = *this - b;
	return *this;
}
Fraction Fraction::operator*(const Fraction &b) const {
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

Fraction Fraction::operator*=(const Fraction &b) {
	*this = *this * b;
	return *this;
}

Fraction Fraction::operator/(const Fraction &b) const {
	Fraction res = b;
	//res.up ^= res.down ^= res.up ^= res.down;
	int temp = res.up;
	res.up = res.down;
	res.down = temp;
	return *this * res;
}

Fraction Fraction::operator/=(const Fraction &b) {
	*this = *this / b;
	return *this;
}

Fraction Fraction::operator^(int expt) const {
	Fraction up = qpow(this->up, expt);
	Fraction down = qpow(this->down, expt);
	return up / down;
}

Fraction Fraction::operator^=(int expt) {
	*this = *this ^ expt;
	return *this;
}

int Fraction::cmpFrac(const Fraction &a, const Fraction &b) {
	if (!(a.down && b.down)){
		error_print("cmpFrac", "Zero in denominators.");
		exit(EDOM);
	}
	if ((a.up == b.up && a.down == b.down) || (a.up == 0 && b.up == 0))
		return 0;
	else if (a.up < 0 && b.up > 0)
		return -1;
	else if (a.up > 0 && b.up < 0)
		return 1;
	int gcdup = gcd(a.up, b.up);
	int gcddown = gcd(a.down, b.down);
	long long resup = a.up / gcdup * (b.down / gcddown);
	long long resdown = a.down / gcddown * (b.up / gcdup);
	if (resup < resdown)
		return -1;
	else if (resup > resdown)
		return 1;
	error_print("cmpFrac", "Unknown error.");
	exit(1);
}

bool Fraction::operator<(const Fraction &b) const {
	return cmpFrac(*this, b) < 0;
}
bool Fraction::operator>(const Fraction &b) const {
	return cmpFrac(*this, b) > 0;
}
bool Fraction::operator==(const Fraction &b) const {
	return cmpFrac(*this, b) == 0;
}
bool Fraction::operator<=(const Fraction &b) const {
	return cmpFrac(*this, b) <= 0;
}
bool Fraction::operator>=(const Fraction &b) const {
	return cmpFrac(*this, b) >= 0;
}

