#include <bits/stdc++.h>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

#define msi map<string, int>

int n, q;
string s,t;

/// So lan xuat hien cua tu t trong van ban thu d la f[d][t]
vector<msi> f;

/// maxf[d] la so lan xuat hien nhieu nhat cua f[d][t], ans luu ket qua
vector<int> maxf, ans;

/// df[t] la so van ban chua tu t
msi df;

/// score(t, d) = TF(t, d) * IDF(t)
double scoreCalculate(string t, int d){
    if(f[d].count(t) == 0)
        return 0;/// neu khong tim thay tu t trong van ban d thi diem = 0
    double tf = 0.5 + 0.5 * (double)f[d][t]/maxf[d];
    double idf = log2((double)n / df[t]);
    return tf * idf;
}

int main(){
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    f.resize(n);
    maxf.resize(n);
    fill(maxf.begin(), maxf.end(), 0);/// cac phan tu trong maxf ban dau = 0
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        istringstream str(s);
        set<string> check;
        while(getline(str, t, ',')){
            f[i][t]++;
            maxf[i] = max(maxf[i], f[i][t]);

            /// check luu lai chuoi t de kiem tra
            if(check.find(t) == check.end()){
                check.insert(t);
                df[t]++;
            }
        }
    }

    cin >> q;
    cin.ignore();
    for(int i = 0; i < q; i++){
        int res = 0;
        getline(cin, s);
        istringstream str(s);
        vector<double> score(n, 0);
        while(getline(str, t, ','))
            for(int j = 0; j < n; j++)
                score[j] += scoreCalculate(t, j);/// tinh diem cua t voi van ban j dang xet

        for ( int k = 0; k < n; k++)
            if( score[k] > score[res] )
                res = k;
        cout << res+1 << endl;
    }

    return 0;
}
