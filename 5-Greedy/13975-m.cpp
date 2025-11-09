#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, temp, a, b, cost;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n; cost = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int j = 0; j < n; j++) {
            cin >> temp;
            pq.push(temp);
        }
        while(pq.size() > 1) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            cost += (a+b);
            pq.push(a+b);
        }
        cout << cost << "\n";
    }
}
