#include <bits/stdc++.h>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int a[1000], n;
int mem[1000]; //# mang ghi nho loi giai cac bai toan con da duoc giai
void init()
{
    memset(mem, -1, sizeof(mem));
}

//# quy hoach dong
//# Hàm lis(i) tra ve do dài dãy con tăng dài nhat ket thúc boi a[i]
int lis(int i)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    for ( int k=0 ; k<i ; k++ ){
        if ( a[k] < a[i] )
            mem[i] = max(mem[i],mem[k]+1);
    }
    if ( mem[i] == -1 ){
        mem[i] = 1;
        return 1;
    }
    else return mem[i];
}

//# Truy vet loi giai
void trace(int i)
{
    for(int j = 0; j < i; j++)
    {
        if (a[j] < a[i] && mem[i] == 1 + mem[j])
        {
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 0; i < n; i++)
    {
        if ( res < lis(i) )
        {
            res = lis(i);
            pos = i;
            //cout << "i = " << i << " res = " << res << endl;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
