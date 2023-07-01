#include <bits/stdc++.h>
#define int int64_t

using namespace std;

const int N = 1e3 + 2;

int n, m;
array<array<int, N>, N> d;
array<array<int, N>, N> g;

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (!g[x - 1][y] && d[x - 1][y] > d[x][y] + 1)
        {
            d[x - 1][y] = d[x][y] + 1;
            q.emplace(x - 1, y);
        }
        if (!g[x + 1][y] && d[x + 1][y] > d[x][y] + 1)
        {
            d[x + 1][y] = d[x][y] + 1;
            q.emplace(x + 1, y);
        }
        if (!g[x][y - 1] && d[x][y - 1] > d[x][y] + 1)
        {
            d[x][y - 1] = d[x][y] + 1;
            q.emplace(x, y - 1);
        }
        if (!g[x][y + 1] && d[x][y + 1] > d[x][y] + 1)
        {
            d[x][y + 1] = d[x][y] + 1;
            q.emplace(x, y + 1);
        }
    }
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                g[i][j] = 1;
            else
                cin >> g[i][j];
            d[i][j] = numeric_limits<int>::max();
        }
    }
    pair<int, int> s, f;
    cin >> s.second >> s.first >> f.second >> f.first;
    d[s.first][s.second] = 0;
    bfs(s.first, s.second);
    cout << (d[f.first][f.second] == numeric_limits<int>::max() ? -1 : d[f.first][f.second]);
}