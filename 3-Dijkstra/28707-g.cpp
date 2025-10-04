#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int M;
    cin >> M;
    vector<tuple<int,int,int>> ops;
    for (int i = 0; i < M; i++){
        int l, r, c;
        cin >> l >> r >> c;
        l--; r--;
        ops.emplace_back(l, r, c);
    }

    // 초기 상태를 문자열로 표현 (“0~9” 문자들)
    string start = "";
    for (int i = 0; i < N; i++){
        // A[i]는 1~10 이므로 1을 빼서 0~9 범위 표현
        start.push_back(char('0' + (A[i] - 1)));
    }

    // 목표 상태
    vector<int> B = A;
    sort(B.begin(), B.end());
    string goal = "";
    for (int i = 0; i < N; i++){
        goal.push_back(char('0' + (B[i] - 1)));
    }

    // 다익스트라: 상태 문자열 → 최소 비용
    unordered_map<string, long long> dist;
    const long long INF = LLONG_MAX / 4;
    dist[start] = 0;

    // (비용, 상태) 쌍을 담는 최소 힙
    priority_queue<pair<long long, string>,
                   vector<pair<long long, string>>,
                   greater<pair<long long, string>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, s] = pq.top();
        pq.pop();

        // 이미 더 작은 비용이 기록되어 있으면 무시
        if (cost > dist[s]) continue;

        // 만약 이 상태가 목표라면 더 이상 확장 필요없어 (최소 비용 보장)
        if (s == goal) break;

        // 가능한 모든 스왑 조작 적용
        for (auto &tup : ops) {
            int l, r, c;
            tie(l, r, c) = tup;
            string t = s;
            swap(t[l], t[r]);
            long long nc = cost + c;
            if (!dist.count(t) || nc < dist[t]) {
                dist[t] = nc;
                pq.push({nc, t});
            }
        }
    }

    if (!dist.count(goal)) {
        cout << -1;
    } else {
        cout << dist[goal];
    }
    cout << "\n";

    return 0;
}
