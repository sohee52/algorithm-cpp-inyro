#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1004;
int n, r, g, b;
ll dp[MAX][3];
struct rgb {
    int r, g, b;
};
vector<rgb> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;
        v.push_back({r, g, b});
    }
    dp[0][0] = v[0].r;
    dp[0][1] = v[0].g;
    dp[0][2] = v[0].b;

    for (int i = 1; i < n; i++) {
        dp[i][0] = v[i].r + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = v[i].g + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = v[i].b + min(dp[i-1][0], dp[i-1][1]);
    }

    ll mn = 1e9;
    mn = min(mn, dp[n-1][0]);
    mn = min(mn, dp[n-1][1]);
    mn = min(mn, dp[n-1][2]);
    cout << mn << "\n";
}
