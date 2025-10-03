#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int t, n, d, c, a, b, s, dist[10004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[10004];

void dijkstra(int start) {
	fill(dist, dist + 10004, INF);
	while (!pq.empty()) pq.pop();

	dist[start] = 0;
	pq.push({0, start});

	while (pq.size()) {
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
	cin >> t;
	while(t--) {
		cin >> n >> d >> c;

		int cnt = 0, last = 0;
		for (int j = 1; j <= n; j++) {
			adj[j].clear();
		}

		while(d--) {
			cin >> a >> b >> s;
			adj[b].push_back({a, s});
		}

		dijkstra(c);

		for (int j = 1; j <= n; j++) {
			if (dist[j] == INF) continue;
			last = max(last, dist[j]);
			cnt++;
		}
		cout << cnt << " " << last << "\n";
	}
}
