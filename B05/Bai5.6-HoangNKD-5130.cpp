#include <iostream>
using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

char cal(double a) {
    if (a < 4) return 'F';
    else if (a < 5.5) return 'D';
    else if (a < 7) return 'C';
    else if (a < 8.5) return 'B';
    else return 'A';
}

int main() {
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;

    while (n--) {
        double a; // Sua kieu du lieu cua 'a' thanh 'double' de phu hop voi ham `cal`
        cin >> a;
        char grade = cal(a); // Luu ket qua cua ham 'cal' de su dung lai
        if (grade == 'A') ++A;
        else if (grade == 'B') ++B;
        else if (grade == 'C') ++C;
        else if (grade == 'D') ++D;
        else if (grade == 'F') ++F;
    }

    cout << A << " " << B << " " << C << " " << D << " " << F;
    return 0;
}
