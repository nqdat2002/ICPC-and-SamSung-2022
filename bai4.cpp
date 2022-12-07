#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	ll k; cin >> k;

	deque<ll> dq;
	ll l = s.size();
	for (int i = 0; i < l; ++i) {
		while (!dq.empty() && k > 0 && s[dq.back()] < s[i]) {
			s[dq.back()] = '#';
			k --;
			dq.pop_back();
		}
		dq.push_back(i);
	}

	while (k > 0 && !dq.empty()) {
		s[dq.back()] = '#';
		dq.pop_back();
		k --;
	}
	for (int i = 0; i < l; ++i) {
		if (s[i] != '#') cout << s[i];
	}
	cout << endl;
	return 0;
}