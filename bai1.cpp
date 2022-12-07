#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1000005;
int prime[nmax];
void Prime() {
	for (int i = 0; i < nmax; ++i) prime[i] = i;
	for (int i = 2; i <= sqrt(nmax); ++i) {
		if (prime[i] == i) {
			for (int j = i * i; j < nmax; j += i) {
				if (prime[j] == j)
					prime[j] = i;
			}
		}
	}
}


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	Prime();

	while (t--) {
		ll m; cin >> m;
		ll ans = 1, res = 1;
		map<int, int> mp;
		ll n = m;
		while (n > 1) {
			mp[prime[n]] ++;
			n /= prime[n];
		}
		n = m + 1;
		while (n > 1) {
			mp[prime[n]] ++;
			n /= prime[n];
		}
		n = m + 2;
		while (n > 1) {
			mp[prime[n]] ++;
			n /= prime[n];
		}

		for (auto it : mp) {
			res *= (it.second + 1);
			ans *= (it.second * 2 + 1);
		}
		cout << (ans + 1) / 2 - res << endl;
	}
	return 0;
}