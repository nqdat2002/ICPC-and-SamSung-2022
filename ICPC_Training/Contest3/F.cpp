#include<bits/stdc++.h>
#define mod                 1000000007
#define ll                  long long
#define v(x)                vector<x>
#define Tree                node*
#define sz(a)               a.size()
#define x                   first
#define y                   second
#define pb(a)               push_back(a)
#define pf(a)               push_front(a)
#define FOR(i, l, r)        for (int i = l; i < r; i++)
#define FORX(i, l, r, x)    for (int i = l; i < r; i += x)
#define FORD(i, l, r)       for (int i = l; i >= r; i--)
#define correct(x, y, n, m) 0 <= (x)&&(x) < (n)& & 0 <= (y)&&(y) < (m)
#define cin(M, n)           FOR(i, 0, n)cin >> M[i]
#define cout(M, n)          FOR(i, 0, n)cout << M[i] << " "
#define rs(M, x)            memset(M, x, sizeof(M))
#define reset()             FOR(i, 0, 1001)A[i].clear(), check[i] = false
#define faster()            cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()               int t; cin >> t; while (t--)
#define pq(x)               priority_queue<x>
#define neg_pq(x)           priority_queue<x, vector<x>, greater<x>>
#define all(M)              M.begin(), M.end()
using namespace std;

//_______________________NGUYỄN_NGỌC_TOÀN_______________________//

int main() {
	faster();
	int n, l, h; cin >> n >> l >> h;
	v(int) p(n), h1(n), h2(n);
	for (int i = 0; i < n; i++) cin >> p[i] >> h1[i] >> h2[i];
	ll res = l - p[n - 1] - 1;
	for (int i = n - 1; i >= 0;) {
		bool ok = true;
		for (int j = i - 1; j >= 0; j--) {
			if (h1[i] + h2[j] >= h || h2[i] + h1[j] >= h) {
				if (h1[i] + h2[j] >= h) {
					res += h1[i] + h2[j] - h + 1;
					if (j > 0 && h2[j] < h2[j - 1] && h1[j] + h2[j - 1] < h)
						res += h2[j - 1] - h2[j];
				}
				if (h2[i] + h1[j] >= h) {
					res += h2[i] + h1[j] - h + 1;
					if (j > 0 && h1[j] < h1[j - 1] && h2[j] + h1[j - 1] < h)
						res += h1[j - 1] - h1[j];

				}
				res += p[i] - p[j];
				i = j;
				ok = false;
				break;
			}
		}
		if (ok == true) {
			res += p[i] + 1;
			break;
		}
	}
	cout << res << endl;
}