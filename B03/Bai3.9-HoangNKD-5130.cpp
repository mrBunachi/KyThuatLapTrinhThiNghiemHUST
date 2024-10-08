#include<bits/stdc++.h>

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

using namespace std;

int n,k1,k2;
int x[250];
int cnt = 0;

void ghinhan(){
    for(int i=1; i<=n; i++)
        cout << x[i];
    cout << endl;
    cnt++;
}

int cnt1 = 0;

bool check1(int  a, int  i){
    if ( a==1 )
        return true;
    if ( i==0 ){
        /// Neu ghep vao day ngay nghi
        if ( x[a-1] == 0 )
            return false;
        else{
            /// neu nghir khi chua lam viec du k1 ngay thi sai
            if ( cnt1 < k1 )
                return false;
        }
    }
    else {
        /// Neu ghep vao day ngay di lam
        if ( x[a-1] == 0 ){
            /// Neu so ki tu con lai khong du de lap k1 thi false
            if ( n-a+1 < k1 )
                return false;
        }
            /// neu da di lam k2 hoac hoac hon roi thi phai nghir
        else if ( cnt1 >=k2 )    return false;
    }

    /// con lai thi return true
    return true;
}

/// Kiem tra xem ngay a co the 0/1 : nghi/hay lam
bool check(int a, int i){
    if ( a==1 )
        return true;
    /// Neu ngay truoc do da nghi
    if ( x[a-1] == 0 ){
        /// thi khong duoc nghi nua
        if ( i==0 )
            return false;
        /// nguoc lai neu di lam ma so ngay con lai khong du k1 ngay di lam
        ///= > loi
        /// nhanh can !!!
        else if ( n-a+1 < k1 ) return false;
    }

    /// neu ngay truoc do da di lam
    else if ( x[a-1] == 1 ) {
        /// ma hom nay muon nghi
        if ( i==0 ){
            /// nhung chua di lam du k1 ngay => loi
            if ( cnt1 <k1 )
                return false;
        }
        /// neu di lam hom nay
        else if ( i==1 ){
            /// ma so ngay di lam da dat dinh => phai nghi
            if ( cnt1 >= k2 )
                return false;
        }
    }

    /// con lai thi return true
    return true;
}

void TRY(int  a){
    for(int  i=0; i<=1; i++){
        if( check(a,i) ) {
            x[a] = i;
            int tmp = cnt1;
            if ( i==1 ){
                if ( x[a-1] == 1 )
                    cnt1++;
                else
                    cnt1=1;
            }
            else cnt1 = 0;
            if ( a==n )
                ghinhan();
            else
                TRY(a+1);
            cnt1 = tmp;
        }
    }
}

int main(){
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k1 >> k2;
    TRY(1);
    return 0;
}
