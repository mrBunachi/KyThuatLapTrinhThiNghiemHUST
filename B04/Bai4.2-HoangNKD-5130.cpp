// #include <iostream>
// #include <cmath>
// #include <iomanip>
// #include <utility>
// using namespace std;
// using Point = pair<double, double>;

double area(Point a, Point b, Point c)
{
    /****************
        Ho va ten: Nguyen Khong Duy Hoang
        MSSV : 20225130
    */
    Point ab = {b.first - a.first, b.second-a.second};
    Point ac = {c.first - a.first, c.second-a.second};
    return (double) (0.5*abs(ab.first*ac.second-ab.second*ac.first) );
}

//int main()
//{
    //cout << setprecision(2) << fixed;
    //cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    //return 0;
//}
