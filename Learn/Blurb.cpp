#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	set<int> s;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		if(s.insert(x).second) cout << 0 << " ";
		else cout << 1 << " ";
	}
	return 0;
}