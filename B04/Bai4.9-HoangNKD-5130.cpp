#include <iostream>
#include <list>
#include <queue>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

#define pII pair<int, int>
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    vector<int> ans(adj.size());
    int l = ans.size();
    for ( int i=0 ; i<l ; i++ )
        ans[i] = INT_MAX;
    ans[0] = 0;

    priority_queue<pII, vector<pII>, greater<pII>> Q;

    for ( int i=0 ; i<l ; i++ )
        Q.push({i,ans[i]});

    while ( !Q.empty() )
    {
        /// Chon ra dinh tu 0 nho nhat
        pII top = Q.top();
        Q.pop();
        int u = top.first;
        int kc = top.second;

        if ( kc > ans[u] )    continue;

        for ( auto it : adj[u] )
        {
            int v = it.first;
            int w = it.second;

            if ( ans[v] > ans[u]+w )
            {
                ans[v] = ans[u]+w;
                Q.push({v, ans[v]});
            }
        }
    }
    return ans;
}

void filee()
{
#define taskname "hello123"
    if ( fopen(taskname".inp","r" ) )
    {
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
}

int main()
{
    //filee();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 10;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 2);
    add_edge(0, 7, 3);
    add_edge(1, 7, 15);
    add_edge(1, 2, 8);
    add_edge(1, 8, 38);
    add_edge(2, 3, 2);
    add_edge(2, 8, 12);
    add_edge(3, 4, 9);
    add_edge(3, 5, 4);
    add_edge(4, 5, 7);
    add_edge(5, 6, 2);
    add_edge(5, 9, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);
    add_edge(7, 9, 71);
    add_edge(7, 5, 17);

    vector<int> distance = dijkstra(adj);
    for (unsigned int i = 0; i < distance.size(); ++i)
    {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}
