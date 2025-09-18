#include <bits/stdc++.h>
using namespace std;
int n, m, l, a[1004];
bool check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n+1; i++) {
		int diff = a[i] - a[i-1];
		cnt += diff / x;
		if (diff % x == 0) cnt--;
	}
	return cnt <= m;
}
int bi() {
	int lo = 1, hi = l;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0, a[n+1] = l;
	sort(a, a+n+2);
	cout << bi() << "\n";
}
