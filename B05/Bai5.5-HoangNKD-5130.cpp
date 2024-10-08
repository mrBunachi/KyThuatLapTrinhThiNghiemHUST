#include <iostream>
using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

int main() {
    int n;
    cin >> n;
    bool found = false;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        // Dieu kien nam nhuan chinh xac
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
            found = true;
            break;  // Tim thay nam nhuan, dung kiem tra
        }
    }

    if (found)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
