#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, s, e, c, st, ed, dist[1004];
vector<pair<int, int>> adj[1004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start) {
    fill(dist, dist + 1004, INF);

    dist[start] = 0;
    pq.push({0, start});

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

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> c;
        adj[s].push_back({c, e});
    }
    cin >> st >> ed;

    dijkstra(st);
    cout << dist[ed] << "\n";
}

