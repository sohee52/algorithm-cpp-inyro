#include <bits/stdc++.h>
using namespace std;
const int MAX = 320004;
int n, m, a, b, ind[MAX];
vector<int> adj[MAX];
queue<int> q;
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
		if(!ind[i]) q.push(i); // 진입 차수가 0인 노드 찾기
	}
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int nxt : adj[cur]) {
			if (!--ind[nxt]) q.push(nxt);
			// 한 노드의 진입 차수 값 = 아직 처리(출력)되지 않은, 앞서야 할 학생 수입니다.
			// x의 진입 차수가 0이라는 것은, 앞에 서야 할 모든 학생들이 이미 처리(출력)되었음을 뜻합니다.
			// 다시 말해, x보다 앞에 서야 하는 조건이 더 이상 남아있지 않으므로 이제 줄에 세워도 제약을 어기지 않습니다.
		}
	}
}
