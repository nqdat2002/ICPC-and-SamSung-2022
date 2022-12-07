#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005];
int c[1005], n, m;
bool chuaxet[1005], check;
void dfs(int u, int t) {
    chuaxet[u] = false;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (chuaxet[v]) {
            if (c[v] == 0)
                c[v] = 3 - c[u];
            dfs(v, u);
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        for (int i = 1; i <= 1005; i++)
            a[i].clear();
        memset(c, 0, sizeof(c));
        memset(chuaxet, true, sizeof(chuaxet));
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (c[i] == 0) {
                c[i] = 1;
                dfs(i, 0);
            }
        }
        check = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                if (c[i] == c[a[i][j]])
                    check = false;
            }
        }
        cout << ((check) ? "YES" : "NO") << endl;
    }
    return 0;
}