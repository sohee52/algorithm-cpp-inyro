#include <bits/stdc++.h>
using namespace std;
int n, k, a[12], b[12], num;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 0; i--) {
        if (k >= a[i]) {
            num += (k / a[i]);
            k = (k % a[i]);
        }
        if (k == 0) break;
    }
    cout << num << "\n";
}
