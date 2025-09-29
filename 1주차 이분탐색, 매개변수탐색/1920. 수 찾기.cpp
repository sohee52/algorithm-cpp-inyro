#include <bits/stdc++.h>
using namespace std;
int n, m, a[100004], x;
int bi(int x, int size) {
	int lo = 0, hi = size - 1;
	int ret = -1;
	while (lo <= hi) {
		int mid = (hi + lo) / 2;
		if (a[mid] == x) {
			ret = mid; break;
		}
		if (a[mid] > x) hi = mid - 1;
		else lo = mid + 1;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		int ret = bi(x, n);
		if (ret == -1) cout << 0 << "\n";
		else cout << 1 << "\n";
	}
	return 0;
}
