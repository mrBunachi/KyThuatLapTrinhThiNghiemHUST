#include <iostream>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int n;
int X[100], Y[100]; /// Luu toa do cac buoc di chuyen cua quan ma
int mark[100][100]; /// Danh dau cac o ma quan ma co the di chuyen qua
/// Mang hx, hy mo ta 8 vi tri quan ma co the di chuyen ke tu vi tri hien tai
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};
/// In ra day cac di chuyen tim duoc
void print_sol()
{
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

int checkbien(int x, int y){
    if ( x<1 || x>n || y<1 || y>n )
        return 0;
    else
        return 1;
}

/// Thuat toan quay lui
void TRY(int k)
{
    for(int i = 0; i < 8; i++)
    {
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if ( mark[xx][yy] == 1 || checkbien(xx,yy) == 0 ){
            continue;
            cout << "Here";
        }
        else {
                ///cout << "Hello i = " << i << " k = " << k << endl ;
                X[k] = xx;
                Y[k] = yy;
                mark[xx][yy] = 1;
        }
        if ( k == n*n )
            print_sol();
        else
            TRY(k+1);
        mark[xx][yy] = 0;
    }
}
int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    cin >> n;
    mark[1][1] = 1;
    X[1] =1;
    Y[1] = 1;
    TRY(2);
    return 0;
}
