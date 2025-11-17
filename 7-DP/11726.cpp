#include <bits/stdc++.h>
using namespace std;
int n, dp[1004];
int solve(int num) {
    int& ret = dp[num];
    if (ret != -1) return ret;
    ret = 0;
    ret += solve(num-1) + solve(num-2);
    return ret %= 10007;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    fill(dp, dp+1004, -1);
    dp[1] = 1; dp[2] = 2;
    cout << solve(n) << "\n";
}
