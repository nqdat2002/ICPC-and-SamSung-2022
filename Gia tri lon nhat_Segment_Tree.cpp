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

const int N = 1e5 + 5;
struct Node {
	int lazy;
	int val;
} nodes[N * 4];

void down(int id) {
	int t = nodes[id].lazy;
	nodes[id * 2].lazy += t;
	nodes[id * 2].val += t;

	nodes[id * 2 + 1].lazy += t;
	nodes[id * 2 + 1].val += t;

	nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
	if (v < l || r < u) {
		return ;
	}
	if (u <= l && r <= v) {
		nodes[id].val += val;
		nodes[id].lazy += val;
		return ;
	}
	int mid = (l + r) >> 1;
	down(id);

	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);

	nodes[id].val = max(nodes[id * 2].val, nodes[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v) {
	if (v < l || r < u) {
		return -oo;
	}
	if (u <= l && r <= v) {
		return nodes[id].val;
	}
	int mid = (l + r) >> 1;
	down(id);

	return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, q; cin >> n >> m;
	while (m --) {
		int u, v, val;
		cin >> u >> v >> val;
		update(1, 1, n, u, v, val);
	}
	cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		cout << get(1, 1, n, u, v) << endl;
	}
	return 0;
}