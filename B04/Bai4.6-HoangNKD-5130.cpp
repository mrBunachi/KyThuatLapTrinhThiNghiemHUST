#include <iostream>
#include <list>
#include <queue>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

void bfs(vector< list<int> > adj)
{
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bat dau tu dinh 1
    /*****************
    # YOUR CODE HERE #
    *****************/
    while ( !Q.empty() ){
        int t = Q.front();
        if ( !visited[t] ){
            visited[t] = true;
            cout << t << '\n';
        }
        Q.pop();
        for ( auto v : adj[t] ){
            if ( !visited[v] ){
                //visited[v] = true;
                Q.push(v);
            }
        }
    }
}

int main()
{
#define taskname "hello123"
    if ( fopen(taskname".inp","r" ) )
    {
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);

    return 0;
}
