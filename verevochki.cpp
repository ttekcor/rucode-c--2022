#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

bool check(vector<double>& v, double n, double k, double x) {

    int sum = 0;

    for (double i = 0; i < n; ++i)sum += int((v[i] + 0.0) / x);

    if (sum >= k)return 1;
    else return 0;

}

double bs(vector<double>& v, double n, double k) {

    double l = 0;
    double r = 1e8;

    for (double i = 0; i < 100; ++i) {

        double mid = (l + r) / 2;

        if (check(v, n, k, mid))l = mid;
        else r = mid;

    }

    return l;

}