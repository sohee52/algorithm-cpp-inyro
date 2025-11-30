#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 10101;
ll t, dp[MAX][4], n;

ll solve(ll cur, ll mx){
    if(cur < 0) return 0;
    ll& ret = dp[cur][mx];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = (mx == 1);
    
    for(int i = 1; i <= mx; i++) ret += solve(cur - mx, i);
    return ret;
}

void run(){
    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(int i = 1; i <= 3; i++) ans += solve(n, i);
        cout << ans << "\n";
    }

    return 0;
}
