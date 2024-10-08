#include <iostream>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int t;
int n,h;
int hamming = 0;
int x[20];

void ghinhan(){
    for ( int i=1 ; i<=n ; i++ )
        cout << x[i];
    cout << "\n";
}

bool check( int a, int i ){
    if ( i==1 && hamming >= h )
        return false;
    return true;
}

void TRY(int a){
    for ( int i=0 ; i<=1 ; i++ ){
        if ( check(a,i) ){
            x[a] = i;
            if ( i==1 )
                hamming++;
            if ( a==n ){
                if ( hamming == h )
                    ghinhan();
            }
            else
                TRY(a+1);
            if ( i==1 )
                hamming--;
        }
        /// nhanh can : neu hamming da > h thi bo qua tat ca truong hop ve sau
        if ( hamming > h )
            continue;
    }
}

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    for ( int t1 = 1 ; t1<=t ; t1++ ){
            cin >> n >> h;
            for ( int i=0 ; i<20 ; i++ )
                x[i] = 0;
            hamming = 0;
            TRY(1);
            cout << "\n";
    }
    return 0;
}
