#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

void dfs(vector< list<int> > adj)
{
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bat dau tu dinh so 1
    /*****************
    # YOUR CODE HERE #
    *****************/
    while ( !S.empty() ){
        int top = S.top();
        if ( !visited[top] ){
            visited[top] = true;
            cout << top << endl;
        }
        if ( !adj[top].empty() ){
            int nextTop = adj[top].front();
            adj[top].pop_front();
            if ( !visited[nextTop] )
                S.push(nextTop);
        } else { S.pop(); }
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
    dfs(adj);
    return 0;
}
