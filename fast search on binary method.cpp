#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    unsigned s, k;

    cin >> s;
    vector<long int> tmp(s);

    for (auto& x : tmp) {
        cin >> x;
    }

    sort(tmp.begin(), tmp.end());

    cin >> k;
    while (k--) {
        long int l, r;
        cin >> l >> r;
        auto lower = lower_bound(tmp.begin(), tmp.end(), l);
        auto upper = upper_bound(lower, tmp.end(), r);
        cout << distance(lower, upper) << ' ';
    }
}