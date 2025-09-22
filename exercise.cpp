#include <bits/stdc++.h>
using namespace std;
const int MAX = 32004;
int n, m, a, b, ind[MAX];
vector<int> adj[MAX];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		ind[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if(!ind[i]) pq.push(i);
	}
	while(pq.size()) {
		int x = pq.top(); pq.pop();
		cout << x << " ";
		for (int nx : adj[x]) {
			if(!--ind[nx]) pq.push(nx);
		}
	}
}
