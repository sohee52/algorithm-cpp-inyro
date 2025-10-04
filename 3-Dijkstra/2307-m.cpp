#include <bits/stdc++.h>
using namespace std;
const int MAX = 5004, INF = 1e9;
typedef pair<int, int> pii;
int n, m, a, b, t, dist[MAX], e[MAX], ret[MAX], parent[MAX];
vector<pii> adj[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int dijkstra(int s, int e, bool saveParent = false) {
    while(!pq.empty()) pq.pop();
    fill(dist, dist+MAX, INF);
    if (saveParent) fill(parent, parent+MAX, -1);

    dist[1] = 0;
    pq.push({0, 1});

    while(pq.size()) {
        auto [hd, here] = pq.top(); pq.pop();
        if (dist[here] != hd) continue;
        for (auto [there, td] : adj[here]) {
            if ((here == s && there == e) || (here == e && there == s)) continue; // 간선 차단
            int nd = hd + td;
            if (dist[there] > nd) {
                dist[there] = nd;
                if (saveParent) parent[there] = here; // 부모 저장
                pq.push({nd, there});
            }
        }
    }
    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

    // 최초 최단경로 구하면서 parent 기록
    int base = dijkstra(-1, -1, true);
    if (base == INF) {
        cout << -1 << "\n";
        return 0;
    }

    // parent 이용해서 최단경로 간선 추적
    int ret = 0;
    int v = n;
    while (v != 1) {
        int u = parent[v];
        if (u == -1) break; // 방어적 처리
        int temp = dijkstra(u, v);
        if (temp == INF) {
            cout << -1 << "\n";
            return 0;
        }
        ret = max(ret, temp - base);
        v = u;
    }

    cout << ret << "\n";
}
