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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int  n, m; cin >> n >> m;
	int y1, y2; cin >> y1 >> y2;
	int s1[500005], s2[500005];
	for (int i = 0; i < n; i++) cin >> s1[i];
	for (int i = 0; i < m; i++) cin >> s2[i];
	sort(s1, s1 + n);
	sort(s2, s2 + m);
	int y = abs(y1 - y2);
	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		int z = lower_bound(s2, s2 + m, s1[i]) - s2;
		if (z >= 0)
			a.push_back(abs(s2[z] - s1[i]));
	}
	for (int i = 0; i < m; i++) {
		int z = upper_bound(s1, s1 + n, s2[i]) - s1;
		if (z >= 0)
			b.push_back(abs(s1[z] - s2[i]));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int mz = min(a[0], b[0]);
	int res = 0;
	for (size_t i = 0; i < a.size(); i++) {
		if (mz == a[i]) res++;
		else break;
	}
	for (size_t i = 0; i < b.size(); i++) {
		if (mz == b[i]) res++;
		else break;
	}
	cout << mz + y << " " << res << endl;
	return 0;
}