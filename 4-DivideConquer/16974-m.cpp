#include <bits/stdc++.h>
using namespace std;
int n, x;
String go(int level, vector<String> ret) {
    if (level == 1) return "P";
    int s = 0; int e = ret.size();
    
    while (s < e) {
        int mid = (s+e)/2;
        ret = "B" + ret;
        go()
        ret.insert(mid, "P");
    
        ret += "B"
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cie.tie(NULL); cout.tie(NULL);
    cin >> n >> x;
    vector<int> ret;
    go(n, ret);
}