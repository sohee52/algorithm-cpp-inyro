#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e12;
ll n, m, d[MAX];
vector <pair<ll, ll>> adj[MAX];

using pll = pair<ll, ll>;
priority_queue <pll, vector<pll>, greater<pll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }
    ll s, e; cin >> s >> e;

    // 거리 배열 큰 값으로 초기화
    for(int i = 0;i < MAX;i++) d[i] = INF;
    // 시작 정점을 방문 가능한 정점으로 처리
    pq.push({0, s});

    while(!pq.empty()){
        // 방문 가능한 정점 중 최단 거리인 정점 방문
        auto[cd, cur] = pq.top(); pq.pop();
        // 이미 최단거리이면 건너 뜀
        if(d[cur] <= cd) continue;
        // 거리 갱신
        d[cur] = cd;

        for(auto& [nxt, co] : adj[cur]){
            // 다음 정점이 이미 최단거리이면 건너 뜀
            if(d[nxt] <= cd + co) continue;
            // 방문 가능한 정점에 포함
            pq.push({cd + co, nxt});
        }
    }

    cout << d[e];

    return 0;
}

