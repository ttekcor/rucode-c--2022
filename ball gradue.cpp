#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[31] = { 0 };
    a[n] = 1;
    for (int i = n; i >= 0; i--) {
        if (i - 1 >= 0) a[i - 1] += a[i];
        if (i - 2 >= 0) a[i - 2] += a[i];
        if (i - 3 >= 0) a[i - 3] += a[i];
    }
    cout << a[0];
    return 0;
}
