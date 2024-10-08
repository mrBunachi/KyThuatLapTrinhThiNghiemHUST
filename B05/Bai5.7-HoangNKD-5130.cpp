#include <iostream>
#include <algorithm>
using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int main() {
    int n;
    cin >> n;
    int ans = 0, sum = 0;

    while (n--) {
        int k, t;
        cin >> k >> t;

        if (t == 1) {
            while (k--) {
                int a;
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        } else if (t == -1) {
            while (k--) {
                int a;
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }

    cout << ans;
    return 0;
}
