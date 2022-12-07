#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

class DSU {
private:
    int cur_time;
    vector<int> parent;
    vector<int> time;
    vector<int> len;
public:
    DSU(const int size)
        : cur_time(0)
        , parent(size + 1)
        , time(size + 1, 0)
        , len(size + 1, 1)
    {
        for (int i = 0; i <= size; ++i) parent[i] = i;
    }

    inline int getTime() const {
        return cur_time;
    }

    inline int Find(int u, const int last_time) const {
        while (time[u] <= last_time && u != parent[u])
            u = parent[u];
        return u;
    }

    inline int Find(const int u) const {
        return Find(u, getTime());
    }

    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (len[u] > len[v])
            swap(u, v);
        if (u != v) {
            cur_time += 1;
            parent[u] = v;
            time[u] = cur_time;
            len[v] += len[u];
        }
    }

    bool same(const int u, const int v) const {
        return Find(u) == Find(v);
    }

    bool same(const int u, const int v, const int last_time) const {
        return Find(u, last_time) == Find(v, last_time);
    }

    inline int Find_time(int u, int v) const {
        int ans = -1;
        int l = 0, r = getTime();
        while (l <= r) {
            const int m = (l + r) >> 1;
            if (same(u, v, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }


    int getSize(const int u) const {
        return len[Find(u)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n);
    map<int, int> mp;
    mp[dsu.getTime()] = 0;
    for (int day = m; day >= 1; --day) {
        for (int i = 2; i * day <= n; ++i) {
            dsu.Union(day, i * day);
            mp[dsu.getTime()] = m - day + 1;
        }
    }
    while (q--) {
        int u, v; cin >> u >> v;
        int t = dsu.Find_time(u, v);
        cout << mp[t] << endl;
    }
    return 0;
}