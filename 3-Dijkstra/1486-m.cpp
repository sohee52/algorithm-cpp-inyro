#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
const int INF = 1e9, MAX = 10000;
int n, m, t, d, a[30][30], dist[MAX], dist2[MAX];
char temp;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> adj[MAX], adj2[MAX];
int num (int y, int x) {
    return y*100 + x;
}
void dijkstra(int *dist, vector<pii> *adj) {
    while(pq.size()) pq.pop();
    fill(dist, dist+MAX, INF);
    dist[0] = 0;
    pq.push({0, 0});

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
	cin >> n >> m >> t >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp >= 'A' && temp <= 'Z') a[i][j] = temp-'A';
            else if (temp >= 'a' && temp <= 'z') a[i][j] = temp-'a'+26;
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                int diff = a[ny][nx] - a[y][x];
                if (abs(diff) > t) continue;
                int cost=(diff>0 ? diff*diff : 1);
                adj[num(y,x)].push_back({num(ny,nx),cost});
                adj2[num(ny,nx)].push_back({num(y,x),cost});
            }
        }
    }
    dijkstra(dist, adj);
    dijkstra(dist2, adj2);
    int ret = a[0][0];
    for (int i = 0; i < MAX; i++) {
        if (dist[i] == INF || dist2[i] == INF) continue;
        if (dist[i]+dist2[i] > d) continue;
        ret = max(ret, a[i/100][i%100]);
    }
    cout << ret << "\n";
}
