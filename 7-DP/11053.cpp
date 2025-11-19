#include <bits/stdc++.h>
using namespace std;
int n, a[1004], dp[1004], ans;
int solve(int n) {
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(dp[i], ans);
    }
    return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << solve(n) << "\n";
}
