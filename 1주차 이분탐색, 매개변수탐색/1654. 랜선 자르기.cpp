#include <bits/stdc++.h>
using namespace std;
int k, n, a[10004];
bool decision(long long cur) {
	long long cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += a[i] / cur;
	}
	return cnt >= n;
}
int maximazation() {
	long long lo = 0, hi = (1<<31)-1;
	while (lo < hi) {
		long long mid = (hi+lo+1)/2;
		if (decision(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	cout << maximazation() << "\n";
}
