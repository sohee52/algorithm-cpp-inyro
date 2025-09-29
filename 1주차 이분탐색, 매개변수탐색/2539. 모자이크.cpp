#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll n, m, l, black;
pair <ll, ll> a[MAX];

bool decision(ll cur){
    // cnt -> 사용한 정사각형의 개수
    // last -> 마지막으로 정사각형을 배치한 x 좌표
    ll cnt = 0, last = -1e12;
    for(int i = 1;i <= black;i++){
        // y좌표가 정사각형보다 크면
        // 검은 칸을 가릴 수 없음
        if(a[i].second > cur) return 0;

        // 현재 x좌표가 이미 배치한 정사각형
        // 안에 들어오면 이미 막힌 검은 칸
        if(a[i].first - last + 1 <= cur) continue;
        last = a[i].first; cnt++;
    }

    // 정사각형을 L개 이하로 사용 했으면
    // 검은 칸을 다 막을 수 있음
    return cnt <= l;
}

ll minimization(){
    // 범위의 최댓값은 1e6
    ll lo = 1, hi = 2e6;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(decision(mid)) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m >> l >> black;
    for(int i = 1;i <= black;i++) cin >> a[i].second >> a[i].first;
    sort(a + 1, a + black + 1); 

    cout << minimization();

    return 0;
}
