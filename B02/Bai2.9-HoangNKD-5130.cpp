/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT = 100; /// gioi han tinh cua x
const int NUM_ITER = 100000; /// so diem chuan bi
const int NUM_INPUTS = NUM_ITER * 100;

/// ham tinh sigmoid _slow: dung ham mac dinh
double sigmoid_slow(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input(){
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i){
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code
//# khai bao cac bien phu tro can thiet
/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
    double prepare[100001];
    #define lowLIMIT -LIMIT
    double const delta = 0.002; /// delta = |x(i+1)-x(i)| = 200/100000 = 0.002

//# ham chuan bi du lieu
void precalc()
{
/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
    for ( int i=0 ; i<=NUM_ITER ; i++ )
        prepare[i] = sigmoid_slow( lowLIMIT + i*delta );
    /// tinh sigmoid cua delta x_i
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x)
{
/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/
    if ( x > LIMIT ) return (double)1; /// neu x > 100 -> tra ve 1
    if ( x < lowLIMIT ) return (double)0; /// neu x < -100 -> tra ve 0
    int i = ( x-lowLIMIT )/delta; /// tinh i trong x[i]
    double x_i = i*delta + lowLIMIT; /// Tim x_i tuong ung
    double tmp = ( (x-x_i)/delta )*(prepare[i+1]-prepare[i]);/// Khoang cach giua y(i+1) va yi la hieu cua prepare(i+1) va prepare(i)=>dua vao ti le de tim y tuong ung
    return prepare[i] + tmp;
}
//# END fast code

double benchmark(double (*calc)(double), vector<double> &result)
{
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t)
    {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i)
        {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//# printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b)
{
    const double EPS = 1e-6;
    if (a.size() != b.size()) return false;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        if (fabs(a[i] - b[i]) > EPS)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r") )
        freopen(taskname".inp","r",stdin),
        freopen(taskname".out","w",stdout);

    prepare_input();
    precalc();
    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);
    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a, b) && (slow/fast > 1.3))
    {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }
    else
    {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }

    return 0;
}
