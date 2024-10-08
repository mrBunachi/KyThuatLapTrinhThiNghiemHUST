#include <iostream>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int c[100][100];

int binom(int n, int k)
{
    if (k > n) return 0 ;
    if (k == 0) return 1;
    return binom(n - 1, k) + binom(n - 1, k - 1);
}

int binom2(int n, int k)
{
//# Khu de quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    if ( k==0 || n==k )
        c[k][n] = 1;
    else{
        if ( c[k][n-1] == 0 )
            c[k][n-1] = binom2(n-1,k);
        if ( c[k-1][n-1] == 0 )
            c[k-1][n-1] = binom2(n-1,k-1);
        c[k][n] = c[k][n-1] + c[k-1][n-1];
    }
    return c[k][n];
}

int main()
{
#define taskname "hello123"
    if ( fopen(taskname".inp","r" ) )
    {
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }

    int m;
    cin >> m;
    for(int n=1; n <= m; ++n)
    {
        for(int k=0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for(int n=1; n <= m; ++n)
    {
        for(int k=0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
