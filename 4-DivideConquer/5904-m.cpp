#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 55;
const ll INF = 1e12;
int n, len[MAX], mx;
char go(ll cur, ll sz) {
    if (!sz) return (cur == 1 ? 'm' : 'o');

    if (cur <= len[sz-1]) return go(cur, sz-1);
    else if (cur > len[sz-1] + sz + 3) {
        return go(cur-len[sz-1]-sz-3, sz-1);
    }
    return (cur == len[sz-1] + 1 ? 'm' : 'o');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; len[0] = 3;
    for (int i = 1; i < MAX; i++) {
        len[i] = 2*len[i-1] + i + 3; mx = i;
        if (len[i] > n) break;
    }
    cout << go(n, mx);
}
