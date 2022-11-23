#include <iostream>
#include <math.h>
#include <vector>

using namespace std;




int main()
{
    long double a;
    vector<long long int> r;
    vector<long long int> res;
    long double max = pow(2, 64);
    while (cin >> a)
    {
        res.push_back(a);
    }
    for (int i = 0; i < res.size(); i++)
    {

        if (res[i] >= 0 && res[i] <= max)
        {
            int n = pow(res[i], 0.5);

            if ((n * n) > res[i])
            {
                n -= 1;
        
            }
           
                r.push_back(n);
            

        }
    }
    for (auto& k : r)
    {
        cout << k << endl;
    }

    return 0;
}