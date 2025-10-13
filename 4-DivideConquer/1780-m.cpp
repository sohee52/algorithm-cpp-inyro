#include <bits/stdc++.h>
using namespace std;
const int MAX = 2500;
int n, a[MAX][MAX], cnt[3];
void go(int y, int x, int sz) {
    int num = a[y][x]; bool flag = 1;
    for (int i = y; i < y + sz; i++) {
        for (int j = x; j < x + sz; j++) {
            if (num != a[i][j]) flag = 0;
        }
    }

    if (flag) {
        cnt[num+1]++; return;
    }

    int nsz = sz/3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            go(y+i*nsz, x+j*nsz, nsz);
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    go(0, 0, n);
    for (int i = 0;i < 3; i++) cout << cnt[i] << "\n";
}
