#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1000004;
int t, n;
ll dp[MAX];
ll solve(ll num) {
    if (num < 0) return 0;
    ll& ret = dp[num];
    if (ret != -1) return ret;
    ret = 0;
    ret += solve(num - 1) + solve(num - 2) + solve(num - 3);
    return ret %= 1000000009;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t; fill(dp, dp+MAX, -1); 
    dp[0] = 1;
    while (t--) {
        cin >> n;
        cout << solve(n) << "\n";
    }
}
