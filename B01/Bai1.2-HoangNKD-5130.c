#include <stdio.h>
int main()
{
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5; i++)  printf("\t    a[%d]",i);
    printf("\n");
    for ( int i=0 ; i<5 ; i++ )
        printf("%p ",&(a[i]));
    /*****************
    Nguyen Khong Duy Hoang 20225130
    *****************/
    return 0;
}

