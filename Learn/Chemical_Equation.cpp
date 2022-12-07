#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, lf, p;
	string eq, s, st;
	cin >> n;
	vector<int> f(26, 0);

	for (int t = 0; t < n; ++t) {
		for (int &i : f) i = 0;
		cin >> eq;
		lf = 1;
		p = eq.find('-');
		s = eq.substr(0, p) + '+';
		auto get_idx = [&]() {
			int coef, q = 0, r = 0, m;
			st = "1";
			auto get_term=[&](){
				st = "";
				if (r + 1 - s.size() == 0) return;
				r = s.find('+', q);
				st = s.substr(q, r - q);
				q = r + 1;
			};
			while (st != "") {
				get_term();
				if (st == "") return;
				m = 0; coef = 1;
				if (st[0] < 65) coef = st[0] - 48;
				for (size_t i = m; i < st.size(); ++i){
					if (st[i] < 65)
						f[st[i - 1] - 65] += (coef * (st[i] - 48) - coef) * lf;
					else 
						f[st[i] - 65] += lf * coef; 
				}
			}
		};
		get_idx();
		lf = -1;
		s = eq.substr(p + 2) + '+';
		get_idx();
		string ans = "Yes";
		for (int i : f) {
			if (i) {
				ans = "No";
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}