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

struct mqh {
	string cha, con;
	int tuoi;
};
int n;
vector<pair<string, int> > res;
void Try(string s, int x, vector<mqh> a) {
	res.push_back({ s, x });
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s == a[i].cha) {
			Try(a[i].con, x - a[i].tuoi, a);
			cnt++;
		}
	}
	if (cnt == 0) return;
}

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.s == b.s)
		return a.f < b.f;
	return a.s > b.s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	for (int j = 1; j <= t; j ++) {
		cin >> n;
		res.clear();
		vector<mqh> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].cha >> a[i].con >> a[i].tuoi;
		}
		Try("Ted", 100, a);
		sort(res.begin(), res.end(), cmp);
		cout << "DATASET " << j << endl;
		int l = res.size();
		for (int i = 1; i < l; i++) {
			cout << res[i].f << " " << res[i].s << endl;
		}
	}
	return 0;
}