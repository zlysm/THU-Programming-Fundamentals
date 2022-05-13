//
//Created by 张益铭 on 5/9/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>

class Rational {
public:
    int gcd(int num1, int num2);

    void add(const Rational &r1, const Rational &r2);

    void sub(const Rational &r1, const Rational &r2);

    void mul(const Rational &r1, const Rational &r2);

    void div(const Rational &r1, const Rational &r2);

    void printRational() const;

    void printReal() const;

    explicit Rational(int X = 0, int Y = 1);

    ~Rational();

private:
    int numerator;
    int denominator;
};

Rational::Rational(int X, int Y) {
    numerator = X / gcd(X, Y);
    denominator = Y / gcd(X, Y);
}

Rational::~Rational() {
    int flag = gcd(numerator, denominator);
    numerator /= flag;
    denominator /= flag;
}

inline int Rational::gcd(int num1, int num2) {  //找最大公约数
    if (num1 < num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    return num2 == 0 ? num1 : gcd(num2, num1 % num2);
}

void Rational::add(const Rational &r1, const Rational &r2) {
    numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    denominator = r1.denominator * r2.denominator;
}

void Rational::sub(const Rational &r1, const Rational &r2) {
    numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    denominator = r1.denominator * r2.denominator;
}

void Rational::mul(const Rational &r1, const Rational &r2) {
    numerator = r1.numerator * r2.numerator;
    denominator = r1.denominator * r2.denominator;
}

void Rational::div(const Rational &r1, const Rational &r2) {
    numerator = r1.numerator * r2.denominator;
    denominator = r1.denominator * r2.numerator;
}

void Rational::printRational() const {
    if (numerator % denominator == 0) {
        printf("%d", numerator / denominator);
    } else {
        printf("%d/%d", numerator, denominator);
    }
}

void Rational::printReal() const {
    printf("%.2f", (double) numerator / denominator);
}

int main() {
    int op, format;
    int numerator1, denominator1, numerator2, denominator2;
    bool isBigger = true;

    scanf("%d", &op);
    scanf("%d %d %d %d", &numerator1, &denominator1, &numerator2, &denominator2);
    scanf("%d", &format);

    Rational r1(numerator1, denominator1);
    Rational r2(numerator2, denominator2);
    Rational r;

    switch (op) {
        case 1:
            r.add(r1, r2);
            break;
        case 2:
            if ((numerator1 * denominator2 - numerator2 * denominator1) >= 0) {
                r.sub(r1, r2);
            } else {
                r.sub(r2, r1);
                isBigger = false;
            }
            break;
        case 3:
            r.mul(r1, r2);
            break;
        case 4:
            r.div(r1, r2);
            break;
        default:
            break;
    }

    if (!isBigger) printf("-");  //负数加负号
    switch (format) {
        case 1:
            r.printRational();
            break;
        case 2:
            r.printReal();
            break;
        default:
            break;
    }

    return 0;
}
