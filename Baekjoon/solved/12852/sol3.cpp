#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;

int dp[N + 1], p[N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		p[i] = i - 1;
		if ((i & 1) == 0 && dp[i >> 1] + 1 < dp[i]) {
			dp[i] = dp[i >> 1] + 1;
			p[i] = i >> 1;
		}
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;
			p[i] = i / 3;
		}
	}
	cout << dp[n] << '\n';
	while (n != 1) {
		cout << n << ' ';
		n = p[n];
	}
	cout << 1 << '\n';
	return 0;
}
