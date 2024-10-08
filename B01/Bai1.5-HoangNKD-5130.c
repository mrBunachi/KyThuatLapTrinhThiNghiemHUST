# include <stdio.h>

double* maximum(double* arr, int size){
    if ( size == 0 )
        return NULL;
    else{
        double tmpMAX = -1000;
        double* tmp;
        while ( size-- ){
            if ( *arr > tmpMAX )
                tmp = arr,
                tmpMAX = *arr;
            arr++;
        }
        return tmp;
    }
}

int main()
{
   double a[7]= {13.1, -355.1, 235.1, 47.1, 67.1, 943.1, 1222.2};
   printf("%hp", maximum(a,7));
    ///printf("\nNguyen Khong Duy Hoang - 20225130 - 2023.2\n");
    return 0;
}
