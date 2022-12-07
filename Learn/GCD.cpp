#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

int n, k, p, q;
vector<ll> a;
ll res = 0, x;

void update(int id, ll val) {
	int u = p + id;
	a[u] = val;
	u >>= 1;
	while (u > 0) {
		a[u] = __gcd(a[u << 1], a[u << 1 | 1]);
		u >>= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FileIO();
	cin >> n >> k;
	for (int i = 20; i >= 0; --i) {
		if ((k >> i) & 1) {
			p = 1 << i;
			break;
		}
	}
	if ((k & (-k)) != k) p <<= 1;
	a.assign(4 * k + 5, 0);
	for (int i = 0; i < k; ++i)
		cin >> a[p + i];
	for (int i = p - 1; i > 0; --i)
		a[i] = __gcd(a[i << 1], a[i << 1 | 1]);
	res = a[1];
	for (int i = k; i < n; ++i) {
		cin >> x;
		update(i % k, x);
		res = max(res, a[1]);
	}
	cout << res << endl;
	return 0;
}