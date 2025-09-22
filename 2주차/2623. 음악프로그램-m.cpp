#include <bits/stdc++.h>
using namespace std;
#define prev aaa
const int MAX = 1004;
int n, m, k, temp, prev, ind[MAX];
vector<int> adj[MAX], ret;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		cin >> prev;
		for (int j = 1; j < k; j++) {
			cin >> temp;
			adj[prev].push_back(temp);
			ind[temp]++;
			prev = temp;
		}
	}
	for (int j = 1; j <= n; j++) {
		if (!ind[j]) q.push(j);
	}
	while(q.size()) {
		int x = q.front(); q.pop();
		ret.push_back(x);
		for (int nx : adj[x]) {
			if (!--ind[nx]) q.push(nx);
		}
	}
	if (ret.size() != n) cout << 0 << "\n";
	else {
		for (int x : ret) cout << x << "\n";
	}
}
