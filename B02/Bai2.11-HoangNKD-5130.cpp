/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#include <iostream>
#include <vector>

using namespace std;

void nhapDaThuc(vector<int>& daThuc, int n)
{
    daThuc.resize(n+1);
    for (int i = 0; i <= n; i++)
        cin >> daThuc[i];
}

vector<int> nhanDaThuc(const vector<int>& daThucA, const vector<int>& daThucB)
{
    int m = daThucA.size();
    int n = daThucB.size();
    vector<int> ketQua(m + n - 1, 0);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; ++j)
            ketQua[i + j] += daThucA[i] * daThucB[j];

    return ketQua;
}

void inDaThuc(const vector<int>& daThuc)
{
    int n = daThuc.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << daThuc[i];
        else if ( daThuc[i] != 0 )
            cout << " + " << daThuc[i] << "x^" << i;
    }
    cout << endl;
}

int xorCacHeSo(const vector<int>& heSo) {
    int result = 0;
    for (int i = 0; i < heSo.size(); ++i) {
        result ^= heSo[i];
    }
    return result;
}

int main()
{
#define taskname "hello123"
    if ( fopen(taskname".inp","r") )
        freopen(taskname".inp","r",stdin),
                freopen(taskname".out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int nA, nB;
    ///cout << "Nhap so he so cua da thuc A: \n";
    cin >> nA;
    vector<int> daThucA;
    nhapDaThuc(daThucA, nA);

    ///cout << "Nhap so he so cua da thuc B: \n";
    cin >> nB;
    vector<int> daThucB;
    nhapDaThuc(daThucB, nB);

    ///cout << nA << ' ' << nB << endl;
    // Tính toán đa thức kết quả khi nhân hai đa thức
    vector<int> ketQua = nhanDaThuc(daThucA, daThucB);

    // In ra đa thức kết quả
    ///cout << "Da thuc A: ";
    ///inDaThuc(daThucA);
    ///cout << "\nDa thuc B: ";
    ///inDaThuc(daThucB);
    ///cout << "\nKet qua sau khi nhan hai da thuc: ";
    ///inDaThuc(ketQua);

    cout << xorCacHeSo(ketQua);

    return 0;
}
