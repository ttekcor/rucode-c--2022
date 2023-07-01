#include <iostream>
#include <vector>

void dfs(int v, std::vector<std::vector<int>>& g, std::vector<bool>& used, 
std::vector<int>& colors, int cnt)
{
    used[v] = true;
    colors[v] = cnt;
    for (auto& u : g[v]) {
        if (!used[u]) {
            dfs(u, g, used, colors, cnt);
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g = std::vector<std::vector<int>>(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    std::vector<bool> used(n, false);
    std::vector<int> colors(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cnt++;
            dfs(i, g, used, colors, cnt);
        }
    }
    std::cout << cnt << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << colors[i] << " ";
    }
    return 0;
}
