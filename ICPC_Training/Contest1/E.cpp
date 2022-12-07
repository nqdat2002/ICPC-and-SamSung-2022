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

//_______________________NGUYỄN_NGỌC_TOÀN_______________________//

int main() {
	faster();
	int n; cin >> n;
	v(ll) M(n);
	ll a, b, c, d, e;
	cin(M, n);
	pq(ll) S,F;
	neg_pq(ll) X;

	for (int i = 0; i < n; i++) {
		if (M[i] >= 0)
			S.push(M[i]);
		else X.push(M[i]),F.push(M[i]);
		if (i < 2)cout << 0 << " ";
		else if (i == 2) {
			cout << M[0]*M[1]*M[2] << " ";
		}
		else {
			if (sz(X) <= 1) {
				a = S.top();
				S.pop();
				b = S.top();
				S.pop();
				c = S.top();
				S.pop();
				cout << a*b*c << " ";
				S.push(a);
				S.push(b);
				S.push(c);
			}
			else if (sz(S) == 0) {
				a = F.top();
				F.pop();
				b = F.top();
				F.pop();
				c = F.top();
				F.pop();
				cout << a*b*c << " ";
				F.push(a);
				F.push(b);
				F.push(c);
			}
			else if (sz(S) == 1 || (sz(S) == 2)) {
				a = S.top();
				S.pop();
				b = X.top();
				X.pop();
				c = X.top();
				X.pop();
				cout << a*b*c << " ";
				S.push(a);
				X.push(b);
				X.push(c);
			}
			else if (sz(X) >= 2 && sz(S) >= 3) {
				a = X.top();
				X.pop();
				b = X.top();
				X.pop();
				c = S.top();
				S.pop();
				d = S.top();
				S.pop();
				e = S.top();
				S.pop();
				ll g = a * b * c;
				ll h = c * d * e;
				cout << max(g, h) << " ";
				X.push(a);
				X.push(b);
				S.push(c);
				S.push(d);
				S.push(e);
			}
		}


	}


}

//__________________________B20DCPT173__________________________//