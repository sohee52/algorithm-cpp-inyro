#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int m, n, s, u, v, w, k, x, cnt;
long long total;
vector<pii> adj[2001];
bool mustVisit[2001];
bool visited[2001];
priority_queue<pii, vector<pii>, greater<>> pq;

long long prim(int start, int k) {
    if (mustVisit[start]) cnt++;
    visited[start] = true;

    for (auto &nx : adj[start]) pq.push({nx.second, nx.first});

    while (!pq.empty() && cnt < k) {
        auto [w, to] = pq.top();
        pq.pop();

        if (visited[to]) continue;
        visited[to] = true;
        total += w;

        if (mustVisit[to]) cnt++;

        for (auto &nx : adj[to]) {
            if (!visited[nx.first]) {
                pq.push({nx.second, nx.first});
            }
        }
    }

    if (cnt == k) return total;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= m; i++) {
        cin >> x;
        mustVisit[x] = true;
        k++;
    }

    cout << prim(s, k) << "\n";
    return 0;
}
