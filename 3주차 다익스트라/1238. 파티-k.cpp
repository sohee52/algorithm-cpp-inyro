#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, x, s, e, t, ret;
int dist[1004], dist2[1004];
vector<pair<int, int>> adj[1004], adj2[1004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int *dist, vector<pair<int, int>> * adj) {
    
    pq.push({0, x});
    dist[x] = 0;

    while (pq.size()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        if (dist[here] != here_dist) continue;

        for (auto there : adj[here]) {
            int _dist = there.first;
            int _there = there.second;

            if (dist[_there] > dist[here] + _dist) {
                dist[_there] = dist[here] + _dist;
                pq.push({dist[_there], _there});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    
    fill(dist, dist + 1004, INF);
    fill(dist2, dist2 + 1004, INF);
    
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        adj[s].push_back({t, e});
        adj2[e].push_back({t, s});
    }

    dijkstra(dist, adj);
    dijkstra(dist2, adj2);
    
    for (int i = 1; i <= n; i++) {
    	if (i == x) continue;
    	ret = max(ret, dist[i] + dist2[i]);
	}
	cout << ret << "\n";
}

