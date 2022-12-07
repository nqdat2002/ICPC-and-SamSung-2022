#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// typedef unsigned long long ull;
// typedef long double ld;
// typedef pair<int, int> p;
// typedef vector<vector<int> > vt;
// typedef vector<pair<int, int> > vp;
// const int oo = 1e6 + 7;

// #define f first
// #define s second
// #define pb push_back
// #define ep emplace_back
#define mp make_pair
// #define sz(a) (int) a.size()
// #define ms(s, n) memset(s, n, sizeof(s))
// #define present(t, x) (t.find(x) != t.end())
// #define all(a) (a.begin(), a.end())
// #define For(i, l, r) for (int i = l; i <= r; i++)
// #define Fod(i, r, l) for (int i = r; i >= l; i--)
// #define fillchar(a, x) memset(a, x, sizeof (a))
// #define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// void FileIO() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// }

const int nmax = 100010;
ll parent[nmax], superparent[nmax], level[nmax], n, part;
int visited[nmax];
pair<ll, ll> ligaparent[nmax], ligasuperparent[nmax];
vector<pair<ll, ll> > adj[nmax];

void dfs_parent(int u) {
    for (size_t i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        if (parent[v] == -1) {
            parent[v] = u;
            ligaparent[v] = mp(adj[u][i].second, adj[u][i].second);
            level[v] = level[u] + 1;
            dfs_parent(v);
        }
    }
}

void dfs_superparent(int u, int p) {
    superparent[u] = p;
    if (level[u] % part == 0) {
        p = u;
        visited[u] = true;
    }
    for (size_t i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        if (superparent[v] == -1)
            dfs_superparent(v, p);
    }
}

pair<ll, ll> LCA(int u, int v) {
    ll resMax = -1, resMin = 1e9 + 1;
    while (superparent[u] != superparent[v]) {
        if (level[u] > level[v]) {
            if (!visited[u]) {
                resMin = min(ligaparent[u].first, resMin);
                resMax = max(ligaparent[u].second, resMax);
                u = parent[u];
            } else {
                resMin = min(ligasuperparent[u].first, resMin);
                resMax = max(ligasuperparent[u].second, resMax);
                u = superparent[u];
            }
        } else {
            if (!visited[v]) {
                resMin = min(ligaparent[v].first, resMin);
                resMax = max(ligaparent[v].second, resMax);
                v = parent[v];
            } else {
                resMin = min(ligasuperparent[v].first, resMin);
                resMax = max(ligasuperparent[v].second, resMax);
                v = superparent[v];
            }
        }
    }
    while (u != v) {
        if (level[u] > level[v]) {
            resMin = min(ligaparent[u].first, resMin);
            resMax = max(ligaparent[u].second, resMax);
            u = parent[u];
        } else {
            resMin = min(ligaparent[v].first, resMin);
            resMax = max(ligaparent[v].second, resMax);
            v = parent[v];
        }
    }
    return mp(resMin, resMax);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //        freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    // #endif
    int t; cin >> t;
    while(t--){
        cin >> n;
        part = 1;
        for (int i = 0; i < nmax; i++) {
            parent[i] = superparent[i] = -1;
            ligaparent[i] = mp(0, 0);
            ligasuperparent[i] = mp(0, 0);
            adj[i].clear();
        }
        memset (visited, 0, sizeof(visited));
        memset (level, 0, sizeof(level));
        for (int i = 1; i < n; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back(mp(v, w));
            adj[v].push_back(mp(u, w));
        }
        level[1] = 0;
        parent[1] = 1;
        superparent[1] = 1;
        ligaparent[1] = mp(1e9 + 1, -1);
        dfs_parent(1);
        for (int i = 1; i <= n; i++) part = max(part, level[i]);
        part = (ll)sqrt(part);
        dfs_superparent(1, 1);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) continue;
            int v = superparent[i];
            ll resMin = 1e9 + 1, resMax = -1;
            int u = i;
            while (u != v) {
                resMin = min(ligaparent[u].first, resMin);
                resMax = max(ligaparent[u].second, resMax);
                u = parent[u];
            }
            ligasuperparent[i] = mp(resMin, resMax);
        }
        int q; cin >> q;
        while (q--) {
            int u, v; cin >> u >> v;
            pair<ll, ll> resp = LCA(u, v);
            cout << resp.first << " " << resp.second << endl;
        }
    }
    return 0;
}