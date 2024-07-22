#ifndef _FRACTION_HPP
#define _FRACTION_HPP

#include <iostream>

class Fraction {
protected:
    int up;
    int down;

    void reduce(int& a, int& b);              //数约分
    int gcd(int a, int b);						//最大公因数
    long long gcd(long long a, long long b);
    int lcm(int a, int b);						//最小公倍数
    Fraction qpow(int base, int expt);				//快速幂
    void fixsignFrac();				            //符号修正、错误处理
    void reduceFrac();				            //分数约分
    int cmpFrac(const Fraction &b);             //比较 返回-1 , 0 , 1
    inline int serious_error();

public:
    Fraction(int up, int down);
    Fraction();
    Fraction(const Fraction &b);
 //   virtual ~Fraction ();

    friend std::ostream& operator<<(std::ostream &out, const Fraction& res){
        out << "(" << res.up << "/" << res.down << ")";
        return out;
    }
    Fraction operator+(const Fraction &b);	//加法
    Fraction operator+=(const Fraction &b);
    Fraction operator-(const Fraction &b);	//减法
    Fraction operator*(const Fraction &b);	//乘法
    Fraction operator/(const Fraction &b);	//除法
    Fraction operator^(int expt);		//乘方
//    Radical  sqrt();               //开方
    bool operator<(const Fraction &nextFrac);
    bool operator>(const Fraction &nextFrac);
    bool operator==(const Fraction &b);
    bool operator<=(const Fraction &b);
    bool operator>=(const Fraction &b);
};


#endif
