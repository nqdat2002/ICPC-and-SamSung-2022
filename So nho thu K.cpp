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

typedef vector<int> data;

const int N = 1e5 + 5;
int n, q, a[N], res, cnt;
bool found;
data tree[4 * N], nil;

/* combine 2 child nodes (increasing vector) to the parent node (increasing vector) */
data merge(data u, data v) {
	data ans = nil;
	int i = 0, j = 0;
	while (i < sz(u) && j < sz(v)) {
		if (u[i] < v[j]) ans.push_back(u[i++]);
		else ans.push_back(v[j++]);
	}
	while (i < sz(u)) ans.push_back(u[i++]);
	while (j < sz(v)) ans.push_back(v[j++]);
	return ans;
}

void build(int id, int l, int r) {
	if (l == r) {
		tree[id].push_back(a[l]);
		return ;
	}
	int m = (l + r) >> 1;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
}

void update(int id, int l, int r, int L, int R) {
	if (r < L || R < l) return ;
	if (L <= l && r <= R) {
		int i = 0, j = sz(tree[id]) - 1, pos = -1;
		while (i <= j) {
			int m = (i + j) >> 1;
			if (tree[id][m] <= res) {
				pos = m;
				i = m + 1;
			} else j = m - 1;
		}
		if (pos == -1) return ;
		cnt += pos + 1;
		if (tree[id][pos] == res) found = true, cnt--;
		return ;
	}
	int m = (l + r) >> 1;
	update(id * 2, l, m, L, R);
	update(id * 2 + 1, m + 1, r, L, R);
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(1, 1, n);

	while (q--) {
		int L, R, k; cin >> L >> R >> k;
		int l = 0, r = sz(tree[1]) - 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			cnt = 0;
			found = false;
			res = tree[1][m];
			update(1, 1, n, L, R);
			if (cnt == k - 1 && found) {
				cout << res << endl;
				break;
			}
			if (cnt < k) l = m + 1;
			else r = m - 1;
		}
	}
	return 0;
}
