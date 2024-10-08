#include <bits/stdc++.h>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

struct state
{
    /// Qua nang thu i mang trang thai j
    /// j = 0 : khong duoc chon, j = -1 : qua nang mang dau -, j = 1 : qua nang mang dau +
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }

    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# tong cac qua nang duoc chon
    int sum = 0;
    s.push(state(1, -1));
    while ( !s.empty() )
    {
        state &top = s.top();
        if (top.i > n)
        {
            if (sum == M)
            {
                for (int i = 1; i <= n; ++i)
                {
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }
    //# Khu đe quy
        /// Khi top.j > -1 tuc la bang 0 hoac 1 =>
        /// trang thai do da duoc duyet qua =>
        /// khoi phuc tong sum
        if ( top.j > - 1 ){
            sum = sum - m[top.i]*x[top.i];
        }

        /// Khi top.j khong thuoc {-1,0,1} => loai
        if ( top.j > 1 ){
            s.pop();
            continue;
        }

        /// Cap nhat
        x[top.i] = top.j;
        sum = sum + m[top.i]*x[top.i]; /// cap nhat sum
        s.push({top.i+1,-1}); /// push trang thai co so voi j=-1
        top.j++;///sum da duoc cap nhat, cac phep toan duoc luu vao x[i]
        /// => top.j++ ( khong anh huong )
    }
    cout << -1;
    return 0;
}
