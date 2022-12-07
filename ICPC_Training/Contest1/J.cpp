#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 3;
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

const int N = 1e5 + 5;
struct node {
    ll len, val;
};
int n, m;
int a[N];
node tree[4 * N];
ll lazy[4 * N], sum[N], Power[N];

node merge(node x, node y) {
    node res;
    res.len = x.len + y.len;
    res.val = (x.val * Power[y.len] + y.val) % mod;
    return res;
}

void buildTree(int u, int l, int r) {
    if (l == r) {
        tree[u].val = a[l];
        tree[u].len = 1;
    }
    else {
        int m = (l + r) >> 1;
        buildTree(2 * u, l, m);
        buildTree(2 * u + 1, m + 1, r);
        tree[u] = merge(tree[u * 2], tree[u * 2 + 1]);
    }
}

void update(int u, int l, int r, int L, int R, int v) {
    if (lazy[u] != -1) {
        tree[u].val = sum[tree[u].len] * lazy[u];
        if (l != r) {
            lazy[u * 2] = lazy[u];
            lazy[u * 2 + 1] = lazy[u];
        }
        lazy[u] = -1;
    }
    if (r < L || l > R)
        return;
    if (L <= l && r <= R) {
        tree[u].val = sum[tree[u].len] * v;
        if (l != r) {
            lazy[u * 2] = v;
            lazy[u * 2 + 1] = v;
        }
        return;
    }
    int m = (l + r) >> 1;
    update(u * 2, l, m, L, R, v);
    update(u * 2 + 1, m + 1, r, L, R, v);
    tree[u] = merge(tree[u * 2], tree[u * 2 + 1]);
}

node get(int u, int l, int r, int L, int R) {
    int m = (l + r) >> 1;
    if (l > R || r < L) {
        node res;
        res.val = 0;
        res.len = 0;
        return res;
    }
    if (lazy[u] != -1)
    {
        tree[u].val = sum[tree[u].len] * lazy[u];
        if (l != r)
        {
            lazy[u * 2] = lazy[u];
            lazy[u * 2 + 1] = lazy[u];
        }
        lazy[u] = -1;
    }
    if (l >= L && r <= R)
        return tree[u];
    node x = get(u * 2, l, m, L, R);
    node y = get(u * 2 + 1, m + 1, r, L, R);
    return merge(x, y);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    sum[0] = 0;
    Power[0] = 1;
    for (int i = 1; i <= n; i++) {
        Power[i] = (Power[i - 1] * 10) % mod;
        sum[i] = (sum[i - 1] + Power[i - 1]) % mod;
    }
    memset(lazy, -1, sizeof(lazy));
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }
    buildTree(1, 1, n);
    while (m--) {
        int q, L, R, x;
        cin >> q >> L >> R >> x;
        if (q == 1)
            update(1, 1, n, L, R, x);
        else {
            node A = get(1, 1, n, L, R - x);
            node B = get(1, 1, n, L + x, R);
            if (A.val == B.val) cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
    return 0;
}