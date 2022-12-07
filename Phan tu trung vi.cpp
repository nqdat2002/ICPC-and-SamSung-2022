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
const int N = 1000000;
int tree[N * 4 + 1];

void update(int id, int l, int r, int x, int diff) {
    if (l == r && l == x) {
        tree[id] += diff;
        return ;
    }
    if (x >= l && x <= r) {
        int m = (l + r) >> 1;
        update(id * 2, l, m, x, diff);
        update(id * 2 + 1, m + 1, r, x, diff);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
}

int get(int id, int l, int r, int k) {
    if (l != r) {
        int m = (l + r) >> 1;
        if (tree[id * 2] >= k)
            return get(id * 2, l, m, k);
        return get(id * 2 + 1, m + 1, r, k - tree[id * 2]);
    }
    return (tree[id]) ? l : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q; cin >> q;
    while (q--) {
        string type; cin >> type;
        if (type == "add") {
            int x; cin >> x;
            update(1, 0, N, x, 1);
        }
        else if (type == "del") {
            int x; cin >> x;
            update(1, 0, N, x, -1);
        }
        else if (type == "print") {
            int k = (tree[1] + 1) >> 1;
            cout << get(1, 0, N, k) << endl;
        }
    }
    return 0;
}