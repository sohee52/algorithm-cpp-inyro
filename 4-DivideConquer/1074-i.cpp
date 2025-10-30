#include <bits/stdc++.h>
using namespace std;
int n, r, c, ans = 0;;
void dnc(int x, int y, int size) {
	if (c == x && r == y) {
        cout << ans;
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y) {
        dnc(x, y, size / 2);
        dnc(x + size / 2, y, size / 2);
        dnc(x, y + size / 2, size / 2);
        dnc(x + size / 2, y + size / 2, size / 2);
    } else {
        ans += size * size;
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> r >> c;
	dnc(0, 0, pow(2, n));
	return 0;
}