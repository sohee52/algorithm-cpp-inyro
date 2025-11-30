#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 10004;
const ll INF = 1e12;
ll n, m, a[MAX], dp[MAX];

ll go(int m) {
    if (m < 0) return INF;
    ll& ret = dp[m];
    if (ret != -1) return ret;
    ret = 1e12;
    if (!m) return ret = 0;
    for (int i = 1; i <= n; i++) ret = min(ret, go(m - a[i]) + 1);
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    fill(dp, dp + MAX, -1);

    cout << (go(m) == INF ? - 1 : go(m));

}
