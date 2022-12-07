#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5 + 5;
typedef long long ll;
vector<pair<ll, ll> > g[MAXN];
ll dist[MAXN], route[MAXN], n, m;
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;

void Dijkstra() {
	for (ll i = 2; i <= n; ++i) {
		dist[i] = INF;
	}
	while(pq.size()) pq.pop();
	pq.push({0, 1});

	dist[1] = 0;
	route[1] = 1;

	while (!pq.empty()) {
		ll d = pq.top().first;
		ll u = pq.top().second;
		pq.pop();
		if (d > dist[u])
			continue;
		for (auto e : g[u]) {
			ll c = e.first;
			ll v = e.second;
			if ((ll)(c + d) > dist[v])
				continue;
			if ((ll)(c + d) == dist[v]) {
				route[v] += route[u];
			}
			if ((ll)(c + d) < dist[v]) {
				dist[v] = c + d;
				route[v] = route[u];
				pq.push({dist[v], v});
			}
		}
	}
	cout << dist[n] << " " << route[n] << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < MAXN; ++i) g[i].clear();
		memset(route, (ll)0, sizeof(route));
		for (ll i = 0; i < m; ++i) {
			ll u, v, c; cin >> u >> v >> c;
			g[u].push_back({c, v});
			g[v].push_back({c, u});
		}
		Dijkstra();
	}
	return 0;
}