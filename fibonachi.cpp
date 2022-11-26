#include <iostream>

using namespace std;

int main()
{

    int  n, c = 0, k = 1, b = 1, bb = 1;
    cin >> n;
    while (n >= k) {
        c = (b + bb) % 10;
        b = bb;
        bb = c;
        k++;
    }
    cout << b;
    return 0;
}