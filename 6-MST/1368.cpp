#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> edge;
int n, w, total, visited[1004];
priority_queue<edge, vector<edge>, greater<>> pq;
vector<pair<int, int>> adj[1004];
int prim(int s) {
    visited[s] = 1;
    for (auto &it : adj[s]) {
        pq.push({it.second, it.first, s}); // weight, to, from
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
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w;
        adj[0].push_back({i, w});
        adj[i].push_back({0, w});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w;
            if (i < j) {
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
    }
	cout << prim(0) << "\n";
}
