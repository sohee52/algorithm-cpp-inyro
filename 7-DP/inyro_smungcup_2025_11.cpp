#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
struct info {
    int s, e, c;
};
bool cmp (const info &x, const info &y) {
    return x.e < y.e;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;

        vector<info> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].s >> a[i].e >> a[i].c;
        }
        sort(a.begin(), a.end(), cmp);

        vector<int> finish(n);
        for (int i = 0; i < n; i++)
            finish[i] = a[i].e;

        vector<ll> dp(n);
        for (int i = 0; i < n; i++) {
            ll take = a[i].c;

            int idx = upper_bound(finish.begin(), finish.end(), a[i].s) 
                      - finish.begin() - 1;

            if (idx >= 0) take += dp[idx];

            dp[i] = (i == 0 ? take : max(dp[i-1], take));
        }

        cout << dp[n-1] << "\n";
    }

    return 0;
}
