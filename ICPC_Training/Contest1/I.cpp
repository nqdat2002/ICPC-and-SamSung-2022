#include<bits/stdc++.h>
#define mod                 1000000007
#define ll                  long long
#define	p(x)                pair<x,x>
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

int main() {
	faster();
	run() {
		int dp[105][105];
		for (int i = 0; i < 105; i++)for (int j = 0; j < 105; j++)dp[i][j] = 0;
		int l, n; cin >> l >> n;
		v(int) M(n);
		M.push_back(0);
		for (int i = 1; i <= n; i++)cin >> M[i];
		M.push_back(l);
		n += 2;
		for (int l = 2; l < n; l++) {
			for (int i = 0; i < n - l; i++) {
				int a = INT_MAX;
				for (int j = i + 1; j < i + l; j++) {
					a = min(a, dp[i][j] + dp[j][i + l]);
				}
				if (a != INT_MAX)dp[i][i + l] += M[i + l] - M[i] + a;
			}

		}
		cout << dp[0][n - 1] << endl;
	}

}
