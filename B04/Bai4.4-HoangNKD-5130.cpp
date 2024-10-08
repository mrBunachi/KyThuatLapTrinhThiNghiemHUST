#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

bool cmp(int a, int b){
    return a>b;
}

bool isEven(int x) { return x%2==0;}

void print_vector(vector<int> &a)
{
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (vector<int>::iterator it = a.begin(); it != a.end(); ) {
        if (*it % 2 == 0) {
            it = a.erase(it);
        } else {
            ++it;
        }
    }
}
void sort_decrease(vector<int> &a)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    sort(a.begin(), a.end(), cmp);
}
vector<int> merge_vectors(const vector<int> &a, const vector<int> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    vector<int> ans;
    for ( auto v : a )
        ans.push_back(v);
    for ( auto v : b )
        ans.push_back(v);
    sort(ans.begin(),ans.end(),cmp);
    return ans;
}
int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }
    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);
    delete_even(b);

    cout << "Odd elements of b: ";
    print_vector(b);
    sort_decrease(a);

    cout << "Decreasingly sorted a: ";
    print_vector(a);
    sort_decrease(b);

    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);
    return 0;
}
