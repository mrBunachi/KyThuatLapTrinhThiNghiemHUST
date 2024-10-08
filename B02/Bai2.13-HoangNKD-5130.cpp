/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <ostream>

using namespace std;

string operator + ( string a, string b )
{
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digitA = (i >= 0) ? (a[i--] - '0') : 0;
        int digitB = (j >= 0) ? (b[j--] - '0') : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

string operator - ( string a, string b )
{
    string result = "";
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0)
    {
        int digitA = (i >= 0) ? (a[i--] - '0') : 0;
        int digitB = (j >= 0) ? (b[j--] - '0') : 0;
        int diff = digitA - digitB - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }

    reverse(result.begin(), result.end());

    return result;

}

string operator * ( string a, string b ){
    if (a == "0" || b == "0") return "0";
    string result = "0";
    for (int i = b.size() - 1; i >= 0; i--)
    {
        string temp = "";
        int digitB = b[i] - '0';
        int carry = 0;
        for (int j = a.size() - 1; j >= 0; j--)
        {
            int digitA = a[j] - '0';
            int product = digitA * digitB + carry;
            carry = product / 10;

            temp.push_back((product % 10) + '0');
        }
        if (carry > 0) temp.push_back(carry + '0');
        reverse(temp.begin(), temp.end());
        for (int k = i; k < b.size() - 1; k++)
            temp.push_back('0');

        result = (string)(result + temp);
    }
    return result;
}

 int compare(string a, string b) {
    while (a.size() > 1 && a[0] == '0') a.erase(0, 1);
    while (b.size() > 1 && b[0] == '0') b.erase(0, 1);

    int lenA = a.size();
    int lenB = b.size();

    if (lenA < lenB) return -1;
    if (lenA > lenB) return 1;
    for (int i = lenA-1; i >=0; i--) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

int main()
{
#define taskname "hello123"
    if ( fopen(taskname".inp","r") )
        freopen(taskname".inp","r",stdin),
                freopen(taskname".out","w",stdout);
    string a, b;
    cin >> a;
    cin >> b;

    int aneg = 0, bneg = 0;
    if ( a[0] == '0' ) aneg = 1;
    if ( b[0] == '0' ) bneg = 1;
    a = a.substr(1);
    b = b.substr(1);

    string num3 = "3", num4 = "4", num12 = "12";

    if ( compare(a, num4) == -1 && aneg == 1 ){
        a = num4 - a;
        aneg = 0;
    }
    else {
        if ( aneg == 1 )
            a = a - num4;
        else
            a = a + num4;
    }
    ///cout << a << " " << aneg << endl;

    if ( compare(b,num3) == -1 && bneg == 0 ){
        b = num3 - b;
        bneg = 1;
    }
    else {
        if ( bneg == 1 )
            b = b+num3;
        else
            b = b-num3;
    }
    ///cout << b << " " << bneg << endl;

    string res = a * b;
    int resneg = 0;
    if ( aneg != bneg )
        resneg = 1;
    ///cout << "here " << resneg << ' ';
    if ( compare(res,num12) == -1 && resneg == 1 ){
        res = num12 - res;
        resneg = 0;
    }
    else {
        if ( resneg == 1 )
            res = res - num12;
        else
            res = res + num12;
    }
    cout << 1 - resneg ;
    cout << res;

    return 0;
}
