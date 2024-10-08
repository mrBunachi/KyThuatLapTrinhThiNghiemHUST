#include <iostream>
#include <map>
#include <string>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int cnt(string s){
    map<int, int> mp;
    int dif = 0;
    for ( int i=0 ; i<(int)s.size() ; i++ ){
        if ( s[i] == '0' )
            dif++;
        else if ( s[i] == '1' )
            dif--;
        mp[dif]++;
    }
    dif = 0;
    for ( auto v : mp ){
        dif += v.second*(v.second-1)/2;
    }
    return dif+mp[0];
}

int main() {
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;

    cout << cnt(s) << endl;

    return 0;
}

