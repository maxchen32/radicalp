#ifndef _FRACTION_HPP
#define _FRACTION_HPP

class Fraction {
private:
	int up;
	int down;

	static void reduce(int& a, int& b);			  //数约分
	static int gcd(int a, int b);						//最大公因数
	// static long long gcd(long long a, long long b);
	static int lcm(int a, int b);						//最小公倍数
	static Fraction qpow(int base, int expt);				//快速幂

	void fixsignFrac();							//符号修正、错误处理
	void reduceFrac();							//分数约分
	static void error_print(const char* error_function, const char* error_content);

public:
	Fraction(int up, int down);
	Fraction(int up);
	Fraction();
	Fraction(const Fraction &b);
	~Fraction();

	static int cmpFrac(const Fraction &a, const Fraction &b);			 //比较 返回-1 , 0 , 1

	friend std::ostream& operator<<(std::ostream &out, const Fraction& a);
	Fraction& operator=(const Fraction &b) = default;
	Fraction operator+(const Fraction &b) const;	//加法
	Fraction operator+=(const Fraction &b);
	Fraction operator-(const Fraction &b) const;	//减法
	Fraction operator-=(const Fraction &b);
	Fraction operator*(const Fraction &b) const;	//乘法
	Fraction operator*=(const Fraction &b);
	Fraction operator/(const Fraction &b) const;	//除法
	Fraction operator/=(const Fraction &b);
	Fraction operator^(int expt) const;		//乘方
	Fraction operator^=(int expt);
//	Radical  sqrt();			   //开方
	bool operator<(const Fraction &a) const;
	bool operator>(const Fraction &a) const;
	bool operator==(const Fraction &b) const;
	bool operator<=(const Fraction &b) const;
	bool operator>=(const Fraction &b) const;
};


#endif
