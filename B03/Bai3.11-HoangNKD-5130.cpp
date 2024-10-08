#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int n, k, number,s ;
int c[200][200];
vector<int> vt;
string input;
int X[250];

void ghinhan(){
    for ( int i=1 ; i<=s ; i++ )
        cout << X[i] << ' ';
    cout << endl;
}

bool check( int a, int v ){
    for ( int i=1 ;  i<a ; i++ ){
        if ( X[i] == v || v == X[s] || c[X[a-1]][v] == 0 )
            return false;
    }
    return true;
}

int curr = 0, best = INT_MAX;

void TRY(int a){
    for ( int i=0 ; i<s ; i++ ){
        if ( check(a, vt[i])){
            X[a] = vt[i];
            curr = curr + c[X[a-1]][X[a]];

            if ( a==s-1 ){
                ///ghinhan();
                if ( c[X[a]][X[s]] != 0 )
                    best = min(best, curr + c[X[a]][X[s]]);
            }
            else
                TRY(a+1);
            curr = curr - c[X[a-1]][X[a]];
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for ( int i=1 ; i<=n ; i++ ){
        for ( int j=1 ; j<=n ; j++ )
            cin >> c[i][j];
    }
    cin.ignore(); // Ignore the newline character after reading k
    for ( int i=1 ; i<=k  ; i++ ){
        fill(begin(X), end(X), 0);
        getline(cin, input);
        stringstream ss(input);
        while ( ss >> number )
            vt.push_back(number);

        s = vt.size();
        s = vt.size();
        if (s == 0) {
            cout << 0 << endl;
            continue;
        }

        X[1] = vt[0];
        X[s] = vt[s-1];
        curr = 0;
        best = INT_MAX;

        ///cout << X[1] << ' ' << X[s] << endl;

        TRY(2);

        if ( best == INT_MAX )
            cout << 0;
        else
            cout << best;
        cout << endl;

        vt.clear();
    }
    return 0;
}

