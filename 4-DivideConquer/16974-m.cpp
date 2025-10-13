#include <bits/stdc++.h>
using namespace std;
int n, x;
string go(int level, string ret) {
    if (level == 1) return "P";

    int s = 0; int e = ret.size();
    
    while (s < e) {
        int mid = (s+e)/2;
        ret = "B" + ret;
        go(n-1, ret);
        ret.insert(mid, "P");
        go(n-1, ret);
        ret += "B";
    }

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cie.tie(NULL); cout.tie(NULL);
    cin >> n >> x;
    go(n, "");
}