#include <bits/stdc++.h>
using namespace std;
#define end aaa
typedef long long ll;
typedef pair<ll, ll> pll;
const int INF = 1e9;
vector<pll> adj[1004];
int n, m, s, e, c, start, end, dist[1004];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijkstra(int start) {
	fill(dist, dist+1004, INF);
	dist[start] = 0;
	pq.push({0, start});

	while(pq.size()) {
		auto [hd, here] = pq.top(); pq.pop();
		if (dist[here] != hd) continue;
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

	cin >> n >> m;
	for (int i = 0;i < m; i++) {
		cin >> s >> e >> c;
		adj[s].push_back({e, c});
	}
	cin >> start >> end;

	dijkstra(start);

	cout << dist[end] << "\n";
}
