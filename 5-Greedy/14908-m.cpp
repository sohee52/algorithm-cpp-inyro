#include <bits/stdc++.h>
using namespace std;
typedef pair<float, int> pfi;
int n, t[1004], s[1004];
vector<pfi> v;
bool cmp (pfi a, pfi b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> s[i];
        v.push_back({(float) s[i] / t[i], i});
    }
    sort(v.begin(), v.end(), cmp);

    for (auto it : v) {
        cout << it.second << " ";
    }
}