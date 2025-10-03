#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
using ll = long long;

const ll MAX = 3 * 10201;
const ll INF = 1e12;
ll n, m, d[MAX];
vector <pair<ll, ll>> adj[MAX];
ll a[101][101];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

using pll = pair<ll, ll>;
priority_queue <pll, vector<pll>, greater<pll>> pq;

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > n;
}

ll num(ll cy, ll cx, ll cnt){
    return cnt * 10101 + cy * 101 + cx;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 0;k < 4;k++){
                ll ny = i + dy[k], nx = j + dx[k];
                if(outrange(ny, nx)) continue;
                adj[num(i, j, 0)].push_back({num(ny, nx, 1), m});
                adj[num(i, j, 1)].push_back({num(ny, nx, 2), m});
                adj[num(i, j, 2)].push_back({num(ny, nx, 0), m + a[ny][nx]});
            }
        }
    }

    for(int i = 0;i < MAX;i++) d[i] = INF;
    pq.push({0, num(1, 1, 0)});

    while(!pq.empty()){
        auto[cd, cur] = pq.top(); pq.pop();
        if(d[cur] <= cd) continue;
        d[cur] = cd;

        for(auto& [nxt, co] : adj[cur]){
            if(d[nxt] <= cd + co) continue;
            pq.push({cd + co, nxt});
        }
    }

    ll result = INF;
    for(int i = 0;i < 3;i++) result = min(result, d[num(n, n, i)]);
    cout << result;

    return 0;
}