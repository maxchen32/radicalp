#ifndef _FRACTION_HPP
#define _FRACTION_HPP

#include <iostream>

class Fraction {
protected:
    int up;
    int down;

    void reduce(int& a, int& b);              //��Լ��
    int gcd(int a, int b);						//�������
    long long gcd(long long a, long long b);
    int lcm(int a, int b);						//��С������
    Fraction qpow(int base, int expt);				//������
    void fixsignFrac();				            //����������������
    void reduceFrac();				            //����Լ��
    int cmpFrac(const Fraction &b);             //�Ƚ� ����-1 , 0 , 1
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
    Fraction operator+(const Fraction &b);	//�ӷ�
    Fraction operator+=(const Fraction &b);
    Fraction operator-(const Fraction &b);	//����
    Fraction operator*(const Fraction &b);	//�˷�
    Fraction operator/(const Fraction &b);	//����
    Fraction operator^(int expt);		//�˷�
//    Radical  sqrt();               //����
    bool operator<(const Fraction &nextFrac);
    bool operator>(const Fraction &nextFrac);
    bool operator==(const Fraction &b);
    bool operator<=(const Fraction &b);
    bool operator>=(const Fraction &b);
};


#endif
