#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll MAX = 1e6 + 4, INF = 1e12;
ll n, a[MAX], b[MAX], dist[MAX];
vector<pll> adj[MAX];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijkstra(ll start) {
	fill(dist, dist + MAX, INF);

	dist[start] = 0;
	pq.push({0, start});

	while(pq.size()) {
		auto[hd, here] = pq.top(); pq.pop();
		if (dist[here] != hd) continue;
		for (auto &[there, td] : adj[here]) {
			ll nd = hd + td;
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

	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	for (ll i = 1; i <= n; i++) cin >> b[i];

	for (ll i = 1; i <= n; i++) {
		ll nx = i - a[i];
		if (nx <= 0) adj[0].push_back({i, b[i]});
		else adj[nx].push_back({i, b[i]});

		nx = i + a[i];
		if (nx > n) adj[0].push_back({i, b[i]});
		else adj[nx].push_back({i, b[i]});
	}
	
	dijkstra(0);

	for (int i = 1; i <= n; i++) cout << dist[i] << " ";
	
}