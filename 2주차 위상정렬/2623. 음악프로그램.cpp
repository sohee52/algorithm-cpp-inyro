#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e12;
ll n, m, ind[MAX], a[MAX];
vector <ll> adj[MAX], result;
queue <ll> q;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    while(m--){
        ll sz; cin >> sz;
        for(int i = 1;i <= sz;i++) cin >> a[i];
        for(int i = 1;i < sz;i++){
            // a[i] -> a[i + 1] 인 간선
            adj[a[i]].push_back(a[i + 1]);
            ind[a[i + 1]]++;
        }
    }

    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.push(i);
    }

    // 위상정렬
    while(!q.empty()){
        ll cur = q.front(); q.pop();
        result.push_back(cur);
        for(auto& nxt : adj[cur]){
            if(!--ind[nxt]) q.push(nxt);
        }
    }

    bool flag = 1;
    for(int i = 1;i <= n;i++){
        // indegree가 0이 아닌 값이 있으면
        // 사이클이 존재 -> 위상 정렬 불가
        if(ind[i]) flag = 0;
    }

    if(flag) for(auto& i : result) cout << i << "\n";
    else cout << 0;

    return 0;
}
