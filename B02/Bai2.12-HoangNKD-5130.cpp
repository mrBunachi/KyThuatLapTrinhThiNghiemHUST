/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#include <iostream>
#include <vector>

using namespace std;

typedef struct couple{
    int key;
    int value;
} couple;

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r") )
        freopen(taskname".inp","r",stdin),
                freopen(taskname".out","w",stdout);
    int a,b;
    vector<couple> vt;
    while ( cin >> a && cin >> b ){
        vt.push_back((couple){a,b});
    }

    int n = vt.size();
    ///for ( couple x : vt )
        ///cout << x.fi << ' ' << x.se << endl;

    [&]() mutable -> void {
        for ( int i=1 ; i<n ; i++ )
            for ( int j=0 ; j<i ; j++ )
                if ( vt[j].value < vt[i].value )
                    swap(vt[i],vt[j]);
                else if ( vt[i].value == vt[j].value && vt[j].key < vt[i].key )
                    swap(vt[i],vt[j]);
    }();

    for ( auto x : vt )
        cout << x.key << ' ' << x.value << endl;
    return 0;
}
