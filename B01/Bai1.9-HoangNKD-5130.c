#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=0;
    int arr[1000];
    scanf("%d",&n);
    for ( int i=0 ; i<n ; i++ )
        scanf("%d",&arr[i]);
    for ( int i=0 ; i<n ; i++ )
        for ( int j=i ; j<n ; j++ ){
            for ( int tmp = i ; tmp<=j ; tmp++ )
                printf("%d ",arr[tmp]);
            printf("\n");
        }
    return 0;
}
