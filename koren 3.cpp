#include <iostream>


using namespace std;

long double fun(long double a, long double b, long double c, long double d, long double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    long double a, b, c, d;
    cin >> a >> b >> c >> d;
    long double l, r;
    r = 1;
    l = -1;
    while ((fun(a, b, c, d, r) * fun(a, b, c, d, l)) >= 0)
    {
        r *= 2;
        l *= 2;
    }
    long double x, v1, v2;
    for (int i = 0; i < 100; i++)
    {
        x = (l + r) / 2;
        v1 = fun(a, b, c, d, x);
        v2 = fun(a, b, c, d, r);
        if (v1 * v2 <= 0) l = x;
        else r = x;
    }
    cout << setprecision(7) << l;
    return 0;
}