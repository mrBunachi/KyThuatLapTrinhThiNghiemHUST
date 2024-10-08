#include<stdio.h>

int tmp;
void reversearray(int arr[], int size){
    int l = 0, r = size - 1;
     for ( int i=0 ; i<size/2 ; i++ ){
        tmp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = tmp;
     }
    /*****************
    # Mang thay doi thong qua con tro arr, chu khong phai thay doi thong qua con tro a #
    *****************/
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1;
    for ( int i=0 ; i<size/2 ; i++ ){
        tmp = *(arr+i);
        *(arr+i) = *(arr+size-i-1);
        *(arr+size-i-1) = tmp;
     }
    /*****************
    # YOUR CODE HERE #
    *****************/
}

void printarray(int a[], int size){
    printf("\n");
    for ( int i=0 ; i<size ; i++ )
        printf("%d  ", a[i]);
    printf("\n");
}

int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    reversearray(a,7);
    printarray(a,7);
    ptr_reversearray(a,7);
    printarray(a,7);
    return 0;
}
