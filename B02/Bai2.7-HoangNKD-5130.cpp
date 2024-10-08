/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#include <iostream>
using namespace std;

//# viết hàm arr_sum
template <class T>

T arr_sum(T a[], int m, T b[], int n){
    T ans=0;
    for ( int i=0 ; i<m ; i++ )
        ans = ans + a[i];
    for ( int i=0 ; i<n ; i++ )
        ans = ans + b[i];
    return ans;
}

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r")){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    int val;
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    return 0;
}
