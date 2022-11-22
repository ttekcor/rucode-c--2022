#include <iostream>
using namespace std;
int main()
{
    int N, K, x;
    cin >> N >> K;
    int array[N];
    for (int i = 0; i < N; i++)
        cin >> array[i];
    for (int h = 0; h < K; h++)
    {
        cin >> x;
        int L = 0;
        int R = N;
        while (L < R)
        {
            int M = L + (R-L) / 2;
            if (array[M] >= x)
                R = M;
            else
                L = M + 1;
        }

        if (array[L]==x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
} 