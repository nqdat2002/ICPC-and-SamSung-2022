#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<vector<int> > type, ls;

void init() {
	ls = {
		{0, 0},
		{1, 2, 1},
		{3, 4, 5, 3},
		{6, 7, 8, 9, 6}
	};
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			int x = ls[i][j], y = ls[i][j + 1];
			for (int k = 0; k < i; ++k)
				type.push_back({ls[i - 1][k], y, x});
			if (i != n - 1) {
				for (int k = 0; k <= i + 1; ++k) type.push_back({x, y, ls[i + 1][k]});
			}

		}
	}
}

void clean(string &s) {
	if (n >= 2) {
		if (s[2] > s[1]) swap(s[2], s[1]);
	}

	if (n >= 3) {
		if (s[4] < s[3] && s[4] < s[5]) {
			// 3 4 5
			// 4 5 3
			char c = s[4];
			s[4] = s[5];
			s[5] = s[3];
			s[3] = c;
		}
		else if (s[5] < s[3] && s[5] < s[4]) {
			// 3 4 5
			// 5 3 4
			char c = s[3];
			s[3] = s[5];
			s[5] = s[4];
			s[4] = c;
		}
	}

	if (n >= 4) {
		if (s[7] < s[6] && s[7] < s[8] && s[7] < s[9]) {
			char c = s[6];
			s[6] = s[7];
			s[7] = s[8];
			s[8] = s[9];
			s[9] = c;
		}

		else if (s[8] < s[6] && s[8] < s[7] && s[8] < s[9]) {
			swap(s[6], s[8]);
			swap(s[7], s[9]);
		}

		else if (s[9] < s[8] && s[9] < s[7] && s[9] < s[6]) {
			char c = s[6];
			s[6] = s[9];
			s[9] = s[8];
			s[8] = s[7];
			s[7] = c;
		}
	}
}

string rotate(const string &s, int p1, int p2, int p3) {
	string res = s;
	res[p1] = s[p3];
	res[p2] = s[p1];
	res[p3] = s[p2];
	return res;
}

void Solve() {
	cin >> n;
	init();
	int limit = n * (n + 1) / 2 - 1;
	string s, en;
	for (int i = 0; i <= limit; ++i) {
		int x; cin >> x;
		s += (char)('0' + x - 1);
		en += (char)('0' + i);
	}
	queue<pair<string, int> > q;
	q.push({s, 0});
	clean(s);
	set<string> se;
	se.insert(s);
	while (q.size()) {
		pair<string, int> t = q.front(); q.pop();
		string top = t.first;
		clean(top);
		if (top == en) {
			cout << t.second << endl;
			return;
		}
		for (vector<int> x : type) {
			if (limit < *max_element(x.begin(), x.end())) break;
			string tmp = rotate(top, x[0], x[1], x[2]);
			clean(tmp);
			if (se.find(tmp) == se.end()) {
				q.push({tmp, t.second + 1});
				se.insert(tmp);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();

	return 0;
}