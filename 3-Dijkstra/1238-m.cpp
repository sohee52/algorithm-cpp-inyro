#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int INF = 1e9;
int n, m, x, s, e, t, dist[10004], dist2[10004];
vector<pll> adj[10004], adj2[10004];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijkstra(int *dist, vector<pll> *adj) {
	fill(dist, dist+10004, INF);
	dist[x] = 0;
	pq.push({0, x});

	while(pq.size()) {
		auto [hd, here] = pq.top(); pq.pop();
		for (auto &[there, td] : adj[here]) {
			int nd = hd + td;
			if (dist[there] > nd) {
				dist[there] = nd;
				pq.push({nd, there});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;
		adj[s].push_back({e, t});
		adj2[e].push_back({s, t});
	}

	dijkstra(dist, adj);
	dijkstra(dist2, adj2);

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		ret = max(ret, dist[i] + dist2[i]);
	}
	cout << ret << "\n";
}
