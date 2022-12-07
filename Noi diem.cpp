#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;

const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
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

double cost[105][105];
int n;
double ans = 0;
bool mark[105];

struct Edge {
    int u, v;
    double cost;
    Edge() {}
    Edge(int U, int V, double C) {
        u = U;
        v = V;
        cost = C;
    }
};

vector <Edge> edge;
int par[105];

double dist(pair < double, double > a, pair < double, double > b) {
    return sqrt((a.first - b.first) * (a.first - b.first)
                + (a.second - b.second) * (a.second - b.second));
}

bool cmp(Edge u, Edge v) {
    return u.cost < v.cost;
}

int root(int x) {
    while (par[x] > 0)
        x = par[x];

    return x;
}

void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
        return;

    if (par[x] < par[y]) {
        par[x] += par[y];
        par[y] = x;
    }

    else {
        par[y] += par[x];
        par[x] = y;
    }
}

void kruskal() {
    sort(edge.begin(), edge.end(), cmp);
    for (int i = 0; i < edge.size(); i++) {
        int u = root(edge[i].u);
        int v = root(edge[i].v);
        if (u != v) {
            merge(u, v);
            ans += edge[i].cost;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        memset(par, -1, sizeof(par));
        vector < pair < double, double > > a(n + 5);
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;

        edge.clear();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cost[i][j] = dist(a[i], a[j]);
                edge.push_back(Edge(i, j, cost[i][j]));
            }
        }

        ans = 0;
        kruskal();
        cout << fixed << setprecision(6) << ans << '\n';
    }
    return 0;
}