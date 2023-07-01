#include <iostream> 
#include <vector> 
 
using namespace std; 
 
 
vector<int> foo(int n)
{ 
    vector<int> p(n + 1, 1); 
    for (int i = 2; i <= n; ++i){ 
        if (p[i] == 1){ 
            for (int j = 2 * i ; j <= n; j += i){ 
                p[j] += 1; 
            } 
        } 
    } 
    return p; 
} 
 
int main() { 
    int n; 
    cin >> n; 
    auto result = foo(n); 
    for (auto i = 0; i <= n; ++i){ 
        if (result[i] >= 4){ 
            cout << i << " "; 
        } 
    } 
    return 0; 
}