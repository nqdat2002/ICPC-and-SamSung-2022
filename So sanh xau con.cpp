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

int M[257][50000];
int a, b, c, d;
bool Ktra() {
	for (int i = 1; i < 257; i++) {

		if (M[i][b] - M[i][a - 1] != M[i][d] - M[i][c - 1])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s; cin >> s;
	for (int i = 0; i < 257; i++) {
		for (int j = 0; j < s.length(); j++)
			M[i][j] = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		M[s[i]][i] = 1;
	}
	for (int i = 1; i < 257; i++) {
		for (int j = 1; j <= s.length(); j++) {
			M[i][j] += M[i][j - 1];
		}
	}
	int t; cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		if (Ktra())cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}