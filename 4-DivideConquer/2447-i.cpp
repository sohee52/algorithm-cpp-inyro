#include <bits/stdc++.h>
using namespace std;
int n;
void dnc(int x, int y, int size) {
	if((x / size) % 3 == 1 && (y / size) % 3 == 1) {
        cout << " ";
    } else {
        if(size / 3 == 0)
            cout << "*";
        else
            dnc(x, y, size / 3);
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dnc(i, j, n);
        }
        cout << "\n";
    }
	return 0;
}