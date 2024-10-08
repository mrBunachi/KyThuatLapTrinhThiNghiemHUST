#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

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

    int n;
    stack<int> st;
    vector<int> h(1000005, 0);
    ///vector<int> s(1000005, 0);
    cin >> n;
    for ( int i=1 ; i<=n ; i++ )
        cin >> h[i];
    h[n+1] = 0;

    /**
    for ( int i=1 ; i<=n+1 ; i++ )
        cout << h[i] << ' ';
    cout << endl;*/

    int maxx = 0;
    for ( int i=1;  i<=n+1 ; i++ ){
        if ( st.empty() || h[st.top()] <= h[i] );
        else{
            int tmp;
            while ( !st.empty() && h[st.top()] > h[i] ){
                tmp = st.top();
                st.pop();
                if ( st.empty() )
                    tmp = h[tmp]*(i-1);
                else
                    tmp = h[tmp]*(i-st.top()-1);
                maxx = max(maxx, tmp);
            }
        }
        st.push(i);
    }
    cout << maxx << endl;
    return 0;
}
