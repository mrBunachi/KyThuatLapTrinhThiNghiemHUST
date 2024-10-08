/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    /// Tao bien tam luu cac gia tri x,y,z
    int tmpx = x, tmpy = y, tmpz= z;

    /// Thay doi gia tri theo yeu cau
    x = tmpy;
    y = tmpz;
    z = tmpx;
}

int main() {
    int x, y, z;

    ///Nhap 3 so nguyen
    scanf("%d %d %d",&x,&y,&z);

    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}
