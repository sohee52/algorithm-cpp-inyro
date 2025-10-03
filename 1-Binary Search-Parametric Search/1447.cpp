#include <iostream>
#include <algorithm>
using namespace std;

int a[1010], n, m, l;

bool decision(int cur){
    // 휴게소 사이의 거리의 최댓값을 cur로 만들기 위해
    // 필요한 추가 휴게소의 개수
    int cnt = 0;
    for(int i = 1;i <= n + 1;i++){
        int diff = a[i] - a[i - 1]; // 휴게소의 거리
        cnt += diff / cur; // (차이 / 최댓값) 만큼 추가로 휴게소를 설치
        if(diff % cur == 0) cnt--; // 차이가 최댓값의 배수면 1을 빼줌
    }

    // 설치해야 하는 휴게소의 개수가 M 이하면 1
    // 아니면 0
    return cnt <= m;
}

int minimization(){
    // 정답의 범위는 1 ~ l
    int lo = 1, hi = l;
    while(lo < hi){
        int mid = (lo + hi) / 2; // 중간값
        // 결정 문제의 답이 1 이면 
        // 정답은 [lo, mid]에 존재
        if(decision(mid)) hi = mid;
        
        // 결정 문제의 답이 0 이면
        // 정답은 [mid + 1, hi]에 존재
        else lo = mid + 1;
    }

    return lo;
}

int main(){
    cin >> n >> m >> l;
    for(int i = 1;i <= n;i++) cin >> a[i];
    a[0] = 0; a[n + 1] = l; // 시작점 0, 끝점 l
    sort(a, a + n + 2); // 정렬

    cout << minimization();
    return 0;
}
