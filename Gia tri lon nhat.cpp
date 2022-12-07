#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x >= 0) res += x;
	}
	cout << res * 2  << endl;
	return 0;
}