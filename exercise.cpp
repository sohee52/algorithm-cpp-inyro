#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n, m, k, w, a, b, p[MAX+4][MAX+4];
bool check(int x) {
	
}
int bi() {
	int lo = 1, hi = MAX;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (check(mid)) 
		else 
	}
	return lo;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k >> w;
	for (int i = 0; i < w; i++) {
		cin >> a >> b;
		a--; b--;
		p[a][b] = 1;
	}
	if (w == 0) {
		cout << 0 << "\n";
		return 0;
	}
	cout << bi() << "\n";
}
