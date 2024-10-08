/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r") )
        freopen(taskname".inp","r",stdin),
        freopen(taskname".out","w",stdout);
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a =
    {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
//# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    auto compareFuntion = [] (vector<int> &a, vector<int> &b)->bool{
        int sum1=0, sum2=0;
        for ( int x : a )
            sum1 += x;
        for ( int x : b )
            sum2 += x;
        return sum1>sum2;
    };
    sort(a.begin(),a.end(),compareFuntion);
    for (const auto &v : a)
    {
        for (int it : v)
        {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
