#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	ll t = __gcd(a.second, b.second);
	t = (a.second * b.second) / t;
	return a.first * (t / a.second) >= b.first * (t / b.second);
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n; cin >> n;
	ll a[n];
	for (auto &x : a) cin >> x;
	multiset<ll> ms;
	vector<pair<pair<ll, ll>, ll> > v;
	pair<ll, ll> p = make_pair(0, 1);
	ll sum = a[n - 1];
	for (ll i = n - 2; i > 0; --i) {
		sum += a[i];
		ms.insert(a[i]);
		pair<ll, ll> tmp;
		tmp.first = (sum - *ms.begin());
		tmp.second = (n - i - 1);
		ll t = __gcd(tmp.first, tmp.second);
		tmp.first /= t;
		tmp.second /= t;
		if (cmp(tmp, p)) {
			v.push_back({tmp, i});
			p = tmp;
		}
	}
	ll l = v.size() - 1;
	while (l >= 0 && cmp(v[l].first, p)) {
		cout << v[l].second << " ";
		l --;
	}
	return 0;
}
