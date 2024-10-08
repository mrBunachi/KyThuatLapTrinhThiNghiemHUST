#include <stdio.h>
#include <stdlib.h>

int *a;
int n, tmp;

void inoutfile(){
    #define taskname "hello123"
    if ( fopen(taskname".inp","r")){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
}

int main(){

    ///inoutfile();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //#Allocate memory
    a = (int *)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    //#Sort array
    int tmp;
    for ( int i=0 ; i<n ; i++ )
        for ( int j=0 ; j<i ; j++ ){
            if ( *(a+i) > *(a+j) ){
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
        }

    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    free(a);
    return 0;
}
