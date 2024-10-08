#include <stdio.h>

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
int cube(int x) {
    /// tra ve lap phuong cua x
    return x*x*x;
}

/// viet ham tinh lap phuong cua mot so kieu double
double cube(double x){
    return (double)x*x*x;
}

int main() {
    #define taskname "hello123"
    if ( fopen(taskname".inp","r")){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    int n;
    double f;
    scanf("%d %lf", &n, &f);

    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));

    return 0;
}
