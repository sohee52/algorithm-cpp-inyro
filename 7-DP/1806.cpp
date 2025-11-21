#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = 0;
    long long sum = 0;
    int ans = 1e9;

    while (true) {
        if (sum >= s) {
            ans = min(ans, right - left);
            sum -= a[left++];
        } else {
            if (right == n) break;
            sum += a[right++];
        }
    }

    if (ans == 1e9) cout << 0;
    else cout << ans;
}
