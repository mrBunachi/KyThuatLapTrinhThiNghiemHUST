/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>

using namespace std;

/// Tao cau truc complex
struct Complex {
    double real;
    double imag;
};

/// Dinh nghia toan tu +
Complex operator + (Complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

/// Dinh nghia toan tu -
Complex operator - (Complex a, Complex b) {
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

/// Dinh nghia toan tu *
Complex operator * (Complex a, Complex b) {
    Complex c;
    c.real = a.real*b.real - a.imag*b.imag;
    c.imag = a.real*b.imag + a.imag*b.real;
    return c;
}

/// Dinh nghia toan tu /
Complex operator / (Complex a, Complex b) {
    Complex c;
    Complex tmpb;
    tmpb.real = b.real;
    tmpb.imag = -b.imag;
    c = a*tmpb;
    c.real = c.real/(b.real*b.real+b.imag*b.imag);
    c.imag = c.imag/(b.real*b.real+b.imag*b.imag);
    return c;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}
