#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    if (n%7 == 1 || n%7 == 3) cout << "CY\n";
    else cout << "SK\n";
}
