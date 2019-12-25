#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int dp[N][2];
int a[N];
int to0[N], to1[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			a[j] += (c == '#');
		}
	}
	for (int i = 0; i < m; i++) {
		to0[i] = a[i];
		to1[i] = n - a[i];
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 0; i < m; i++) {
		for (int type = 0; type < 2; type++) {
			if (dp[i][type] != -1) {
				int need = 0;
				for (int j = i; j < m; j++) {
					need += (type == 0) ? to0[j] : to1[j];
					dp[j + 1][1 - type] = min(dp[j + 1][1 - type], dp[i][type] + need);
				}
			}
		}
	}
	cout << min(dp[m][0], dp[m][1]) << '\n';
	return 0;
}
