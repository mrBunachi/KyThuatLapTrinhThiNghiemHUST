#include <stdio.h>
#include <stdlib.h>

int n;
int **mtx1, **mtx2, **res;

void nhap(int **mt){
    for ( int i=0 ; i<n ; i++ )
        for ( int j=0 ; j<n ; j++ )
            scanf("%d", *(mt+i)+j);
}

void allocate_mem(int ***mt, int n){
    *mt = (int **)malloc(n*sizeof(int *));
    for ( int i=0 ; i<n ; i++ )
        *(*mt+i) = (int *)malloc(n * sizeof(int));
}

void free_mem(int **mt){
    for ( int i=0 ; i<n ; i++ )
        free(*(mt+i));
    free(mt);
}

void summtx(int **mt1, int **mt2, int **ans){
    for ( int i=0 ; i<n ; i++ )
        for ( int j=0 ; j<n ; j++ )
            *(*(ans+i)+j) = *(*(mt1+i)+j) + *(*(mt2+i)+j);
}

void productmtx(int **mt1, int **mt2, int **ans){
    for ( int i=0 ; i<n ; i++ )
    for ( int j=0 ; j<n ; j++ ){
        *(*(ans+i)+j) = 0;
        for ( int k=0 ; k<n ; k++ )
            *(*(ans+i)+j) = *(*(ans+i)+j) + *(*(mt1+i)+k) * *(*(mt2+k)+j);
    }
}

int main(){
    #define taskname "hello123"
    if ( fopen(taskname".inp","r"))
        freopen(taskname".inp","r",stdin),
        freopen(taskname".out","w",stdout);

    scanf("%d",&n);

    allocate_mem(&mtx1, n);
    allocate_mem(&mtx2, n);
    allocate_mem(&res, n);

    nhap(mtx1);
    nhap(mtx2);

    summtx(mtx1,mtx2,res);
    for ( int i=0 ; i<n ; i++ ){
        for ( int j=0 ; j<n ; j++ )
            printf("%d ", *(*(res+i)+j));
        printf("\n");
    }

    productmtx(mtx1,mtx2,res);
    for ( int i=0 ; i<n ; i++ ){
        for ( int j=0 ; j<n ; j++ )
            printf("%d ",*(*(res+i)+j));
        printf("\n");
    }

    free_mem(mtx1);
    free_mem(mtx2);
    free_mem(res);
    return 0;
}
