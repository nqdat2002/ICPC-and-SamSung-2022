#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int x; cin >> x;
	vector<ll> a(x);
	for (int i = 0; i < x; ++i) cin >> a[i];
	ll res = 0, l = 0;
	set<pair<ll, ll> > s;
	for (int i = 0; i < x; ++i) {
		if (s.size() < 2) s.insert({a[i], i});
		else {
			ll m = s.begin()->first;
			ll n = s.rbegin()->first;
			if (s.size() == 2) {
				if (a[i] > n) {
					if (n + m <= a[i]) {
						s.erase({a[l], l});
						l++;
					}
				}
				else {
					if (m + a[i] <= n) {
						s.erase({a[l], l});
						l++;
					}
				}
			}
			while (s.size() > 1) {
				auto it = s.begin();
				++it;
				if (it->first + s.begin()->first <= a[i] || s.begin()->first + a[i] <= s.rbegin()->first) {
					s.erase({a[l], l});
					l++;
				}
				else break;
			}
			s.insert({a[i], i});
			if (s.size() > 2) res = max(res, (ll)s.size());
		}
	}
	cout << res << endl;
	return 0;
}


