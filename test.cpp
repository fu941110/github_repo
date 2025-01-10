#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 100005;

vector<int> g[MAXN];

int n, m;

bool vis[MAXN];

int dfs(int u) {
    vis[u] = true;
    int cnt = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            cnt += dfs(v);
        }
    }
    return cnt;
}

    int main() {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans = max(ans, dfs(i));
            }
        }
        cout << ans << endl;
        return 0;
    }
    