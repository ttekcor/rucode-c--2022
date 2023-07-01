#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <set> 
#include <string> 
 
using namespace std; 
using l = long long;


int main()
{ 
    l a, b; 
    cin >> a >> b; 
 
    vector<bool> prime ((l)ceil(sqrt(b))+1, true); 
    prime[0] = false; 
    prime[1] = false; 
    vector<bool> prime1 (b-a+1, true); 
    if (a == 1) prime1[0] = false; 
    for (l i=2; i <= (l)ceil(sqrt(b)); ++i) 
        if (prime[i]) 
            if (i <= (l)ceil(sqrt(b)))
            { 
                for (l j = i * i; j <= (l) ceil(sqrt(b)); j += i)
                    if (j < prime.size()) prime[j] = false; 
                l p = a % i; 
                l begin = 1ll*i*i >= a ? 1ll*i*i : (p == 0 ? a : a + (i - p)); 
                for (l j=begin; j <= b; j+=i) 
                    prime1[j - a] = false; 
 
            } 
 
 
    for (l i = a; i <= b; i++)
    { 
        if (prime1[i-a]) 
            cout << i << " "; 
    } 
}
