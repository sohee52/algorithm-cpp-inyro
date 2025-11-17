#include <bits/stdc++.h>
using namespace std;
int n, a[304], dp[304][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1][0] = a[1];
    dp[2][0] = a[2];
    dp[2][1] = a[1] + a[2];

    for (int i = 3; i <= n; i++) {
        dp[i][1] = dp[i-1][0] + a[i];
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + a[i];
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
}