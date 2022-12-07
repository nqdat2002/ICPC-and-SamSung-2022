#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b, c, d, n, ans = 0;
	cin >> n >> a >> b >> c;
	int d = b - c;
	if (a <= d)
		ans = n / a;
	else {
		ans = (n - b) / d + 1;
		n -= ans * d;
		ans += n / a;
	}
	cout << ans << endl;
	return 0;
}