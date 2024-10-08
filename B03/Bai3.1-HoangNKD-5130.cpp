#include <iostream>
#include <string>
#include <vector>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int x;

int lucas(int n) {
    if ( n==0 )
        return 2;
    else if ( n==1 )
        return 1;
    else
        return lucas(n-1)+lucas(n-2);
}

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }

    int x;
    cin >> x;
    cout << lucas(x);
    return 0;
}
