#include <iostream>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int n, k;
int m;
int cnt=0;
int graph[35][35];
int X[35];
int mark[35];

void ghinhan(){
    for ( int i=1 ; i<=k+1 ; i++ )
        cout << X[i] << ' ';
    cout << endl;
}

bool check( int a, int v ){
    if ( mark[v] == 1 )
        return false;
    for ( int i=1 ;  i<a ; i++ ){
        if ( X[i] == v || graph[X[a-1]][v] == 0 )
            return false;
    }
    return true;
}

void TRY(int a){
    for ( int i=1 ; i<=n ; i++ ){
        if ( check(a, i)){
            mark[i] = 1;
            X[a] = i;

            if ( a==k+1 ){
                //ghinhan();
                cnt++;
            }
            else
                TRY(a+1);
            mark[i] = 0;
        }
    }
}

int main(){
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for ( int i=0 ; i<33 ; i++ )
    for ( int j=0 ; j<33 ; j++ )
        graph[i][j] = 0;
    fill(begin(mark),end(mark),0);

    cin >> n >> k >> m;
    int a, b;
    for ( int i=0 ; i<m ; i++ ){
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    /**
    for ( int i=1 ; i<=n ; i++ )
        for ( int j=1 ; j<=n ; j++ )
            cout << graph[i][j] << " \n"[j==n];
            */

    TRY(1);

    cout << cnt/2;

    return 0;
}
