#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 200000;
ll n, c, a[MAX+4];
void go(int cnt) {
	if (cnt == c) ret = max(ret, 
	for (int i = 0; i < n; i++) {
		visited[i] = 1;
		go(cnt++);
		visited[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	cout << go();
}
 
