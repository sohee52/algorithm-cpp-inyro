#include <bits/stdc++.h>
using namespace std;
int n, result, arr[100001], d[100001], s[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	arr[0] = 0;
	s[0] = 0;
	result = -1000000000;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

    // 현재까지 누적합
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + arr[i];
	}

    // 이전까지의 최소 누적합
	d[0] = 1000;
	for (int i = 1; i <= n; i++) {
		d[i] = min(s[i - 1], d[i - 1]);
	}

    // 최대 부분합 = (현재까지 누적합) - (이전까지의 최소 누적합)
	for (int i = 1; i <= n; i++) {
		result = max(result, s[i] - d[i]);
	}

	cout << result;

	return 0;
}