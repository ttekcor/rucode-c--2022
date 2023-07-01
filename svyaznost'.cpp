#include <iostream>
#include <vector>

void dfs(int u, std::vector<std::vector<int>>& g, std::vector<bool>& used) 
{
    used[u] = true;
    for (auto& v : g[u]) {
        if (!used[v]) {
            dfs(v, g, used);
        }
    }
}

int main()
{
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
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        std::vector<bool> used(n, false);
        dfs(i, g, used);
        for (auto x : used) {
            if (!x) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    if (flag) {
        std::cout << "NO" << "\n";
    } else {
        std::cout << "YES" << "\n";
    }
    return 0;
}





