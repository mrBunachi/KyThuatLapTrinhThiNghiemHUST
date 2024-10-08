#include <iostream>
#include <queue>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#define pII pair<int, int>

int n,linh;

// dinh nghia mot functor cho ham so sanh
struct cmp {
    bool operator()(pII a, pII b) {
        return min(a.first, a.second) < min(b.first, b.second);
    }
};

priority_queue<pII, vector<pII>, cmp> Q;

void duyet(priority_queue<pII, vector<pII>, cmp> Q){
    while ( !Q.empty() ){
        pII tmp = Q.top(); Q.pop();
        cout << tmp.first << ' ' << tmp.second << endl;
    }
}

int killcnt = 0;
void solve(){
    while ( !Q.empty() && linh !=0 ){
        pII tmp = Q.top(); Q.pop();
        if ( tmp.first <= tmp.second )
            killcnt += tmp.first;
        else{
            killcnt += tmp.second;
            Q.push({tmp.first-tmp.second,tmp.second});
        }
        linh--;
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

    int a,b,total = 0;
    cin >> n >> linh;
    for ( int i=0 ; i<n ; i++ ){
        cin >> a >> b;
        total += a;
        Q.push({a,b});
    }
    /// duyet(Q);
    solve();
    cout << total-killcnt;
    return 0;
}
