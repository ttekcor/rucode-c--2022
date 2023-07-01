#include <iostream> 
using namespace std; 

using l = long long;

l gcd(l a, l b, l &x, l &y)
{ 
    if (b == 0)
    { 
        x = 1; 
        y = 0; 
        return a; 
    } 
    
    l g = gcd(b, a % b, x, y); 
    x = x - (a / b) * y; 
    swap(x, y); 
    return g; 
} 


void solve(l &a, l &b, l &c, l &x, l &y)
{ 
    l g = gcd(a, b, x, y); 
    if (c % g != 0)
    { 
        cout << 0 << " " << 0 << "\n"; 
        return; 
    } 
    l k0 = x * c / g; 
    l k1 = b / g; 
    l xi, yi; 
    if (k0 > 0)
    { 
        xi = k0 - k1 * (k0 / k1); 
        yi = y * c / g + a / g * (k0 / k1); 
    } 
    else if (k0 == 0)
    { 
        xi = 0; 
        yi = y * c / g; 
    } 
    else 
    { 
        xi = k0 - k1 * ((k0 - k1 + 1) / k1); 
        yi = y * c / g + a / g * ((k0 - k1 + 1)/ k1); 
    } 
    cout << xi << " " << yi << "\n"; 
} 
 
 
int main()
{ 
    int n; 
    cin >> n; 
    for (int i = 0; i < n; ++i)
    { 
        l a, b, c, x, y, g; 
        cin >> a >> b >> c; 
        solve(a, b, c, x, y); 
    } 
}