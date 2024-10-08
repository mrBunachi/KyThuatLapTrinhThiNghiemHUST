
#include <iostream>
#include <algorithm>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int gcd(int a, int b)
{
    if (b ==0) return a;
    return gcd(b, a% b);
}

int gcd2(int a, int b)
{
//# Khu de quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    int tmp;
    while ( b!= 0 ){
        tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}
int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
