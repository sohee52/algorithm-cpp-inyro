#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> edge;
int v, e, k, temp, t, f, w, total, visited[1004];
priority_queue<edge, vector<edge>, greater<>> pq;
vector<pair<int, int>> adj[1004];
int prim(int s) {
    visited[s] = 1;
    for (auto &it : adj[s]) {
        pq.push({it.second, it.first, s});
    }

    while (pq.size()) {
        auto [w, to, from] = pq.top();
        pq.pop();
        
        if (visited[to]) continue;
        visited[to] = 1;
        total += w;

        for (auto &it : adj[to]) {
            if (visited[it.first]) continue;
            pq.push({it.second, it.first, to});
        }
    }
    return total;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e >> k;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		pq.push({0, temp, 0});
	}
	for (int i = 0; i < e; i++) {
		cin >> t >> f >> w;
		adj[t].push_back({f, w});
		adj[f].push_back({t, w});
	}
	cout << prim(0) << "\n";
}
