# include <stdio.h>

int countEven(int* arr, int n){
    int count = 0;

    for ( int i=0 ; i<n ; i++ )
        if ( (*(arr+i))%2==0 )
            count++;

    return count;
}

int main()
{
   int a[7]= {13, -355, 235, 47, 67, 943, 1222};
   printf("%d",countEven(a,7));
    ///printf("\nNguyen Khong Duy Hoang - 20225130 - 2023.2\n");
    return 0;
}
