#include <bits/stdc++.h>
using namespace std;

const int MAX = 40000, INF = 1e9;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, t, a[104][104], dist[MAX];
vector<pair<int, int>> adj[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int num (int y, int x, int cnt) {
	return cnt*10000 + y*100 + x;
}

void dijkstra(int start) {
	fill(dist, dist+MAX, INF);
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
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				adj[num(y, x, 0)].push_back({num(ny, nx, 1), t});
				adj[num(y, x, 1)].push_back({num(ny, nx, 2), t});
				adj[num(y, x, 2)].push_back({num(ny, nx, 0), t + a[ny][nx]});
			}
		}
	}

	dijkstra(num(0, 0, 0));

	int ret = INF;
	for (int i = 0; i < 3; i++) {
		ret = min(ret, dist[(num(n-1, n-1, i))]);
	}
	cout << ret << "\n";
}