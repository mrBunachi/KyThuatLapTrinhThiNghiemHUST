#include <bits/stdc++.h>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

#define MAX 100

int n, c[MAX][MAX]; //# so thanh pho va ma tran chi phi
int cmin = INT_MAX; //# chi phi di lai nho nhat giua hai thanh pho khac nhau
int best = INT_MAX; //# tong chi phi nho nhat can tim, ban dau dat bang gia tri vo cung lon INT_MAX = 2^31-1
int curr; //# tong chi phi toi thoi diem hien tai
int mark[MAX]; //# danh dau nhung thanh pho da di
int x[MAX]; //# luu giu cac thanh pho da di

//# Doc du lieu vao
void input()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thuat toan quay lui
void TRY(int k)
{
    for(int i = 2; i <= n; i++)
    {
        if ( mark[i] == 0 && i!=x[k-1] ){
            x[k] = i;
            mark[x[k]] = 1;
            curr += c[x[k-1]][x[k]];
            if ( k == n ){
                best = min(best, curr+c[x[k]][1]);
            }
            else{
                if ( curr + ( n-k+1 )*cmin >= best ) continue;
                else
                    TRY(k+1);
            }
            mark[x[k]] = 0;
            curr -= c[x[k-1]][x[k]];
        }
    }
}

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}

