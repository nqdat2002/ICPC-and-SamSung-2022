#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i) cin >> a[i];
	int minnn = a[n - 1];
	int res = a[n - 2] - a[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		res = max(res, a[i] - minnn);
		minnn = min(minnn, a[i]);
	}
	cout << res << endl;
	return 0;
}