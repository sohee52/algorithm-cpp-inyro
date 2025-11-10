#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> edge;
bool visited[10004];
vector<pair<ll, ll>> adj[10004];
priority_queue<edge, vector<edge>, greater<>> pq;
ll v, e, a, b, c, total;

ll prim(int s) {
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
	cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cout << prim(1) << "\n";
}