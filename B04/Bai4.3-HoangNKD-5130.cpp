// #include <iostream>
// #include <cmath>
// #include <iomanip>
// using namespace std;
// using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b)
{
    /****************
        Ho va ten: Nguyen Khong Duy Hoang
        MSSV : 20225130
    */
    double a1 = get<0>(a), a2 = get<1>(a), a3 = get<2>(a);
    double b1 = get<0>(b), b2 = get<1>(b), b3 = get<2>(b);
    return {a2*b3-b2*a3, -a1*b3+b1*a3, a1*b2-b1*a2};
}

// int main() {
// cout << setprecision(2) << fixed;
// Vector a {1.2, 4, -0.5};
// Vector b {1.5, -2, 2.5};
// Vector c = cross_product(a, b);
// cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
// return 0;
// }

