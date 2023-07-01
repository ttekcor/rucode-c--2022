#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 1;

int n;
array<int, N> dist;
array<vector<int>, N> g;

void dfs(int v, int p = -1, int d = 0)
{
    dist[v] = d;
    for (auto u : g[v])
    {
        if (u != p) 
        {
            dfs(u, v, d + 1);
        }
    }
}

int32_t main()
{
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    int s = max_element(dist.begin(), dist.end()) - dist.begin();
    fill(dist.begin(), dist.end(), 0);
    dfs(s);
    int f = max_element(dist.begin(), dist.end()) - dist.begin();
    cout << dist[f] + 1;
}