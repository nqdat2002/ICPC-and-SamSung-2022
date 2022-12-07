#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(int N, int l, int r, int val, int bit[][505]){
	for (int i = l; i <= N; i += i & -i)
		for (int j = r; j <= N; j += j & -j)
			bit[i][j] += val;
}
ll query(int N, int l, int r, int bit[][505]){
	ll ret = 0;
	for (int i = l; i > 0; i -= i & -i)
		for (int j = r; j > 0; j -= j & -j)
			ret += bit[i][j];
	return ret;
}
ll countInversionPairs(int N, int mat[][505]){
	int bit[505][505] = {0};
	vector<pair<int, pair<int, int> > > v;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			v.push_back(make_pair(-mat[i][j], make_pair(i+1, j+1)));
	sort(v.begin(), v.end());
	ll inv_pair_cnt = 0;
	int i = 0;
	while (i < v.size()){
		int curr = i;
		vector<pair<int, int> > pairs;
		while (curr < v.size() && (v[curr].first == v[i].first)){
			pairs.push_back(make_pair(v[curr].second.first,
									v[curr].second.second));
			inv_pair_cnt += query(N, v[curr].second.first,
								v[curr].second.second, bit);
			curr++;
		}

		vector<pair<int, int> >::iterator it;
		for (it = pairs.begin(); it != pairs.end(); ++it){
			int x = it->first;
			int y = it->second;
			update(N, x, y, 1, bit);
		}
		i = curr;
	}
	return inv_pair_cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int N; cin >> N;
		int a[505][505];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) cin >> a[i][j];
		cout << countInversionPairs(N, a) << endl;
	}
	return 0;
}
